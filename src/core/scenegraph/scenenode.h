#ifndef SCENENODE_H
#define SCENENODE_H

#include <list>
#include <string>
#include <functional>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>

#include <ireleasable.h>

class SceneNode : public IReleasable
{
public:
    explicit SceneNode(std::string name);
    virtual ~SceneNode() {};

    virtual void loadSelf() {};
    virtual void updateSelf() {};

    void loadAll();
    void updateAll();
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

    std::string getName() { return name; }
    void setName(std::string _name) { name = _name; }

    // Every cycle, only changed items are processed
    void setUpdatedFlg() { update_required = true; }

    void setLoadFlg() { load_required = true; }

    virtual void debug_printObject(int level = 0);

protected:
    void destroy();

    std::string name;
    SceneNode* parent;
    std::list<SceneNode*> children;
    bool update_required;
    bool always_update = false; // Some nodes may want to handle update themselves
    bool load_required;

    glm::mat4 transform;
    glm::vec3 pos;
private:
};

#endif
