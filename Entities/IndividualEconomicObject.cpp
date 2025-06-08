#include "IndividualEconomicObject.h"
#include "../World/GroupEconomicObject.h"

void IndividualEconomicObject::unregister() {
    if (registry_) {
        registry_->removeStepable(this->getId());
        registry_ = nullptr;
    }
}

void IndividualEconomicObject::performStep(uint64_t /*currentStep*/) {
    // [AI: NOTE] Поведение индивидуального агента пока не определено.
}
