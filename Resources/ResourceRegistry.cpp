 #include "ResourceRegistry.h"
#include <fstream>
#include <sstream>
#include <iostream>

int ResourceRegistry::addResource(const std::string& name, int volumePerUnit) {
    ResourceType resource(name, volumePerUnit);
    int id = resource.getId();
    resourceMap_.emplace(id, std::move(resource));
    return id;
}

const ResourceType* ResourceRegistry::getResourceById(int id) const {
    auto it = resourceMap_.find(id);
    return it != resourceMap_.end() ? &it->second : nullptr;
}

bool ResourceRegistry::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open resource config file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Пропускаем пустые строки и комментарии
        if (line.empty() || line[0] == '#') continue;

        std::istringstream iss(line);
        std::string name;
        int volumePerUnit;

        if (!(iss >> name >> volumePerUnit)) {
            std::cerr << "Invalid line in resource config: " << line << std::endl;
            continue;
        }

        addResource(name, volumePerUnit);
    }

    return true;
}
