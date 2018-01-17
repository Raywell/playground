#ifndef ASSET_H
#define ASSET_H

#include <string>

class Asset
{
public:
    explicit Asset(std::string name);
    virtual ~Asset() = 0;

    void release() { delete this; }

protected:
    std::string name;
private:
};

#endif
