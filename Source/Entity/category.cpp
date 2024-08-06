#include <string>
#include "category.h"

Cautatoru::Category::Category(const std::string& name, const bool& timeout)
{
    this->name = name;
    this->timeout = timeout;
}

std::string& Cautatoru::Category::GetName()
{
    return this->name;
}

bool& Cautatoru::Category::IsTimeout()
{
    return this->timeout;
}

void Cautatoru::Category::SetTimeout(bool timeout)
{
    this->timeout = timeout;
}