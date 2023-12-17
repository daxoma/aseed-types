cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project("test" VERSION 0.1)


# configure
set(ROOT_DIR "${${PROJECT_NAME}_SOURCE_DIR}")
set(CMAKE_DIR "${ROOT_DIR}/cmake")

include("${CMAKE_DIR}/configure.cmake")
set(PROJECT_RUNTIME_DIRECTORY "${ROOT_DIR}/bin")
set(PROJECT_LIBRARY_DIRECTORY "${PROJECT_RUNTIME_DIRECTORY}")
include("${CMAKE_DIR}/set_compiler_options.cmake")
include("${CMAKE_DIR}/set_directories.cmake")

# libraries dir
link_directories(${PROJECT_RUNTIME_DIRECTORY})

# exec object
file(GLOB PROJECT_SOURCES "./*.cpp")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# link options (flags & objects)
include("${CMAKE_DIR}/set_linker_options.cmake")

# we can't set up TARGET directories befor add_MODULE (
target_include_directories(${PROJECT_NAME} PUBLIC
    "${ROOT_DIR}/thirdparty"
)

