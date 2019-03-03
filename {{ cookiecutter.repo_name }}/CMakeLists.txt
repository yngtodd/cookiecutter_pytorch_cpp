# {{ cookiecutter.full_name }}. Copyright (C) {{ cookiecutter.year }}. GPLv3


#
# Project Properties
#
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project ({{ cookiecutter.repo_name }})
set (APPLICATION_NAME "{{ cookiecutter.project_name }}")
set (APPLICATION_CODENAME "${PROJECT_NAME}")
set (APPLICATION_COPYRIGHT_YEARS "{{ cookiecutter.year }}")
set (APPLICATION_VERSION_MAJOR 0)
set (APPLICATION_VERSION_MINOR 1)
set (APPLICATION_VERSION_PATCH 0)
set (APPLICATION_VERSION_TYPE SNAPSHOT)
set (APPLICATION_VERSION_STRING "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}-${APPLICATION_VERSION_TYPE}")

#
# Requirements
#
find_package(Torch REQUIRED)


#
# Debugging Options
#
set (CMAKE_VERBOSE_MAKEFILE 0) # Use 1 for debugging, 0 for release


#
# Project Output Paths
#
set (MAINFOLDER ${PROJECT_SOURCE_DIR})
set (EXECUTABLE_OUTPUT_PATH "${MAINFOLDER}/bin")
set (LIBRARY_OUTPUT_PATH "${MAINFOLDER}/lib")
set (CATCH_DIR "${MAINFOLDER}/external/catch")


#
# Add Build Targets
#
#add_library({{ cookiecutter.project_name }}_example)

file (GLOB productionSources src/*.cpp)
add_library ({{ cookiecutter.project_name }}_example STATIC ${productionSources})
target_include_directories ({{ cookiecutter.project_name }}_example PRIVATE ${PROJECT_SOURCE_DIR}/include)

#add_subdirectory(src)
#add_subdirectory(include)

add_executable(example calculator.cpp main.cpp)
target_link_libraries(example "${TORCH_LIBRARIES}")
target_link_libraries(example {{ cookiecutter.project_name }}_example)
target_include_directories(example PRIVATE ${MAINFOLDER}/include)
set_property(TARGET example PROPERTY CXX_STANDARD 11)

#enable_testing()
#add_subdirectory(test)


#
# Add Install Targets
#
if (EXISTS "${MAINFOLDER}/include/${PROJECT_NAME}" AND IS_DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}")
    install(DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}" DESTINATION "include")
endif (EXISTS "${MAINFOLDER}/include/${PROJECT_NAME}" AND IS_DIRECTORY "${MAINFOLDER}/include/${PROJECT_NAME}")
