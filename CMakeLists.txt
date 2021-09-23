cmake_minimum_required(VERSION 3.21)
project(handler)

set(CMAKE_CXX_STANDARD 14)

add_executable(handler main.cpp message.cpp message.h handler.cpp handler.h message_queue.cpp message_queue.h looper.cpp looper.h)
