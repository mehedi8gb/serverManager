cmake_minimum_required(VERSION 3.12)
project(ServerManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(ServerManager
        src/main.cpp
        src/RegistryManager.cpp
        src/RegistryManager.h)
