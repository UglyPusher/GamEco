#pragma once

#include "BaseEconomicAgent.h"

/// [AI: PURPOSE] �������������� ������������� ������: �������, NPC, ��������.
/// [AI: DESIGN] ����� ���������������� � �������� ����������� � �������.
/// ����� �������� ��������, ������, ���������� (� ������� �������).
class IndividualEconomicObject : public BaseEconomicAgent {
public:
    IndividualEconomicObject() = default;
    virtual ~IndividualEconomicObject() = default;

    /// [AI: PURPOSE] �������� ����������� � ������� ������.
    void unregister();

protected:
    /// [AI: OVERRIDE_POINT] ��������� ������ �� ���� ��������� (����� ��������� �����).
    void performStep(uint64_t currentStep) override;
};
