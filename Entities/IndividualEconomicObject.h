#pragma once

#include "BaseEconomicAgent.h"

/// [AI: PURPOSE] Индивидуальный экономический объект: человек, NPC, персонаж.
/// [AI: DESIGN] Может регистрироваться и отменять регистрацию в группах.
/// Может обладать навыками, семьёй, профессией (в будущих версиях).
class IndividualEconomicObject : public BaseEconomicAgent {
public:
    IndividualEconomicObject() = default;
    virtual ~IndividualEconomicObject() = default;

    /// [AI: PURPOSE] Отменить регистрацию в текущей группе.
    void unregister();

protected:
    /// [AI: OVERRIDE_POINT] Поведение агента на шаге симуляции (будет расширено позже).
    void performStep(uint64_t currentStep) override;
};
