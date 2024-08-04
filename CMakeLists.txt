cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../target" CACHE STRING "Target directory")
set(CMAKE_TOOLCHAIN_FILE "~/Documents/repositories/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Package manager toolchain")

project(cautatoru)

find_package(log4cxx CONFIG REQUIRED)
find_package(LibXml2 CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_subdirectory(Source)