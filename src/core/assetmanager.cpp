#include "assetmanager.h"
#include <stdexcept>

AssetManager::AssetManager()
{
    asset_list = std::vector<Asset*>();
    asset_name_map = std::unordered_map<std::string, unsigned>();
}

void AssetManager::destroy() {
    for (auto i = asset_list.begin(); i != asset_list.end(); i++ ) {
        (*i)->release();
    }
}

Asset* AssetManager::getAsset(const std::string& name) {
    auto asset_id_iter = asset_name_map.find(name);
    if (asset_id_iter == asset_name_map.end()) {
        return NULL;
    } else {
        return getAsset((*asset_id_iter).second);
    }
}

Asset* AssetManager::getAsset(const unsigned& id) {
    return asset_list.at(id);
}
