cmake_minimum_required(VERSION 3.20)

project(PCAImageCompression)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(fmt REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(PCAImageCompression PRIVATE
    include
)

target_link_libraries(PCAImageCompression PRIVATE
    Eigen3::Eigen
    ${OpenCV_LIBS}
    fmt::fmt
)
