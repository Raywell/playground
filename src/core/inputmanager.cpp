#include "inputmanager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager() {
}

void InputManager::registerCallback(int key, int action, std::function<void(void)> callback) {
    std::pair<int,int> key_action = std::make_pair(key,action);

    auto callbacks_it = key_callbacks.find(key_action);
    if (callbacks_it != key_callbacks.end()) {
        callbacks_it->second.push_back(callback);
    } else {
        std::vector<std::function<void(void)>> key_functions;
        key_functions.push_back(callback);
        key_callbacks[key_action] = key_functions;
    }
}

void InputManager::setMousePos(double xpos, double ypos) {
    mouse_pos.x = xpos;
    mouse_pos.y = ypos;
}

void InputManager::keyCallback(int key, int action)
{
    // Calling every callback associated with the couple KEY/ACTION
    std::pair<int,int> key_action = std::make_pair(key,action);
    auto key_functions = key_callbacks.find(key_action);
    if (key_functions != key_callbacks.end()) {
        for(auto const& callback : key_functions->second) {
            callback();
        }
    }
}
