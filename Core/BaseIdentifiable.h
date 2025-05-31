#pragma once

#include "IIdentifiable.h"
#include <atomic>
#include <cstdint>

class BaseIdentifiable : public IIdentifiable {
public:
    BaseIdentifiable() : id(nextId()) {}
    explicit BaseIdentifiable(int64_t existingId) : id(existingId) {
        updateCounter(existingId);
    }

    int64_t getId() const override {
        return id;
    }

protected:
    int64_t id;

private:
    static std::atomic<int64_t> counter;

    static int64_t nextId() {
        return ++counter;
    }

    static void updateCounter(int64_t val) {
        int64_t cur = counter.load();
        while (val > cur && !counter.compare_exchange_weak(cur, val)) {
            // loop until updated
        }
    }
};

// Инициализация статического члена
//std::atomic<int64_t> BaseIdentifiable::counter{ 0 };
