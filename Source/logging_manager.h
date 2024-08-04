#ifndef _CAUTATORU_LOGGING_MANAGER_H
#define _CAUTATORU_LOGGING_MANAGER_H

#include "log4cxx/logger.h"

namespace Cautatoru
{
    log4cxx::LoggerPtr GetLogger();

    void log_info(const std::string& message);

    void log_error(const std::string& message);
}

#endif