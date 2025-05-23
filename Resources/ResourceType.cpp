#include "ResourceType.h"

// Инициализация статического счетчика
int ResourceType::nextId_ = 0;

ResourceType::ResourceType(const std::string& name, int volume)
    : id_(nextId_++), name_(name), volume_(volume) {}

int ResourceType::getId() const {
    return id_;
}

const std::string& ResourceType::getName() const {
    return name_;
}

int ResourceType::getVolume() const {
    return volume_;
}

bool ResourceType::isCraftable() const {
    return !componentResourceQuantities_.empty();
}

const std::unordered_map<int, int>& ResourceType::getRecipe() const {
    return componentResourceQuantities_;
}

void ResourceType::setRecipe(const std::unordered_map<int, int>& recipe) {
    componentResourceQuantities_ = recipe;
}
