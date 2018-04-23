#ifndef ASSET_H
#define ASSET_H

#include <string>

#include <ireleasable.h>

class Asset : public IReleasable
{
public:
    explicit Asset(std::string name);
    virtual ~Asset() = 0;
    
    virtual void load() = 0;
    virtual void unload() = 0;

    void setId(unsigned p_id) { id = p_id; }
    unsigned getId() const { return id; }

    void setPath(const std::string& p_path) { path = p_path; }
    std::string getPath() const { return path; }

protected:
    unsigned id;
    std::string path;
    std::string name;
private:
};

#endif
