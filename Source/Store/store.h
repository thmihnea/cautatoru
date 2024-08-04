#ifndef _CAUTATORU_STORE_H
#define _CAUTATORU_STORE_H

#include <string>

namespace Cautatoru
{
    class Store 
    {
    private:
        std::string url;
    public:
        Store(const std::string& url);

        std::string GetUrl() const;

        virtual std::string RequestUrl(const std::string& item) const = 0;
    };

    class EMag : public Store
    {
    public:
        EMag();

        std::string RequestUrl(const std::string& item) const override;
    };
}

#endif