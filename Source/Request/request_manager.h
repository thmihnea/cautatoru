#ifndef _CAUTATORU_REQUEST_MANAGER_H
#define _CAUTATORU_REQUEST_MANAGER_H

#include <vector>
#include <memory>
#include "../Store/store.h"

namespace Cautatoru
{
    /**
     * @brief This class is responsible for
     * managing scrape requests.
     * 
     * It holds data regarding the tasks
     * and the initialized stores.
     */
    class RequestManager
    {
    private:
        std::vector<std::shared_ptr<Store>> m_store_data;
    public:
        /**
         * @brief Construct a new RequestManager
         * object.
         * 
         * @note This is only used in the main function.
         * Should not be called twice.
         */
        RequestManager();

        /**
         * @brief Returns the vector object holding
         * the shared pointers of the stores.
         * 
         * @note The stores are wrapped inside of
         * shared pointers because there are multiple
         * contexts owning them.
         * 
         * @return std::vector<std::shared_ptr<Store>>& 
         * The vector of stores.
         */
        std::vector<std::shared_ptr<Store>>& GetStoreData();

        /**
         * @brief Schedule the scraping operations
         * within each store.
         */
        void schedule();
    };
}

#endif