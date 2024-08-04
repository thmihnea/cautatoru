#include <vector>
#include <memory>
#include "../Store/store.h"
#include "request_manager.h"

Cautatoru::RequestManager::RequestManager()
{
    this->m_store_data = std::vector<std::unique_ptr<Store>>();

    this->m_store_data.push_back(
        std::make_unique<EMag>()
    );
}

std::vector<std::unique_ptr<Cautatoru::Store>>& Cautatoru::RequestManager::GetStoreData()
{
    return this->m_store_data;
}