
cmake_minimum_required(VERSION 3.28)
project(vulkan)

set(CMAKE_CXX_COMPILER "g++")

set(glfw3_DIR "${CMAKE_SOURCE_DIR}/3rdParty/glfw-3.4/lib/cmake/glfw3/")
find_package(glfw3 REQUIRED)

add_executable(
    main
    src/application.cpp
    src/main.cpp
)
target_include_directories(main PUBLIC src/ "/home/janetatomas11/Desktop/tj/vulkan/3rdParty/glfw-3.4/include")
target_link_libraries(main "/home/janetatomas11/Desktop/tj/vulkan/3rdParty/glfw-3.4/lib/libglfw3.a")
