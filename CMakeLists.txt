cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/anasteyshakoshman/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "1290f4b8d32ce4fef2b9101c9d951649224e1ca5"
)

project(main)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(main CURL::libcurl)

install(TARGETS main RUNTIME DESTINATION bin)
