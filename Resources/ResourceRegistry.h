#pragma once

#include "ResourceType.h"
#include <unordered_map>
#include <memory>
#include <string>

class ResourceRegistry {
public:
    // Добавляет новый тип ресурса, возвращает его ID
    int addResource(const std::string& name, int volumePerUnit);

    // Получает ресурс по ID, nullptr если не найден
    const ResourceType* getResourceById(int id) const;

    // Загружает ресурсы из текстового конфигурационного файла
    bool loadFromFile(const std::string& filename);

private:
    std::unordered_map<int, ResourceType> resourceMap_;
};
