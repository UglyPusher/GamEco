#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

class IEconomicAgent;

class IGlobalEconomyManager {
public:
    using Ptr = std::shared_ptr<IGlobalEconomyManager>;

    virtual ~IGlobalEconomyManager() = default;

    // �������� �������������� ������ (������������)
    virtual void addStaticAgent(const std::shared_ptr<IEconomicAgent>& agent) = 0;

    // ������� �������������� ������ (������������) �� ID
    virtual void removeStaticAgent(int id) = 0;

    // �������� �������������� ������ (������������) �� ID
    virtual std::shared_ptr<IEconomicAgent> getStaticAgent(int id) const = 0;

    // �������� ���� ����������� �������
    virtual std::vector<std::shared_ptr<IEconomicAgent>> getAllStaticAgents() const = 0;

    // �������� ���������� �������������� ������ (�������/�����)
    virtual void addMobileAgent(const std::shared_ptr<IEconomicAgent>& agent) = 0;

    // ������� ���������� ������ �� ID
    virtual void removeMobileAgent(int id) = 0;

    // �������� ���������� ������ �� ID
    virtual std::shared_ptr<IEconomicAgent> getMobileAgent(int id) const = 0;

    // �������� ���� ��������� �������
    virtual std::vector<std::shared_ptr<IEconomicAgent>> getAllMobileAgents() const = 0;
};
