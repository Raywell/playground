#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <vector>
#include <functional>

#include <GLFW/glfw3.h>

// Globals
extern std::vector<std::function<void(int,int)>> g_keyHandlers;

class WindowManager
{
public:
    WindowManager();
    virtual ~WindowManager();

    GLFWwindow* getWindow() { return window; }

    void createRenderingWindow(std::string window_title, float _width, float _height);
    bool windowShouldClose();
    void swapBuffers();

    // Done every frame
    void frameAction();

    void closeWindow();
    void bindCloseWindowKeyAction(int key, int action);

    int getWidth() { return width; }
    int getHeight() { return height; }
    void setWidthHeight(float _width, float _height);
protected:
private:
    GLFWwindow *window = NULL;
    int width;
    int height;

    void addKeyHandler(std::function<void(int,int)> callback)
    {
        g_keyHandlers.push_back(callback);
    }
};

#endif
