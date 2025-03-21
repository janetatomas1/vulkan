
cmake_minimum_required(VERSION 3.28)
project(vulkan)

set(CMAKE_CXX_COMPILER "g++")


add_executable(
    main src/main.cpp src/application.cpp
)

set(glfw3_DIR "/home/toms/Desktop/tj/VulkanTutorial/code/glfw-3.4/lib/cmake/glfw3")
set(glm_DIR "/home/toms/Desktop/tj/VulkanTutorial/code/glm-1.0.1/release/share/glm/")
set(tinyobjloader_DIR "/home/toms/Desktop/tj/VulkanTutorial/code/tinyobjloader-1.0.6/release/lib/tinyobjloader/cmake/")
set(STB_INCLUDEDIR "/home/toms/Desktop/tj/VulkanTutorial/code/stb/")

find_package(glfw3 REQUIRED)

target_include_directories(main PUBLIC include "/home/toms/Desktop/tj/VulkanTutorial/code/glfw-3.4/include")
target_link_libraries(main "/home/toms/Desktop/tj/VulkanTutorial/code/glfw-3.4/lib/libglfw3.a")
