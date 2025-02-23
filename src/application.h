
#include <GLFW/glfw3.h>

class Application {
    GLFWwindow *window;

public:
    Application();
    void init_vulkan();
    void exec();
};
