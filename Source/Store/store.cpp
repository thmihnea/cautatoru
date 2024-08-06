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
    this->m_category_queue = std::queue<std::shared_ptr<Cautatoru::Category>>();
}

std::string& Cautatoru::Store::GetUrl()
{
    return this->m_url;
}

std::queue<std::unique_ptr<Cautatoru::ScrapedProduct>>& Cautatoru::Store::GetProductQueue()
{
    return this->m_product_queue;
}

std::queue<std::shared_ptr<Cautatoru::Category>>& Cautatoru::Store::GetCategoryQueue()
{
    return this->m_category_queue;
}

Cautatoru::ScrapeTask* Cautatoru::Store::GetScrapeTask()
{
    return this->m_scrape_task.get();
}

void Cautatoru::Store::SetScrapeTask(std::thread& thread_ptr, std::atomic<bool>& atomic_ref)
{
    this->m_scrape_task = std::make_unique<ScrapeTask>(
        thread_ptr,
        atomic_ref
    );
}

void Cautatoru::Store::AddCategory(std::shared_ptr<Cautatoru::Category>& category_ptr)
{
    this->m_category_queue.push(category_ptr);
}

Cautatoru::EMag::EMag() : Store(EMAG_URL) {}

std::string Cautatoru::EMag::RequestUrl(const std::string& item)
{
    return this->GetUrl() + "/search/" + item + "?ref=effective_search";
}

void Cautatoru::EMag::Scrape()
{

}