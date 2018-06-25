#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <unordered_map>
#include <ireleasable.h>
#include "assets/asset.h"
#include "assets/geometry.h"
#include "assets/mesh.h"

class AssetManager : public IReleasable
{
public:
    AssetManager();
    virtual ~AssetManager() {};

    template <class T> T* registerAsset(const std::string& name, const std::string& path = "") {
        if (getAsset(name) != NULL) {
            throw std::invalid_argument("Cannot add Asset '"+name+"' : name already exists");
        }
        T *asset = new T(name);

        long new_id = ++last_asset_id;
        asset->setPath(path);
        asset->setId(new_id);

        asset_list.push_back(asset);
        asset_name_map.emplace(name, new_id);

        return asset;
    }

    Asset* getAsset(const std::string& name);
    Asset* getAsset(const unsigned& id); // Throws exception if not exists

protected:
    std::vector<Asset*> asset_list;
    std::unordered_map<std::string, unsigned> asset_name_map;
private:
    void destroy();
    unsigned long last_asset_id = 0;
};

#endif
