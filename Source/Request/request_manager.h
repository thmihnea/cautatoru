#ifndef _CAUTATORU_REQUEST_MANAGER_H
#define _CAUTATORU_REQUEST_MANAGER_H

#include <vector>
#include <memory>
#include <thread>
#include <atomic>
#include <string>
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
        std::vector<std::unique_ptr<Store>> m_store_data;
        std::vector<std::unique_ptr<Cautatoru::ScrapeTask>> m_scrape_tasks;
        std::vector<std::string> m_scrape_categories;
    public:
        RequestManager();

        std::vector<std::unique_ptr<Store>>& GetStoreData();

        std::vector<std::unique_ptr<Cautatoru::ScrapeTask>>& GetScrapeTasks();

        std::vector<std::string>& GetScrapeCategories();

        void schedule();
    };
}

#endif