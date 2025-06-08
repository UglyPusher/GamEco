#pragma once

#include "BaseEconomicAgent.h"
#include <memory>

/// [AI: PURPOSE] Групповой экономический объект: село, муниципалитет, отряд.
/// [AI: DESIGN] Служит контейнером для других агентов. Может быть местом их регистрации.
/// Не может быть зарегистрирован сам (если не переопределено явно).
class GroupEconomicObject : public BaseEconomicAgent {
public:
    GroupEconomicObject() = default;
    virtual ~GroupEconomicObject() = default;

    /// [AI: PURPOSE] Переопределение базового метода. Групповой объект не может быть зарегистрирован.
    void registerTo(GroupEconomicObject* group) override;

protected:
    /// [AI: OVERRIDE_POINT] Поведение группового объекта на шаге симуляции.
    void performStep(uint64_t currentStep) override;
};
