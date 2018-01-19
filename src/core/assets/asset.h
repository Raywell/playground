#ifndef ASSET_H
#define ASSET_H

#include <string>

#include <ireleasable.h>

class Asset : public IReleasable
{
public:
    explicit Asset(std::string name);
    virtual ~Asset() = 0;

protected:
    std::string name;
private:
};

#endif
