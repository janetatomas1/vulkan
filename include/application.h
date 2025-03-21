
#include <GLFW/glfw3.h>

class Application {
    int init();
    int mainloop();
    void cleanup();

    GLFWwindow *window;
    const char *TITLE = "APPLICATION";

public:
    Application() = default;
    int exec();
};
