cmake_minimum_required(VERSION 3.5)
project(C_Project_Calendar)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES
    headers/agenda.h
    headers/event.h
    headers/export.h
    src/agenda.c
    src/event.c
    src/export.c
    src/main.c)

add_executable(C_Project_Calendar ${SOURCE_FILES})