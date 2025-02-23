
#include "application.h"
#include <chrono>
#include <thread>

Application::Application() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(1000, 1000, "APP", nullptr, nullptr);
}

void Application::init_vulkan() {

}

void Application::exec() {
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
