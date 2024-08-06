#ifndef _CAUTATORU_STORE_H
#define _CAUTATORU_STORE_H

#include <string>
#include <queue>
#include <memory>
#include <vector>
#include "../Entity/scraped_product.h"
#include "../Entity/category.h"

namespace Cautatoru
{
    /**
     * @brief Class representing the fundamental
     * store object. This holds specific scraping
     * information for each store.
     */
    class Store 
    {
    private:
        std::string m_url;
        std::queue<std::unique_ptr<ScrapedProduct>> m_product_queue;
        std::queue<std::shared_ptr<Category>> m_category_queue;
    public:
        /**
         * @brief Construct a new Store object.
         * 
         * @param url The URL of the store.
         */
        Store(const std::string& url);

        /**
         * @brief Get the URL object within
         * this store object.
         * 
         * @return std::string& The specified
         * store URL.
         */
        std::string& GetUrl();

        /**
         * @brief This function generates the specific
         * URL which should be used for requests made
         * towards this store object.
         * 
         * @param item The item (i.e. the category)
         * for which we are browsing.
         * @return std::string The request URL
         * for this specific item.
         */
        virtual std::string RequestUrl(const std::string& item) = 0;

        /**
         * @brief Get the queue object holding
         * information about the current product
         * queue. This queue is used to remotely
         * store data towards the database.
         * 
         * The idea is that data is bulk-written
         * as to ensure good performance. The
         * objects within the queue are objects
         * which have been scraped.
         * 
         * @return std::queue<std::unique_ptr<ScrapedProduct>>& 
         * A reference towards the queue of scraped products.
         */
        std::queue<std::unique_ptr<ScrapedProduct>>& GetProductQueue();

        /**
         * @brief Get the categories which are waiting
         * to be scraped.
         * 
         * The objects at the front of the queue
         * may or may not have yet been scraped.
         * 
         * The idea is that once an object was
         * eventually scraped, it is removed
         * from the front of the queue and pushed
         * towards its end, whilst also being
         * marked so.
         * 
         * @if The category is scraped, it will become available
         * for scraping again within 24 hours (default).
         * 
         * @return std::queue<std::shared_ptr<Category>>& 
         * A reference towards the queue of categories.
         */
        std::queue<std::shared_ptr<Category>>& GetCategoryQueue();

        /**
         * @brief Adds a category towards the
         * current queue.
         * 
         * @param category_ptr A shared pointer
         * towards the category. Note that a shared
         * pointer is required here as the same
         * category object will be owned by multiple
         * stores.
         */
        void AddCategory(std::shared_ptr<Category>& category_ptr);

        /**
         * @brief Initializes the scraping
         * operation.
         * 
         * This function generates one thread
         * per store which will manage its scraping.
         * Therefore, it is to be noted that this
         * method runs asynchronously and should
         * be treated as such.
         * 
         * Note that this method is a virtual function
         * and should be implemented for each individual
         * store, as they have different HTML codes.
         */
        virtual void scrape() = 0;
    };

    /**
     * @brief Implementation of the Store
     * object for the EMag marketplace.
     */
    class EMag : public Store
    {
    public:
        /**
         * @brief The base constructor for the
         * EMag marketplace.
         */
        EMag();

        /**
         * @brief This function generates the specific
         * URL which should be used for requests made
         * towards this store object.
         * 
         * @param item The item (i.e. the category)
         * for which we are browsing.
         * @return std::string The request URL
         * for this specific item.
         */
        std::string RequestUrl(const std::string& item) override;

        /**
         * @brief Initializes the scraping
         * operation for this specific store.
         */
        void scrape() override;
    };
}

#endif