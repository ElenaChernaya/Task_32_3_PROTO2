cmake_minimum_required(VERSION 3.16)
project(Task_32_3_PROTO2)

set(CMAKE_CXX_STANDARD 20)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_executable(Task_32_3_PROTO2 main.cpp)
add_subdirectory(nlohmann_json)

target_link_libraries(Task_32_3_PROTO2 PRIVATE nlohmann_json::nlohmann_json)