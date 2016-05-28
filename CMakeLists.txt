cmake_minimum_required(VERSION 3.5)
project(Assignment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        HashSum.hpp
        Integer.hpp Integer.cpp
        Account.cpp Account.hpp
        DateTimeFormat.hpp DateTimeFormat.cpp
        Configs.hpp
        AccountManager.cpp AccountManager.hpp
        Utils.hpp Utils.cpp
        MenuHelper.cpp MenuHelper.hpp LoginScreen.cpp LoginScreen.hpp)
add_executable(Assignment ${SOURCE_FILES})