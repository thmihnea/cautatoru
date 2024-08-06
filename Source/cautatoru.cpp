#include <iostream>
#include <memory>
#include <chrono>
#include <string> 
#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "logging_manager.h"
#include "Request/request_manager.h"

int main(int argc, char** argv)
{
    // Record the start time.
    auto start_time = std::chrono::system_clock::now();

    // Set up logging-related utilities.
    log4cxx::BasicConfigurator::configure();
    Cautatoru::log_info("Set up logging utilities.");

    // Set up the request manager.
    auto request_manager = std::make_unique<Cautatoru::RequestManager>();
    Cautatoru::log_info("Set up the request manager.");

    // Record the end time
    auto end_time = std::chrono::system_clock::now();

    // Calculate the duration in seconds
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    Cautatoru::log_info("Application started successfully. This process took " + std::to_string(duration) + "ms.");

    // Schedule.
    request_manager.get()->schedule();

    return EXIT_SUCCESS;
}
