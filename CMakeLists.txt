#Auto Generated Root CMake file by aura CLI
#Copyright(c) 2025 None.All rights reerved.
cmake_minimum_required(VERSION 3.6...3.31)
project(baseline VERSION 1.0.0 LANGUAGES CXX)
include(res/config.cmake)
#@add_find_package Warning: Do not remove this line
find_package(Boost REQUIRED COMPONENTS process)
find_package(7zip CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
#@add_subproject Warning: Do not remove this line
add_subdirectory(baseline)
