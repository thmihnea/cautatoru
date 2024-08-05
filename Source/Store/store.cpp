#include <string>
#include <memory>
#include <queue>
#include "store.h"
#include "../Entity/scraped_product.h"

static constexpr char* EMAG_URL = "https://www.emag.ro";

Cautatoru::Store::Store(const std::string& url)
{
    this->m_url = url;
    this->m_product_queue = std::queue<std::unique_ptr<Cautatoru::ScrapedProduct>>();
}

std::string& Cautatoru::Store::GetUrl()
{
    return this->m_url;
}

std::queue<std::unique_ptr<Cautatoru::ScrapedProduct>>& Cautatoru::Store::GetProductQueue()
{
    return this->m_product_queue;
}

Cautatoru::EMag::EMag() : Store(EMAG_URL) {}

std::string Cautatoru::EMag::RequestUrl(const std::string& item)
{
    return this->GetUrl() + "/search/" + item + "?ref=effective_search";
}

void Cautatoru::EMag::scrape(std::vector<std::string>& category)
{

}