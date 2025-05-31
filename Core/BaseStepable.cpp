#include "BaseStepable.h"
#include "IIdentifiable.h"

std::mt19937 BaseStepable::rng;

void BaseStepable::initializeRng(unsigned seed) {
    rng.seed(seed);
}

void BaseStepable::addStepable(const std::shared_ptr<IStepable>& obj) {
    stepables.push_back(obj);
}

void BaseStepable::removeStepable(int64_t id) {
    stepables.erase(
        std::remove_if(stepables.begin(), stepables.end(),
            [id](const std::shared_ptr<IStepable>& obj) {
                auto identifiable = std::dynamic_pointer_cast<IIdentifiable>(obj);
                return identifiable && identifiable->getId() == id;
            }),
        stepables.end()
    );
}

void BaseStepable::step() {
    std::shuffle(stepables.begin(), stepables.end(), rng);
    for (auto& obj : stepables) {
        obj->step();
    }
}
