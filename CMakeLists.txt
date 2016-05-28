cmake_minimum_required(VERSION 3.5)
project(Assignment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        utils/HashSum.hpp
        utils/Integer.hpp utils/Integer.cpp
        model/Account.cpp model/Account.hpp
        utils/DateTimeFormat.hpp utils/DateTimeFormat.cpp
        Configs.hpp
        AccountManager.cpp AccountManager.hpp
        utils/Utils.hpp utils/Utils.cpp
        utils/MenuHelper.cpp utils/MenuHelper.hpp screens/LoginScreen.cpp screens/LoginScreen.hpp screens/AdminScreen.cpp screens/AdminScreen.hpp)
add_executable(Assignment ${SOURCE_FILES})