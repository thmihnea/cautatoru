#ifndef _CAUTATORU_LOGGING_MANAGER_H
#define _CAUTATORU_LOGGING_MANAGER_H

#include "log4cxx/logger.h"

namespace Cautatoru
{
    /**
     * @brief Returns a reference towards
     * the object used for logging information
     * about the runtime of the application.
     * 
     * @return log4cxx::LoggerPtr& The
     * specific logger object.
     */
    log4cxx::LoggerPtr& GetLogger();

    /**
     * @brief Logs a message marked as
     * 'INFO' towards stdout.
     * 
     * @param message The message which
     * should be logged.
     */
    void log_info(const std::string& message);

    /**
     * @brief Logs a message marked as
     * 'ERROR' towards stdout.
     * 
     * @note If this is ever used, the
     * application should also end its
     * execution. It is a good idea to also
     * throw an error with this.
     * 
     * @param message The message which should be
     * logged.
     */
    void log_error(const std::string& message);
}

#endif