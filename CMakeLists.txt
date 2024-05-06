cmake_minimum_required(VERSION 3.27)
project(PJC_Project)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master
)
FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(SFML)
add_executable(PJC_Project src/main.cpp)
target_link_libraries(PJC_Project fmt sfml-graphics)
