#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

class IEconomicAgent;

class IGlobalEconomyManager {
public:
    using Ptr = std::shared_ptr<IGlobalEconomyManager>;

    virtual ~IGlobalEconomyManager() = default;

    // Добавить экономического агента (статического)
    virtual void addStaticAgent(const std::shared_ptr<IEconomicAgent>& agent) = 0;

    // Удалить экономического агента (статического) по ID
    virtual void removeStaticAgent(int id) = 0;

    // Получить экономического агента (статического) по ID
    virtual std::shared_ptr<IEconomicAgent> getStaticAgent(int id) const = 0;

    // Получить всех статических агентов
    virtual std::vector<std::shared_ptr<IEconomicAgent>> getAllStaticAgents() const = 0;

    // Добавить мобильного экономического агента (караван/банда)
    virtual void addMobileAgent(const std::shared_ptr<IEconomicAgent>& agent) = 0;

    // Удалить мобильного агента по ID
    virtual void removeMobileAgent(int id) = 0;

    // Получить мобильного агента по ID
    virtual std::shared_ptr<IEconomicAgent> getMobileAgent(int id) const = 0;

    // Получить всех мобильных агентов
    virtual std::vector<std::shared_ptr<IEconomicAgent>> getAllMobileAgents() const = 0;
};
