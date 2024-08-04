#include <string>
#include "store.h"

static const std::string EMAG_URL = "https://www.emag.ro";

Cautatoru::Store::Store(const std::string& url)
{
    this->url = url;
}

std::string Cautatoru::Store::GetUrl() const
{
    return this->url;
}

Cautatoru::EMag::EMag() : Store(EMAG_URL) {}

std::string Cautatoru::EMag::RequestUrl(const std::string& item) const
{
    return this->GetUrl() + "/search/" + item + "?ref=effective_search";
}