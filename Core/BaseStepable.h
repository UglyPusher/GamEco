#pragma once

#include "IStepable.h"
#include "BaseIdentifiable.h"

#include <unordered_map>
#include <memory>
#include <random>
#include <algorithm>

/// [AI: PURPOSE] Базовый класс для объектов, обладающих ID и участвующих в симуляции.
/// [AI: DESIGN] Объединяет IIdentifiable и IStepable. Управляет дочерними IStepable-объектами.
class BaseStepable : public IStepable, public BaseIdentifiable {
public:
    using Ptr = std::shared_ptr<BaseStepable>;

    BaseStepable() = default;

    /// [AI: RNG_INIT] Устанавливает seed для глобального генератора случайных чисел.
    static void initializeRng(unsigned seed = std::random_device{}());

    /// [AI: AGGREGATION] Добавляет дочерний stepable-объект.
    void addStepable(const std::shared_ptr<IStepable>& obj, IdType id);

    /// [AI: AGGREGATION] Удаляет дочерний stepable-объект по ID.
    void removeStepable(IdType id);

    /// [AI: STEP_METHOD] Выполняет симуляционный шаг, включая потомков.
    void step(uint64_t currentStep) override;

protected:
    /// [AI: CONTAINER] Хранилище дочерних объектов по ID.
    std::unordered_map<IdType, std::shared_ptr<IStepable>> stepables;

    /// [AI: STATE_FIELD] Последний шаг, уже обработанный этим объектом.
    uint64_t lastProcessedStep = static_cast<uint64_t>(-1);

    /// [AI: OVERRIDE_POINT] Метод, переопределяемый для реализации логики шага.
    virtual void performStep(uint64_t currentStep) = 0;

private:
    /// [AI: RNG_ENGINE] Генератор случайных чисел для перемешивания порядка обхода потомков.
    static std::mt19937 rng;
};
