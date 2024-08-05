#include "logging_manager.h"
#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"

static auto logger_ptr = log4cxx::Logger::getLogger("Cautatoru");

log4cxx::LoggerPtr& Cautatoru::GetLogger()
{
    return logger_ptr;
}

void Cautatoru::log_info(const std::string& message)
{
    LOG4CXX_INFO(
        GetLogger(),
        message
    );
}

void Cautatoru::log_error(const std::string& message)
{
    LOG4CXX_ERROR(
        GetLogger(),
        message
    );
}