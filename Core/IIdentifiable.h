#pragma once

#include <cstdint>

/// [AI: PURPOSE] Интерфейс для объектов, обладающих уникальным числовым идентификатором.
/// [AI: USAGE] Реализуется всеми сущностями симуляции, требующими отслеживания и учёта.
class IIdentifiable {
public:
    using IdType = uint64_t;

    virtual ~IIdentifiable() = default;

    /// [AI: PURPOSE] Получить уникальный идентификатор объекта.
    virtual IdType getId() const = 0;
};
