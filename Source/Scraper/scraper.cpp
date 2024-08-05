#include <string>
#include "scraper.h"
#include "cpr/cpr.h"

#define USER_AGENT "User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36"

cpr::Response Cautatoru::Scrape(const std::string& url)
{
    cpr::Header headers = {{USER_AGENT}};
    return cpr::Get(cpr::Url{url}, headers);
}