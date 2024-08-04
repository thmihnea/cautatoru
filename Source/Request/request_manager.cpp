#include <vector>
#include <memory>
#include <thread>
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "../Store/store.h"
#include "request_manager.h"
#include "../Scraper/scraper.h"
#include "../logging_manager.h"

Cautatoru::RequestManager::RequestManager()
{
    this->m_store_data = std::vector<std::unique_ptr<Store>>();
    this->m_scrape_tasks = std::vector<std::unique_ptr<ScrapeTask>>();
    this->m_scrape_categories = std::vector<std::string>();

    this->m_store_data.push_back(
        std::make_unique<EMag>()
    );

    std::ifstream config("../../config.json");
    nlohmann::json json;

    config >> json;
    auto categories = json["scraped_categories"];

    for (auto &entry : categories)
    {
        this->m_scrape_categories.push_back(entry);
    }
}

std::vector<std::unique_ptr<Cautatoru::Store>>& Cautatoru::RequestManager::GetStoreData()
{
    return this->m_store_data;
}

std::vector<std::unique_ptr<Cautatoru::ScrapeTask>>& Cautatoru::RequestManager::GetScrapeTasks()
{
    return this->m_scrape_tasks;
}

std::vector<std::string>& Cautatoru::RequestManager::GetScrapeCategories()
{
    return this->GetScrapeCategories();
}

void Cautatoru::RequestManager::schedule()
{
    for (auto &store_ptr : this->m_store_data)
    {
        for (auto &entry : this->m_scrape_categories)
        {
            auto store = store_ptr.get();
            auto atomic_ref = std::atomic<bool>(true);
            std::thread execute_scrape([&atomic_ref, store, entry]{
                while (atomic_ref)
                {
                    auto request_url = store->RequestUrl(entry);
                    auto response = Scrape(request_url);

                    log_info("Successfully scraped data for category " + entry + " for store " + store->GetUrl() + ".");

                    std::this_thread::sleep_for(std::chrono::seconds(5));
                }
            
            });

            this->m_scrape_tasks.push_back(
                std::make_unique<ScrapeTask>(
                    execute_scrape,
                    atomic_ref
                )   
            );
        }

        for (auto &task : this->m_scrape_tasks)
        {
            task.get()->GetThread().join();
        }
    }
}

Cautatoru::ScrapeTask::ScrapeTask(std::thread& thread_ptr, std::atomic<bool>& running_ref)
{
    this->m_thread_ptr = std::move(thread_ptr);
    this->m_running_ref = std::move(&running_ref);
}

std::thread& Cautatoru::ScrapeTask::GetThread()
{
    return this->m_thread_ptr;
}

std::atomic<bool>& Cautatoru::ScrapeTask::GetAtomicRef()
{
    return this->m_running_ref;
}