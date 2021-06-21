cmake_minimum_required(VERSION 3.0.0)
project(debugger VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(debugger debugger.c utils.c)
