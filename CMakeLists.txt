cmake_minimum_required(VERSION 3.16)
project(Operating_Systems_XV6_HW2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Operating_Systems_XV6_HW2 main.c queue.h queue.c mlq.h mlq.c)