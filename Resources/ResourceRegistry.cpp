#include "ResourceRegistry.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::unordered_map<IIdentifiable::IdType, ResourceType> ResourceRegistry::resourceMap_;
std::unordered_map<std::string, IIdentifiable::IdType> ResourceRegistry::nameToIdMap_;

IIdentifiable::IdType ResourceRegistry::addResource(const std::string& name, uint64_t volumePerUnit) {
    ResourceType resource(name, volumePerUnit);
    auto id = resource.getId();
    resourceMap_.emplace(id, resource);
    nameToIdMap_.emplace(name, id);
    return id;
}

const ResourceType* ResourceRegistry::getResourceById(IIdentifiable::IdType id) {
    auto it = resourceMap_.find(id);
    return it != resourceMap_.end() ? &it->second : nullptr;
}

const ResourceType* ResourceRegistry::getResourceByName(const std::string& name) {
    auto it = nameToIdMap_.find(name);
    if (it == nameToIdMap_.end()) return nullptr;
    return getResourceById(it->second);
}

std::vector<const ResourceType*> ResourceRegistry::getAllResources() {
    std::vector<const ResourceType*> result;
    result.reserve(resourceMap_.size());
    for (const auto& pair : resourceMap_) {
        result.push_back(&pair.second);
    }
    return result;
}

bool ResourceRegistry::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "[ResourceRegistry] Failed to open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        std::istringstream iss(line);
        std::string name;
        uint64_t volume;

        if (!(iss >> name >> volume)) {
            std::cerr << "[ResourceRegistry] Invalid line: " << line << std::endl;
            continue;
        }

        addResource(name, volume);
    }

    return true;
}
