#pragma once

#include "IIdentifiable.h"
#include <atomic>
#include <cstdint>

/// [AI: PURPOSE] Базовая реализация IIdentifiable с автоинкрементом идентификатора.
/// [AI: DESIGN] Использует std::atomic для потокобезопасного назначения ID (даже если симуляция однопоточная).
class BaseIdentifiable : public IIdentifiable {
public:
    /// [AI: USAGE] Назначает новый уникальный ID при создании.
    BaseIdentifiable() : id(nextId()) {}

    /// [AI: USAGE] Используется при восстановлении объекта с уже существующим ID.
    explicit BaseIdentifiable(IdType existingId) : id(existingId) {
        updateCounter(existingId);
    }

    /// [AI: PURPOSE] Возвращает уникальный ID объекта.
    IdType getId() const override {
        return id;
    }

protected:
    /// [AI: STATE_FIELD] Идентификатор объекта.
    IdType id;

private:
    /// [AI: STATE_FIELD] Глобальный счётчик ID.
    static std::atomic<IdType> counter;

    /// [AI: DESIGN] Выдаёт новый ID, увеличивая счётчик.
    static IdType nextId() {
        return ++counter;
    }

    /// [AI: DESIGN] Обновляет счётчик, если ID выше текущего значения (для восстановления из данных).
    static void updateCounter(IdType val) {
        IdType cur = counter.load();
        while (val > cur && !counter.compare_exchange_weak(cur, val)) {
            // loop until updated
        }
    }
};
