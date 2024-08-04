#ifndef _CAUTATORU_SCRAPER_H
#define _CAUTATORU_SCRAPER_H

#include <string>
#include "cpr/cpr.h"

namespace Cautatoru
{
    cpr::Response Scrape(const std::string& url);
}

#endif