#include "BaseStepable.h"

std::mt19937 BaseStepable::rng;

/// [AI: RNG_INIT_IMPL] ��������� ����������� seed.
void BaseStepable::initializeRng(unsigned seed) {
    rng.seed(seed);
}

/// [AI: AGGREGATION_IMPL] ���������� stepable-������� �� ID.
void BaseStepable::addStepable(const std::shared_ptr<IStepable>& obj, IdType id) {
    if (obj) {
        stepables[id] = obj;
    }
}

/// [AI: AGGREGATION_IMPL] �������� ������� �� ID.
void BaseStepable::removeStepable(IdType id) {
    stepables.erase(id);
}

/// [AI: STEP_IMPL] ���������� ����: ���� ��� �� ������� ���, + �������.
void BaseStepable::step(uint64_t currentStep) {
    if (currentStep <= lastProcessedStep) return;

    lastProcessedStep = currentStep;

    std::vector<std::shared_ptr<IStepable>> shuffled;
    for (const auto& kv : stepables) {
        if (kv.second) shuffled.push_back(kv.second);
    }

    std::shuffle(shuffled.begin(), shuffled.end(), rng);

    for (const auto& s : shuffled) {
        s->step(currentStep);
    }

    performStep(currentStep);
}
