#pragma once

#include <cstdint>
#include <memory>

/// [AI: PURPOSE] Интерфейс для объектов, выполняющих шаг симуляции.
/// [AI: USAGE] Используется в системах пошагового обновления. Не содержит требований к идентификации.
class IStepable {
public:
    using Ptr = std::shared_ptr<IStepable>;

    virtual ~IStepable() = default;

    /// [AI: PURPOSE] Выполнить симуляционный шаг для текущего времени.
    /// [AI: USAGE] Вызывается один раз за шаг симуляции извне.
    virtual void step(uint64_t currentStep) = 0;
};
