#pragma once

#include <cstdint>

/// [AI: PURPOSE] ��������� ��� ��������, ���������� ���������� �������� ���������������.
/// [AI: USAGE] ����������� ����� ���������� ���������, ���������� ������������ � �����.
class IIdentifiable {
public:
    using IdType = uint64_t;

    virtual ~IIdentifiable() = default;

    /// [AI: PURPOSE] �������� ���������� ������������� �������.
    virtual IdType getId() const = 0;
};
