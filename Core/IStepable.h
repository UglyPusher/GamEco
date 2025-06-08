#pragma once

#include <cstdint>
#include <memory>

/// [AI: PURPOSE] ��������� ��� ��������, ����������� ��� ���������.
/// [AI: USAGE] ������������ � �������� ���������� ����������. �� �������� ���������� � �������������.
class IStepable {
public:
    using Ptr = std::shared_ptr<IStepable>;

    virtual ~IStepable() = default;

    /// [AI: PURPOSE] ��������� ������������� ��� ��� �������� �������.
    /// [AI: USAGE] ���������� ���� ��� �� ��� ��������� �����.
    virtual void step(uint64_t currentStep) = 0;
};
