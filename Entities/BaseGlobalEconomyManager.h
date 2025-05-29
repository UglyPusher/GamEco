#pragma once

#include "IGlobalEconomyManager.h"
#include <vector>
#include <memory>

class MobileEconomicEntity;

class BaseGlobalEconomyManager : public IGlobalEconomyManager {
public:
	virtual ~BaseGlobalEconomyManager() = default;

	// Регистрирует подвижный экономический объект (караван, банда и т.д.)
	virtual void registerMobileEntity(std::shared_ptr<MobileEconomicEntity> entity);

	// Выполняет шаг симуляции: обновляет все подвижные объекты
	void step() override;

protected:
	std::vector<std::shared_ptr<MobileEconomicEntity>> mobileEntities;
};
