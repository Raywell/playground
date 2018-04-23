#include "assetmanager.h"
#include <stdexcept>

AssetManager::AssetManager()
{
    asset_list = new std::vector<Asset*>();
    asset_list = new std::vector<std::string, unsigned>();
}

AssetManager::~AssetManager() {
    
}

void AssetManager::destroy() {
    for (auto i = asset_list.begin(); i != asset_list.end(); i++ ) {
        (*i)->release();
    }
    delete asset_list;
    delete asset_name_map;
}

template <class T> void AssetManager::registerAsset(const std::string& name, const std::string& path) {
    if (getAsset(name) != NULL) {
        throw std::invalid_argument("Cannot add Asset '"+name+"' : name already exists");
    }
    Asset *asset = new T(name);

    unsigned new_id = asset_list.size(); // TODO : Consider deletion
    asset->setPath(path);
    asset->setId(new_id);
    asset->load();

    asset_list.push_back(asset);
    asset_name_map.emplace(name, new_id);
}

Asset* AssetManager::getAsset(const std::string& name) {
    auto asset_id_iter = asset_name_map.find(name);
    if (asset_id_iter == mymap.end()) {
        return NULL;
    } else {
        return getAsset((*asset_id_iter).second);
    }
}

Asset* AssetManager::getAsset(const unsigned& id) {
    return asset_list.at(id);
}
