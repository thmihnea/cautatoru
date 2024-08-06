#ifndef _CAUTATORU_SCRAPER_H
#define _CAUTATORU_SCRAPER_H

#include <string>
#include "cpr/cpr.h"

namespace Cautatoru
{
    /**
     * @brief Utility function which scrapes
     * the HTML code of a given webpage URL.
     * 
     * @param url The URL in question.
     * @return cpr::Response The response
     * received upon the finalization of the
     * scraping operation.
     */
    cpr::Response Scrape(const std::string& url);
}

#endif