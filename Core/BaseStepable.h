#pragma once

#include "IStepable.h"
#include "BaseIdentifiable.h"

#include <unordered_map>
#include <memory>
#include <random>
#include <algorithm>

/// [AI: PURPOSE] ������� ����� ��� ��������, ���������� ID � ����������� � ���������.
/// [AI: DESIGN] ���������� IIdentifiable � IStepable. ��������� ��������� IStepable-���������.
class BaseStepable : public IStepable, public BaseIdentifiable {
public:
    using Ptr = std::shared_ptr<BaseStepable>;

    BaseStepable() = default;

    /// [AI: RNG_INIT] ������������� seed ��� ����������� ���������� ��������� �����.
    static void initializeRng(unsigned seed = std::random_device{}());

    /// [AI: AGGREGATION] ��������� �������� stepable-������.
    void addStepable(const std::shared_ptr<IStepable>& obj, IdType id);

    /// [AI: AGGREGATION] ������� �������� stepable-������ �� ID.
    void removeStepable(IdType id);

    /// [AI: STEP_METHOD] ��������� ������������� ���, ������� ��������.
    void step(uint64_t currentStep) override;

protected:
    /// [AI: CONTAINER] ��������� �������� �������� �� ID.
    std::unordered_map<IdType, std::shared_ptr<IStepable>> stepables;

    /// [AI: STATE_FIELD] ��������� ���, ��� ������������ ���� ��������.
    uint64_t lastProcessedStep = static_cast<uint64_t>(-1);

    /// [AI: OVERRIDE_POINT] �����, ���������������� ��� ���������� ������ ����.
    virtual void performStep(uint64_t currentStep) = 0;

private:
    /// [AI: RNG_ENGINE] ��������� ��������� ����� ��� ������������� ������� ������ ��������.
    static std::mt19937 rng;
};
