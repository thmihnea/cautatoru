#include <iostream>
#include <memory>
#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "logging_manager.h"
#include "Request/request_manager.h"

int main(int argc, char** argv)
{
    // Set up logging-related utilities.
    log4cxx::BasicConfigurator::configure();

    Cautatoru::log_info(
        "Set up logging utilities."
    );

    // Set up the request manager.
    auto request_manager = std::make_unique<Cautatoru::RequestManager>();

    Cautatoru::log_info(
        "Set up the request manager."
    );

    Cautatoru::log_info(
        "Application started successfully."
    );

    return EXIT_SUCCESS;
}