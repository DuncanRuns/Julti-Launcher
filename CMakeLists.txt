cmake_minimum_required(VERSION 3.26)
project(Julti_Launcher C)

set(CMAKE_C_STANDARD 11)

if(WIN32)
    set(CMAKE_WIN32_EXECUTABLE ON)
endif()

add_executable(Julti_Launcher main.c)
