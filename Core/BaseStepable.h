#pragma once

#include "IStepable.h"
#include "BaseIdentifiable.h"
#include <vector>
#include <memory>
#include <random>
#include <algorithm>

class BaseStepable : public IStepable, public BaseIdentifiable {
public:
    using Ptr = std::shared_ptr<BaseStepable>;

    BaseStepable() = default;

    static void initializeRng(unsigned seed = std::random_device{}());

    void addStepable(const std::shared_ptr<IStepable>& obj);
    void removeStepable(int64_t id);

    void step() override;

protected:
    std::vector<std::shared_ptr<IStepable>> stepables;

private:
    static std::mt19937 rng;
};
