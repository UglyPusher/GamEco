#pragma once

#include "../Core/BaseStepable.h"
#include "../Resources/ResourceType.h"

#include <unordered_map>

/// [AI: PURPOSE] Базовый экономический агент с ограниченным по объёму хранилищем ресурсов.
/// [AI: DESIGN] Использует BaseStepable для механики симуляции и добавляет бизнес-логику: ресурсы, объём, производство.
class BaseEconomicAgent : public BaseStepable {
public:
    virtual ~BaseEconomicAgent() = default;

    /// [AI: PURPOSE] Получить текущее количество ресурсов.
    const std::unordered_map<const ResourceType*, uint64_t>& getResources() const;

    /// [AI: PURPOSE] Добавить ресурсы (с учётом объёма). Возвращает фактически добавленное.
    uint64_t addResource(const ResourceType& type, uint64_t amount);

    /// [AI: PURPOSE] Изъять ресурсы (если хватает). Возвращает фактически изъятое.
    uint64_t consumeResource(const ResourceType& type, uint64_t amount);

    /// [AI: PURPOSE] Установить общий лимит хранилища (в объёмных единицах).
    void setTotalCapacity(uint64_t maxVolume);

    /// [AI: PURPOSE] Получить доступный объём хранилища.
    uint64_t getFreeVolume() const;

    /// [AI: PURPOSE] Полностью очистить содержимое ресурсов.
    void clearResources();

protected:
    /// [AI: OVERRIDE_POINT] Реализация логики агента на шаге симуляции.
    virtual void performStep(uint64_t currentStep) override = 0;

    std::unordered_map<const ResourceType*, uint64_t> resources_;
    uint64_t capacityLimit_ = 0;
};
