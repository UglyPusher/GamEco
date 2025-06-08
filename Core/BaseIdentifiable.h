#pragma once

#include "IIdentifiable.h"
#include <atomic>
#include <cstdint>

/// [AI: PURPOSE] ������� ���������� IIdentifiable � ��������������� ��������������.
/// [AI: DESIGN] ���������� std::atomic ��� ����������������� ���������� ID (���� ���� ��������� ������������).
class BaseIdentifiable : public IIdentifiable {
public:
    /// [AI: USAGE] ��������� ����� ���������� ID ��� ��������.
    BaseIdentifiable() : id(nextId()) {}

    /// [AI: USAGE] ������������ ��� �������������� ������� � ��� ������������ ID.
    explicit BaseIdentifiable(IdType existingId) : id(existingId) {
        updateCounter(existingId);
    }

    /// [AI: PURPOSE] ���������� ���������� ID �������.
    IdType getId() const override {
        return id;
    }

protected:
    /// [AI: STATE_FIELD] ������������� �������.
    IdType id;

private:
    /// [AI: STATE_FIELD] ���������� ������� ID.
    static std::atomic<IdType> counter;

    /// [AI: DESIGN] ����� ����� ID, ���������� �������.
    static IdType nextId() {
        return ++counter;
    }

    /// [AI: DESIGN] ��������� �������, ���� ID ���� �������� �������� (��� �������������� �� ������).
    static void updateCounter(IdType val) {
        IdType cur = counter.load();
        while (val > cur && !counter.compare_exchange_weak(cur, val)) {
            // loop until updated
        }
    }
};
