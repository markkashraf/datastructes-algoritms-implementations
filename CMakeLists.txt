cmake_minimum_required(VERSION 3.23)
project(CPP_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(cmake-build-debug)

add_executable(CPP_Code
        .idea/.gitignore
        ".idea/CPP Code.iml"
        .idea/modules.xml
        .idea/workspace.xml
        gg.cpp)
