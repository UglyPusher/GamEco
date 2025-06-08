#pragma once

#include "ResourceType.h"
#include <unordered_map>
#include <string>
#include <vector>

/// [AI: PURPOSE] ���������� ������ ���� ����� ��������.
/// [AI: DESIGN] ������������ ��� static-only API ��� ������������� ��������� ����������.
class ResourceRegistry {
public:
    /// [AI: PURPOSE] ���������������� ����� ������. ���������� ��� ���������� ID.
    static IIdentifiable::IdType addResource(const std::string& name, uint64_t volumePerUnit);

    /// [AI: PURPOSE] �������� ������ �� ID.
    static const ResourceType* getResourceById(IIdentifiable::IdType id);

    /// [AI: PURPOSE] �������� ������ �� ����� (���� ����������).
    static const ResourceType* getResourceByName(const std::string& name);

    /// [AI: PURPOSE] �������� ������ ���� ��������.
    static std::vector<const ResourceType*> getAllResources();

    /// [AI: PURPOSE] ��������� ������� �� ����������������� �����.
    static bool loadFromFile(const std::string& filename);

private:
    static std::unordered_map<IIdentifiable::IdType, ResourceType> resourceMap_;
    static std::unordered_map<std::string, IIdentifiable::IdType> nameToIdMap_;

    /// [AI: DESIGN] ��������� �������� �����������.
    ResourceRegistry() = delete;
};
