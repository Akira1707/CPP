cmake_minimum_required(VERSION 3.10)
project(lab1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    src/Operation.cpp
    src/Cosx.cpp
    src/Power.cpp
    src/Sinx.cpp
    src/Tanx.cpp
    src/Cotanx.cpp
    src/Logarithm.cpp
    src/Operation.cpp
)

include_directories(include)
add_library(lab1 SHARED ${SOURCE_FILES})
add_executable(main src/lab1.cpp)
target_link_libraries(main lab1)
