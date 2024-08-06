#ifndef _CAUTATORU_SCRAPED_PRODUCT_H
#define _CAUTATORU_SCRAPED_PRODUCT_H

#include <string>

namespace Cautatoru
{
    /**
     * @brief Class which holds data
     * regarding a scraped product.
     */
    class ScrapedProduct
    {
    private:
        std::string m_name;
        float m_price;
        float m_rating;
        int m_review_count;
    public:
        /**
         * @brief Construct a new Scraped Product object.
         * 
         * @param name The name of the product.
         * @param price The price of the product.
         * @param rating The rating of the product.
         * @param review_count The amount of reviews.
         */
        ScrapedProduct(std::string& name, float& price, float& rating, int& review_count);

        /**
         * @brief Returns the name of the
         * product.
         * 
         * @return std::string& The name
         * of the product.
         */
        std::string& GetName();

        /**
         * @brief Returns the price of the
         * product.
         * 
         * @return float& The price of the
         * current product.
         */
        float& GetPrice();

        /**
         * @brief Returns the rating of the
         * product.
         * 
         * @return float& The rating of the
         * product.
         */
        float& GetRating();

        /**
         * @brief Returns the review count
         * of the product.
         * 
         * @return int& The review count of
         * the product.
         */
        int& GetReviewCount();
    };
}

#endif