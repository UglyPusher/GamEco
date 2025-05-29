#pragma once

#include "IGlobalEconomyManager.h"
#include <vector>
#include <memory>

class MobileEconomicEntity;

class BaseGlobalEconomyManager : public IGlobalEconomyManager {
public:
	virtual ~BaseGlobalEconomyManager() = default;

	// ������������ ��������� ������������� ������ (�������, ����� � �.�.)
	virtual void registerMobileEntity(std::shared_ptr<MobileEconomicEntity> entity);

	// ��������� ��� ���������: ��������� ��� ��������� �������
	void step() override;

protected:
	std::vector<std::shared_ptr<MobileEconomicEntity>> mobileEntities;
};
