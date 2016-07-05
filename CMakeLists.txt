cmake_minimum_required(VERSION 3.5)
project(restino)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Request.cpp Request.h RequestBuilder.cpp RequestBuilder.h http.h Rest.cpp Rest.h restino.h TypeCollection.cpp TypeCollection.h HeaderCollection.cpp HeaderCollection.h)
add_executable(restino ${SOURCE_FILES})