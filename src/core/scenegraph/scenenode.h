#ifndef SCENENODE_H
#define SCENENODE_H

#include <list>
#include <string>
#include <functional>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>

class SceneNode
{
public:
    explicit SceneNode(std::string name);
    virtual ~SceneNode() { destroy(); };

    void release() { delete this; }

    virtual void updateSelf();
    virtual void updateAll();
    void addChild(SceneNode* new_child);

    void setParent(SceneNode *_parent) {
        parent = _parent;
    }

    void setTransform(glm::mat4 p_transform) {
        transform = p_transform;
    }

    void setPos(glm::vec3 p_pos) {
        pos = p_pos;
    }

    virtual void debug_printObject(int level = 0);

protected:
    std::string name;
    SceneNode* parent;
    std::list<SceneNode*> children;

    glm::mat4 transform;
    glm::vec3 pos;
private:
    void destroy() {
        for (auto i = children.begin(); i != children.end(); i++ ) {
            (*i)->release();
        }
      
        children.clear();
    }
};

#endif
