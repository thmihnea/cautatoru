#ifndef _CAUTATORU_STORE_H
#define _CAUTATORU_STORE_H

#include <string>
#include <queue>
#include <memory>
#include <vector>
#include "../Entity/scraped_product.h"

namespace Cautatoru
{
    class Store 
    {
    private:
        std::string m_url;
        std::queue<std::unique_ptr<ScrapedProduct>> m_product_queue;
    public:
        Store(const std::string& url);

        std::string& GetUrl();

        virtual std::string RequestUrl(const std::string& item) = 0;

        std::queue<std::unique_ptr<ScrapedProduct>>& GetProductQueue();

        virtual void scrape(std::vector<std::string>& category) = 0;
    };

    class EMag : public Store
    {
    public:
        EMag();

        std::string RequestUrl(const std::string& item) override;

        void scrape(std::vector<std::string>& category) override;
    };
}

#endif