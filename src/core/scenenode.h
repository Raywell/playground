#ifndef SCENENODE_H
#define SCENENODE_H

#include <vector>
#include <string>

class SceneNode
{
public:
    SceneNode(std::string name);
    virtual ~SceneNode();

    virtual void update();
    void addChild(SceneNode* new_child);
protected:
private:
    std::string name;
    SceneNode* parent;
    std::vector<SceneNode*> children;
};

#endif
