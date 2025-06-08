#pragma once

#include "BaseEconomicAgent.h"
#include <memory>

/// [AI: PURPOSE] ��������� ������������� ������: ����, �������������, �����.
/// [AI: DESIGN] ������ ����������� ��� ������ �������. ����� ���� ������ �� �����������.
/// �� ����� ���� ��������������� ��� (���� �� �������������� ����).
class GroupEconomicObject : public BaseEconomicAgent {
public:
    GroupEconomicObject() = default;
    virtual ~GroupEconomicObject() = default;

    /// [AI: PURPOSE] ��������������� �������� ������. ��������� ������ �� ����� ���� ���������������.
    void registerTo(GroupEconomicObject* group) override;

protected:
    /// [AI: OVERRIDE_POINT] ��������� ���������� ������� �� ���� ���������.
    void performStep(uint64_t currentStep) override;
};
