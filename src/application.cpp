
#include <iostream>
#include <stdexcept>

#include "application.h"


int Application::init() {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW\n");
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    if (!primaryMonitor) {
        throw std::runtime_error("Failed to get primary monitor\n");
    }

    const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);
    if (videoMode) {
        window = glfwCreateWindow(0.8 * videoMode->width, 0.8 * videoMode->height, TITLE, nullptr, nullptr);
    } else {
        throw std::runtime_error("Failed to get video mode\n");
    }

    return 0;
}

int Application::mainloop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    return 0;
}

void Application::cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

int Application::exec() {
    try {
        init();
        mainloop();    
        cleanup();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        glfwTerminate();
        return -1;
    }
    
    return 0;
}
