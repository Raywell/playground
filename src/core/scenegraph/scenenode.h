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
    SceneNode(std::string name = "", int level = 0);
    virtual ~SceneNode() { destroy(); };

    void destroy() {
        for (auto i = children.begin(); i != children.end(); i++ ) {
            (*i)->release();
        }
      
        children.clear();
    }
    void release() { delete this; }

    virtual void update();
    void addChild(SceneNode* new_child);

    void setLevel(int new_level);
    void addLevel(int diff);

    void setParent(SceneNode *_parent) {
        parent = _parent;
    }

    virtual void debug_printObject();

protected:
    std::string name;
    int level;
    SceneNode* parent;
    std::list<SceneNode*> children;
private:
};

#endif
