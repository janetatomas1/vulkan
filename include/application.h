#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


class Application {
    void init();
    void init_vulkan();
    void create_instance();
    void mainloop();
    void cleanup();

    GLFWwindow *window;
    const char *TITLE = "APPLICATION";
    VkInstance instance;

public:
    Application() = default;
    int exec();
};
