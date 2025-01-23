cmake_minimum_required(VERSION 3.15)
project(Blocks)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DBX_CONFIG_DEBUG)

# Enable vcpkg integration
include(cmake/vcpkg.cmake)

# Helpers
include(cmake/helpers.cmake)

# Find packages
find_package(SDL2 CONFIG REQUIRED)
find_package(bgfx CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)

# Create executable
add_executable(${PROJECT_NAME} main.cpp)

# Add project modules
add_module(core)
add_module(engine)
add_module(graphics)
add_module(layers)
add_module(primitive)
add_module(scenes)
add_module(shaders)

# Project libraries
#target_link_libraries(${PROJECT_NAME} PUBLIC Core Primitive)
target_include_directories(${PROJECT_NAME} PUBLIC ${VCPKG_INCLUDE})

# External libraries
target_link_libraries(${PROJECT_NAME}
        PUBLIC
        SDL2::SDL2
        SDL2::SDL2main
        bgfx::bx
        bgfx::bgfx
        bgfx::bimg
        bgfx::bimg_decode
        Eigen3::Eigen
)