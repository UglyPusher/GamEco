#pragma once

#include <cstdint>

/**
 * Интерфейс объекта, обладающего уникальным идентификатором.
 */
class IIdentifiable {
public:
    using IdType = int64_t;

    virtual ~IIdentifiable() = default;

    /**
     * Получить уникальный идентификатор объекта.
     */
    virtual IdType getId() const = 0;
};
