cmake_minimum_required(VERSION 3.10)
project(FLP_linux)

set(CMAKE_CXX_STANDARD 17)
add_library(stdc++fs UNKNOWN IMPORTED)
set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "/usr/lib/gcc/x86_64-linux-gnu/7/libstdc++fs.a")

add_executable(FLP_linux main.cpp fileReader.cpp fileReader.h keywords.cpp keywords.h)
target_link_libraries(${PROJECT_NAME} stdc++fs)