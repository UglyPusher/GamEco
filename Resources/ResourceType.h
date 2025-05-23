#pragma once

#include <string>
#include <unordered_map>

class ResourceType {
public:
    ResourceType(const std::string& name, int volume);

    int getId() const;
    const std::string& getName() const;
    int getVolume() const;

    bool isCraftable() const;
    const std::unordered_map<int, int>& getRecipe() const;
    void setRecipe(const std::unordered_map<int, int>& recipe);

private:
    static int nextId_;     // Статический счетчик для автоматической нумерации

    int id_;
    std::string name_;
    int volume_;
    std::unordered_map<int, int> componentResourceQuantities_;
};
