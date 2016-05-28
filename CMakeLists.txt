cmake_minimum_required(VERSION 3.5)
project(Assignment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp HashSum.hpp Integer.hpp Account.cpp Account.hpp DateTimeFormat.hpp Configs.hpp AccountManager.cpp AccountManager.hpp Utils.hpp Integer.cpp DateTimeFormat.cpp Utils.cpp)
add_executable(Assignment ${SOURCE_FILES})