#ifndef _CAUTATORU_REQUEST_MANAGER_H
#define _CAUTATORU_REQUEST_MANAGER_H

#include <vector>
#include <memory>
#include <thread>
#include <atomic>
#include <string>
#include <unordered_map>
#include "../Store/store.h"

namespace Cautatoru
{
    class ScrapeTask
    {
    private:
        std::thread m_thread_ptr;
        std::atomic<bool> m_running_ref;
    public:
        ScrapeTask(
            std::thread& thread_ptr,
            std::atomic<bool>& running_ref
        );

        std::thread& GetThread();

        std::atomic<bool>& GetAtomicRef();
    };

    class RequestManager
    {
    private:
        std::vector<std::shared_ptr<Store>> m_store_data;
        std::unordered_map<std::shared_ptr<Store>, std::shared_ptr<ScrapeTask>> m_scrape_tasks;
        std::vector<std::string> m_scrape_categories;
    public:
        RequestManager();

        std::vector<std::shared_ptr<Store>>& GetStoreData();

        std::unordered_map<std::shared_ptr<Store>, std::shared_ptr<ScrapeTask>>& GetScrapeTasks();

        std::vector<std::string> GetScrapeCategories();

        void schedule();
    };
}

#endif