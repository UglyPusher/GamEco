#pragma once

#include "..\Core\BaseIdentifiable.h"
#include <string>
#include <unordered_map>

/// [AI: PURPOSE] �������� ���� ������� (��������, ���, �������).
/// [AI: DESIGN] ����� ���������� ID � �������� ����� ResourceRegistry.
class ResourceType : public BaseIdentifiable {
public:
    ResourceType(const std::string& name, uint64_t volume);

    /// [AI: PURPOSE] �������� ��� �������.
    const std::string& getName() const;

    /// [AI: PURPOSE] �������� ����� ����� ������� �������.
    uint64_t getVolume() const;

    /// [AI: PURPOSE] �������� �� ������ ���������.
    bool isCraftable() const;

    /// [AI: PURPOSE] �������� ������ ������ (���� ���������).
    const std::unordered_map<IdType, uint64_t>& getRecipe() const;

    /// [AI: PURPOSE] ���������� ������ ������.
    void setRecipe(const std::unordered_map<IdType, uint64_t>& recipe);

private:
    std::string name_;
    uint64_t volume_ = 0;
    std::unordered_map<IdType, uint64_t> componentResourceQuantities_;
};
