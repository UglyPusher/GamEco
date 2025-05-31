#include "StepableGroup.h"
#include <algorithm>
#include <atomic>

StepableGroup::StepableGroup() : id(generateId()) {}

void StepableGroup::initializeRng(unsigned seed) {
    rng().seed(seed);
}

void StepableGroup::addStepable(const std::shared_ptr<IStepable>& stepable) {
    members.push_back(stepable);
}

void StepableGroup::removeStepable(int64_t targetId) {
    members.erase(
        std::remove_if(members.begin(), members.end(),
            [targetId](const std::shared_ptr<IStepable>& obj) {
                return obj && obj->getId() == targetId;
            }),
        members.end()
    );
}

const std::vector<std::shared_ptr<IStepable>>& StepableGroup::getMembers() const {
    return members;
}

void StepableGroup::step() {
    std::shuffle(members.begin(), members.end(), rng());

    for (const auto& stepable : members) {
        if (stepable) {
            stepable->step();
        }
    }
}

int64_t StepableGroup::getId() const {
    return id;
}

int64_t StepableGroup::generateId() {
    static std::atomic<int64_t> counter{ 1 };
    return counter++;
}

std::mt19937& StepableGroup::rng() {
    static std::mt19937 instance(std::random_device{}());
    return instance;
}
