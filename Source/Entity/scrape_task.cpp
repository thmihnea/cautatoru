#include "scrape_task.h"
#include <thread>
#include <atomic>

Cautatoru::ScrapeTask::ScrapeTask(std::thread& thread_ptr, std::atomic<bool>& running_ref)
{
    this->m_thread_ptr = std::move(thread_ptr);
    this->m_running_ref = std::move(&running_ref);
}

std::thread* Cautatoru::ScrapeTask::GetThread()
{
    return &this->m_thread_ptr;
}

std::atomic<bool>* Cautatoru::ScrapeTask::GetAtomicRef()
{
    return &this->m_running_ref;
}