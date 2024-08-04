#ifndef _CAUTATORU_REQUEST_MANAGER_H
#define _CAUTATORU_REQUEST_MANAGER_H

#include <vector>
#include <memory>
#include "../Store/store.h"

namespace Cautatoru
{
    class RequestManager
    {
    private:
        std::vector<std::unique_ptr<Store>> m_store_data;
    public:
        RequestManager();

        std::vector<std::unique_ptr<Store>>& GetStoreData();
    };
}

#endif