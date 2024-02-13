cmake_minimum_required(VERSION 3.26)
project(Julti_Launcher C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_AUTORCC ON)

if(WIN32)
    set(CMAKE_WIN32_EXECUTABLE ON)
    add_executable(Julti_Launcher main.c app.rc)  # Add resources.rc to sources
endif()
