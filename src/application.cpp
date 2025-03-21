
#include <iostream>
#include <stdexcept>

#include "application.h"


void Application::init() {
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
}

void Application::init_vulkan() {
    create_instance();
}

void Application::create_instance() {
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = TITLE;
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No engine";
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }
}

void Application::mainloop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
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
