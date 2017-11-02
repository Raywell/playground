#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <vector>
#include <functional>

#include <GLFW/glfw3.h>
#include "camera.h"

// Globals
extern std::vector<std::function<void(int,int)>> g_keyHandlers;

class WindowManager
{
public:
    WindowManager(int wRes, int hRes);
    virtual ~WindowManager();

    GLFWwindow* getWindow() { return window; }

    void init();
    bool createRenderingWindow();
    bool windowShouldClose();
    void swapBuffers();

    // Done every frame
    void frameAction();

    void bindCloseWindowKeyAction(int key, int action);

    int width;
    int height;
protected:
private:
    GLFWwindow *window = NULL;

    void addKeyHandler(std::function<void(int,int)> callback)
    {
        g_keyHandlers.push_back(callback);
    }
};

#endif
