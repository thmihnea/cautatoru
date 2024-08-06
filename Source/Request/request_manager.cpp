#include <vector>
#include <memory>
#include <thread>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <condition_variable>
#include "nlohmann/json.hpp"
#include "../Store/store.h"
#include "request_manager.h"
#include "../Scraper/scraper.h"
#include "../logging_manager.h"
#include "../Entity/category.h"

Cautatoru::RequestManager::RequestManager()
{
    this->m_store_data = std::vector<std::shared_ptr<Store>>();

    this->m_store_data.push_back(
        std::make_shared<EMag>()
    );

    std::ifstream config("../../config.json");
    if (!config.is_open())
    {
        log_error("The config.json file could not be opened. Make sure it exists!");
        return;
    }

    nlohmann::json json;
    config >> json;
    auto categories = json["scraped_categories"];
    
    for (auto& cat : categories)
    {
        auto cat_ptr = std::make_shared<Category>(cat, false);
        for (auto& store_ptr : this->m_store_data)
        {
            store_ptr.get()->AddCategory(cat_ptr);
        }
    }
}

std::vector<std::shared_ptr<Cautatoru::Store>>& Cautatoru::RequestManager::GetStoreData()
{
    return this->m_store_data;
}

void Cautatoru::RequestManager::schedule()
{

    for (auto& store_ptr : this->m_store_data) {
        auto store = store_ptr.get();
        auto atomic_ref = std::atomic<bool>(true);
        
        std::thread execute_scrape([store, &atomic_ref] {
            while (atomic_ref) {
                store->Scrape();
                std::this_thread::sleep_for(std::chrono::seconds(30));
            }
        });

        execute_scrape.detach();

        store->SetScrapeTask(
            execute_scrape,
            atomic_ref
        );
    }

    log_info("All threads have been successfully started.");

    std::condition_variable cv;
    std::mutex cv_m;

    std::unique_lock<std::mutex> lock(cv_m);
    cv.wait(lock, [this]{
        auto stores = this->GetStoreData();
        int stopped_count = 0;
        for (const auto& store : stores)
        {
            if (!store.get()->GetScrapeTask()->GetAtomicRef()->load())
            {
                stopped_count++;
            }
        }
        return !(stopped_count == stores.size());
    });
}