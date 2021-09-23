cmake_minimum_required(VERSION 3.21)
project(handler)

set(CMAKE_CXX_STANDARD 14)

# add extra include directories
include_directories(/usr/local/Cellar/libevent/2.1.12/include)
# add extra lib directories
link_directories(/usr/local/Cellar/libevent/2.1.12/lib)

add_executable(handler main.cpp message.cpp message.h handler.cpp handler.h message_queue.cpp message_queue.h looper.cpp looper.h)

target_link_libraries(handler event)