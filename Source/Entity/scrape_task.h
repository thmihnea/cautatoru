#include <memory>
#include <thread>
#include <atomic>
#include <vector>
#include <memory>

namespace Cautatoru
{
    /**
     * @brief Class which holds data regarding
     * the scrape tasks that are owned by each
     * store.
     * 
     * Stores information regarding the thread
     * this process is running on and an atomic
     * reference to know whether or not the 
     * process should continue running.
     */
    class ScrapeTask
    {
    private:
        std::thread m_thread_ptr;
        std::atomic<bool> m_running_ref;
    public:
        /**
         * @brief Construct a new Scrape Task object.
         * 
         * @param thread_ptr A reference towards
         * the thread of this process.
         * @param running_ref The atomic reference
         * which should be used when deciding if the
         * current thread should continue working.
         */
        ScrapeTask(
            std::thread& thread_ptr,
            std::atomic<bool>& running_ref
        );

        /**
         * @brief Get the thread object which
         * maintains the current scrape task.
         * 
         * @return std::thread& The aforementioned
         * thread.
         */
        std::thread* GetThread();
        
        /**
         * @brief Get the atomic boolean reference
         * to aid in deciding if the task should continue
         * running.
         * 
         * @return std::atomic<bool>& The aforementioned
         * atomic reference.
         */
        std::atomic<bool>* GetAtomicRef();
    };
}