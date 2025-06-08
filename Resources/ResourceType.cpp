#include "ResourceType.h"

ResourceType::ResourceType(const std::string& name, uint64_t volume)
    : name_(name), volume_(volume) {}

const std::string& ResourceType::getName() const {
    return name_;
}

uint64_t ResourceType::getVolume() const {
    return volume_;
}

bool ResourceType::isCraftable() const {
    return !componentResourceQuantities_.empty();
}

const std::unordered_map<IIdentifiable::IdType, uint64_t>& ResourceType::getRecipe() const {
    return componentResourceQuantities_;
}

void ResourceType::setRecipe(const std::unordered_map<IIdentifiable::IdType, uint64_t>& recipe) {
    componentResourceQuantities_ = recipe;
}
