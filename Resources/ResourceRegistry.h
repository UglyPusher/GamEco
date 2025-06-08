#pragma once

#include "ResourceType.h"
#include <unordered_map>
#include <string>
#include <vector>

/// [AI: PURPOSE] Глобальный реестр всех типов ресурсов.
/// [AI: DESIGN] Используется как static-only API без необходимости создавать экземпляры.
class ResourceRegistry {
public:
    /// [AI: PURPOSE] Зарегистрировать новый ресурс. Возвращает его уникальный ID.
    static IIdentifiable::IdType addResource(const std::string& name, uint64_t volumePerUnit);

    /// [AI: PURPOSE] Получить ресурс по ID.
    static const ResourceType* getResourceById(IIdentifiable::IdType id);

    /// [AI: PURPOSE] Получить ресурс по имени (если существует).
    static const ResourceType* getResourceByName(const std::string& name);

    /// [AI: PURPOSE] Получить список всех ресурсов.
    static std::vector<const ResourceType*> getAllResources();

    /// [AI: PURPOSE] Загрузить ресурсы из конфигурационного файла.
    static bool loadFromFile(const std::string& filename);

private:
    static std::unordered_map<IIdentifiable::IdType, ResourceType> resourceMap_;
    static std::unordered_map<std::string, IIdentifiable::IdType> nameToIdMap_;

    /// [AI: DESIGN] Запрещаем создание экземпляров.
    ResourceRegistry() = delete;
};
