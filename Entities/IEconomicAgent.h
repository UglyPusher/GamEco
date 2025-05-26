#pragma once

#include <vector>
#include <memory>

class IEconomicAgent {
public:
    using Ptr = std::shared_ptr<IEconomicAgent>;

    virtual ~IEconomicAgent() = default;

    virtual int getId() const = 0;

    virtual void addChild(const Ptr& child) = 0;
    virtual void removeChild(const Ptr& child) = 0;
    virtual const std::vector<Ptr>& getChildren() const = 0;

    virtual void step() = 0;
};
