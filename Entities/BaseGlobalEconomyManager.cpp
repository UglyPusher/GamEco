#include "BaseGlobalEconomyManager.h"
#include "MobileEconomicEntity.h"

void BaseGlobalEconomyManager::registerMobileEntity(std::shared_ptr<MobileEconomicEntity> entity) {
	mobileEntities.emplace_back(std::move(entity));
}

void BaseGlobalEconomyManager::step() {
	// Можно добавить перемешивание порядка, если требуется избежать приоритета
	for (auto& entity : mobileEntities) {
		if (entity) {
			entity->step();
		}
	}
}
