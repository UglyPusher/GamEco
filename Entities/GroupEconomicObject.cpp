#include "GroupEconomicObject.h"
#include <stdexcept>

void GroupEconomicObject::registerTo(GroupEconomicObject* /*group*/) {
    throw std::logic_error("[GroupEconomicObject] Cannot be registered in another group.");
}

void GroupEconomicObject::performStep(uint64_t /*currentStep*/) {
    // [AI: OVERRIDE_POINT] ��������� ����� ����� ��������� ���������� stepables_
    // ��������: Settlement ����� ��������� �����, ������� ������ � �.�.

    stepChildren();
}
