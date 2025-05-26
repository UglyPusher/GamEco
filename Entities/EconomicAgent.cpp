#include "EconomicAgent.h"

int EconomicAgent::idCounter_ = 0;

EconomicAgent::EconomicAgent() : id_(++idCounter_) {}

int EconomicAgent::getId() const {
    return id_;
}

void EconomicAgent::addChild(const Ptr& child) {
    if (child && std::find(children_.begin(), children_.end(), child) == children_.end()) {
        children_.push_back(child);
    }
}

void EconomicAgent::removeChild(const Ptr& child) {
    auto it = std::find(children_.begin(), children_.end(), child);
    if (it != children_.end()) {
        children_.erase(it);
    }
}

const std::vector<EconomicAgent::Ptr>& EconomicAgent::getChildren() const {
    return children_;
}

void EconomicAgent::step() {
    for (auto it = children_.begin(); it != children_.end(); ++it) {
        if (*it) {
            (*it)->step();
        }
    }
}
