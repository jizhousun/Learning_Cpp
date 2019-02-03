cmake_minimum_required(VERSION 2.8.12)

project(Thread_Mutex)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread")
find_package(Qt5Core)

add_executable(${PROJECT_NAME} "main.cpp" "th.cpp" "basicclass.cpp")

target_link_libraries(${PROJECT_NAME} Qt5::Core)
