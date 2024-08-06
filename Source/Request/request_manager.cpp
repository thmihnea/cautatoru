#include <vector>
#include <memory>
#include <thread>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "nlohmann/json.hpp"
#include "../Store/store.h"
#include "request_manager.h"
#include "../Scraper/scraper.h"
#include "../logging_manager.h"
#include "../Entity/category.h"

Cautatoru::RequestManager::RequestManager()
{
    this->m_store_data = std::vector<std::shared_ptr<Store>>();
    this->m_scrape_tasks = std::unordered_map<std::shared_ptr<Cautatoru::Store>, std::shared_ptr<Cautatoru::ScrapeTask>>();

    this->m_store_data.push_back(
        std::make_shared<EMag>()
    );

    std::ifstream config("config.json");
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

std::unordered_map<std::shared_ptr<Cautatoru::Store>, std::shared_ptr<Cautatoru::ScrapeTask>>& Cautatoru::RequestManager::GetScrapeTasks()
{
    return this->m_scrape_tasks;
}

void Cautatoru::RequestManager::schedule()
{
    
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