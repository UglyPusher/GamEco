#include "BaseEconomicAgent.h"
#include "../World/GroupEconomicObject.h"  // предполагается

#include <algorithm>
#include <stdexcept>

void BaseEconomicAgent::registerTo(GroupEconomicObject* group) {
    if (!group) {
        throw std::invalid_argument("[BaseEconomicAgent] Cannot register to null group.");
    }

    if (registry_) {
        registry_->removeStepable(this->getId());
    }

    registry_ = group;
    registry_->addStepable(shared_from_this());
}

GroupEconomicObject* BaseEconomicAgent::getRegistry() const {
    return registry_;
}

const std::unordered_map<const ResourceType*, uint64_t>& BaseEconomicAgent::getResources() const {
    return resources_;
}

uint64_t BaseEconomicAgent::addResource(const ResourceType& type, uint64_t amount) {
    uint64_t perUnit = type.getVolume();
    uint64_t availableVolume = getFreeVolume();
    uint64_t maxUnitsFit = (perUnit > 0) ? (availableVolume / perUnit) : amount;
    uint64_t toAdd = std::min(amount, maxUnitsFit);
    resources_[&type] += toAdd;
    return toAdd;
}

uint64_t BaseEconomicAgent::consumeResource(const ResourceType& type, uint64_t amount) {
    const ResourceType* key = &type;
    uint64_t available = resources_[key];
    uint64_t toTake = std::min(amount, available);
    resources_[key] -= toTake;
    return toTake;
}

void BaseEconomicAgent::setTotalCapacity(uint64_t maxVolume) {
    capacityLimit_ = maxVolume;
    uint64_t total = 0;
    for (auto& pair : resources_) {
        uint64_t vol = pair.first->getVolume();
        uint64_t maxAllowed = (vol > 0) ? (capacityLimit_ - total) / vol : pair.second;
        if (pair.second > maxAllowed) {
            pair.second = maxAllowed;
        }
        total += pair.second * vol;
        if (total >= capacityLimit_) break;
    }
}

uint64_t BaseEconomicAgent::getFreeVolume() const {
    uint64_t used = 0;
    for (const auto& pair : resources_) {
        used += pair.second * pair.first->getVolume();
    }
    return (used < capacityLimit_) ? (capacityLimit_ - used) : 0;
}

void BaseEconomicAgent::clearResources() {
    resources_.clear();
}
