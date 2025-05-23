#pragma once

#include "ResourceType.h"
#include <unordered_map>
#include <memory>
#include <string>

class ResourceRegistry {
public:
    // ��������� ����� ��� �������, ���������� ��� ID
    int addResource(const std::string& name, int volumePerUnit);

    // �������� ������ �� ID, nullptr ���� �� ������
    const ResourceType* getResourceById(int id) const;

    // ��������� ������� �� ���������� ����������������� �����
    bool loadFromFile(const std::string& filename);

private:
    std::unordered_map<int, ResourceType> resourceMap_;
};
