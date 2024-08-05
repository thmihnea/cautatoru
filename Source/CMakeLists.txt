include_directories(Scraper)

set(SOURCES
    cautatoru.cpp
    logging_manager.cpp
    Entity/scraped_product.cpp
    Scraper/scraper.cpp
    Store/store.cpp
    Request/request_manager.cpp
)

add_executable(cautatoru ${SOURCES})

target_link_libraries(cautatoru PRIVATE log4cxx)
target_link_libraries(cautatoru PRIVATE LibXml2::LibXml2)
target_link_libraries(cautatoru PRIVATE cpr::cpr)
target_link_libraries(cautatoru PRIVATE nlohmann_json::nlohmann_json)