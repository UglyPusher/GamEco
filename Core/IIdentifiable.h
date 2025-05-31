#pragma once

#include <cstdint>

/**
 * ��������� �������, ����������� ���������� ���������������.
 */
class IIdentifiable {
public:
    using IdType = int64_t;

    virtual ~IIdentifiable() = default;

    /**
     * �������� ���������� ������������� �������.
     */
    virtual IdType getId() const = 0;
};
