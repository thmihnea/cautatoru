#ifndef _CAUTATORU_CATEGORY_H
#define _CAUTATORU_CATEGORY_H

#include <string>

namespace Cautatoru
{
    /**
     * @brief This is a wrapper class
     * that holds information about a category
     * which should be scraped.
     */
    class Category
    {
    private:
        bool timeout;
        std::string name;
    public:
        /**
         * @brief Construct a new Category object.
         * 
         * @param name The name of the category.
         * @param timeout Whether or not the category
         * is currently in timeout mode.
         * 
         * @if The object is in timeout mode, then it
         * will be skipped in the next scraping operation.
         * This timeout usually takes ~24 hours.
         */
        Category(const std::string& name, const bool& timeout);

        /**
         * @brief Checks if a category is in
         * timeout mode.
         * 
         * @return true if yes
         * @return false otherwise
         */
        bool& IsTimeout();

        /**
         * @brief Set the current category's
         * timeout mode.
         * 
         * @param timeout true/false
         */
        void SetTimeout(bool timeout);

        /**
         * @brief Get the name of the 
         * category to be used in the request
         * URL.
         * 
         * @return std::string& The name
         * of the category.
         */
        std::string& GetName();
    };
}

#endif