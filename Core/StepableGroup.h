#pragma once

#include "IStepable.h"
#include <vector>
#include <memory>
#include <random>
#include <cstdint>

/**
 * ��������� ������� ��������, ���������� step() � ������� �������� � ��������� �������.
 */
class StepableGroup : public IStepable {
public:
    using Ptr = std::shared_ptr<StepableGroup>;

    StepableGroup();

    // ������������� ������ ��� (����������)
    static void initializeRng(unsigned seed = std::random_device{}());

    void addStepable(const std::shared_ptr<IStepable>& stepable);
    void removeStepable(int64_t id);

    const std::vector<std::shared_ptr<IStepable>>& getMembers() const;

    void step() override;
    int64_t getId() const override;

private:
    std::vector<std::shared_ptr<IStepable>> members;
    int64_t id;

    static std::mt19937& rng();
    static int64_t generateId();
};
