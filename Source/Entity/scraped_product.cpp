#include <string>
#include "scraped_product.h"

Cautatoru::ScrapedProduct::ScrapedProduct(std::string& name, float& price, float& rating, int& review_count)
{
    this->m_name = name;
    this->m_price = price;
    this->m_rating = rating;
    this->m_review_count = review_count;
}

std::string& Cautatoru::ScrapedProduct::GetName()
{
    return this->m_name;
}

float& Cautatoru::ScrapedProduct::GetPrice()
{
    return this->m_price;
}

float& Cautatoru::ScrapedProduct::GetRating()
{
    return this->m_rating;
}

int& Cautatoru::ScrapedProduct::GetReviewCount()
{
    return this->m_review_count;
}