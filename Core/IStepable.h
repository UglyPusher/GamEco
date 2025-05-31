#pragma once

#include "IIdentifiable.h"

/**
 * »нтерфейс объекта, участвующего в пошаговой симул€ции.
 * ¬се объекты IStepable также €вл€ютс€ идентифицируемыми.
 */
class IStepable : public IIdentifiable {
public:
    virtual ~IStepable() = default;

    /**
     * ћетод, вызываемый на каждом шаге симул€ции.
     */
    virtual void step() = 0;
};
