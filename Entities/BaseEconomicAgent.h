#pragma once

#include "../Core/BaseStepable.h"
#include "../Resources/ResourceType.h"

#include <unordered_map>

/// [AI: PURPOSE] ������� ������������� ����� � ������������ �� ������ ���������� ��������.
/// [AI: DESIGN] ���������� BaseStepable ��� �������� ��������� � ��������� ������-������: �������, �����, ������������.
class BaseEconomicAgent : public BaseStepable {
public:
    virtual ~BaseEconomicAgent() = default;

    /// [AI: PURPOSE] �������� ������� ���������� ��������.
    const std::unordered_map<const ResourceType*, uint64_t>& getResources() const;

    /// [AI: PURPOSE] �������� ������� (� ������ ������). ���������� ���������� �����������.
    uint64_t addResource(const ResourceType& type, uint64_t amount);

    /// [AI: PURPOSE] ������ ������� (���� �������). ���������� ���������� �������.
    uint64_t consumeResource(const ResourceType& type, uint64_t amount);

    /// [AI: PURPOSE] ���������� ����� ����� ��������� (� �������� ��������).
    void setTotalCapacity(uint64_t maxVolume);

    /// [AI: PURPOSE] �������� ��������� ����� ���������.
    uint64_t getFreeVolume() const;

    /// [AI: PURPOSE] ��������� �������� ���������� ��������.
    void clearResources();

protected:
    /// [AI: OVERRIDE_POINT] ���������� ������ ������ �� ���� ���������.
    virtual void performStep(uint64_t currentStep) override = 0;

    std::unordered_map<const ResourceType*, uint64_t> resources_;
    uint64_t capacityLimit_ = 0;
};
