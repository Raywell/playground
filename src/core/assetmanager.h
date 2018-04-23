#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <ireleasable.h>
#include "assets/asset.h"

class AssetManager : public IReleasable
{
public:
    AssetManager();
    virtual ~AssetManager() {};

    template <class T> void registerAsset(const std::string& name, const std::string& path = NULL);

    Asset* getAsset(std::string name);
    Asset* getAsset(unsigned id); // Throws exception if not exists

protected:
    std::vector<Asset*> asset_list;
    std::unordered_map<std::string, unsigned> asset_name_map;
private:
    void destroy();
};

#endif
