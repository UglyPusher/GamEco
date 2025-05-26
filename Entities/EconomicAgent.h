#pragma once

#include <vector>
#include <memory>
#include <algorithm> // std::find
#include "IEconomicAgent.h"

class EconomicAgent : public IEconomicAgent {
public:
    using Ptr = std::shared_ptr<IEconomicAgent>;

    EconomicAgent();
    virtual ~EconomicAgent() = default;

    virtual int getId() const override;

    virtual void addChild(const Ptr& child) override;
    virtual void removeChild(const Ptr& child) override;
    virtual const std::vector<Ptr>& getChildren() const override;

    virtual void step() override;

protected:
    int id_;
    std::vector<Ptr> children_;

private:
    static int idCounter_;
};
