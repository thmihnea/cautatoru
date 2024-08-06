#ifndef _CAUTATORU_CATEGORY_H
#define _CAUTATORU_CATEGORY_H

#include <string>

namespace Cautatoru
{
    class Category
    {
    private:
        bool timeout;
        std::string name;
    public:
        Category(const std::string& name, const bool& timeout);

        bool& IsTimeout();

        void SetTimeout(bool timeout);

        std::string& GetName();
    };
}

#endif