#pragma once

#include "IIdentifiable.h"

/**
 * ��������� �������, ������������ � ��������� ���������.
 * ��� ������� IStepable ����� �������� �����������������.
 */
class IStepable : public IIdentifiable {
public:
    virtual ~IStepable() = default;

    /**
     * �����, ���������� �� ������ ���� ���������.
     */
    virtual void step() = 0;
};
