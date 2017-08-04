#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <GLFW/glfw3.h>
#include "camera.h"

class WindowManager
{
public:
    WindowManager();
    virtual ~WindowManager();

    void init();
    bool createRenderingWindow();
    bool windowShouldClose();
    void swapBuffers();
    void closeWindow();
    int getKeyState(int key);

    int width;
    int height;
protected:
private:
    GLFWwindow *window = NULL;
};

#endif
