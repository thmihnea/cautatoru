#ifndef _CAUTATORU_SCRAPED_PRODUCT_H
#define _CAUTATORU_SCRAPED_PRODUCT_H

#include <string>

namespace Cautatoru
{
    class ScrapedProduct
    {
    private:
        std::string m_name;
        float m_price;
        float m_rating;
        int m_review_count;
    public:
        ScrapedProduct(std::string& name, float& price, float& rating, int& review_count);

        std::string& GetName();

        float& GetPrice();

        float& GetRating();

        int& GetReviewCount();
    };
}

#endif