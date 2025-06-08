#pragma once

#include "..\Core\BaseIdentifiable.h"
#include <string>
#include <unordered_map>

/// [AI: PURPOSE] Описание типа ресурса (например, еда, энергия).
/// [AI: DESIGN] Имеет уникальный ID и создаётся через ResourceRegistry.
class ResourceType : public BaseIdentifiable {
public:
    ResourceType(const std::string& name, uint64_t volume);

    /// [AI: PURPOSE] Получить имя ресурса.
    const std::string& getName() const;

    /// [AI: PURPOSE] Получить объём одной единицы ресурса.
    uint64_t getVolume() const;

    /// [AI: PURPOSE] Является ли ресурс составным.
    bool isCraftable() const;

    /// [AI: PURPOSE] Получить рецепт крафта (если применимо).
    const std::unordered_map<IdType, uint64_t>& getRecipe() const;

    /// [AI: PURPOSE] Установить рецепт крафта.
    void setRecipe(const std::unordered_map<IdType, uint64_t>& recipe);

private:
    std::string name_;
    uint64_t volume_ = 0;
    std::unordered_map<IdType, uint64_t> componentResourceQuantities_;
};
