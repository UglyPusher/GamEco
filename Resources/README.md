# 🌍 Game Economic Simulation Framework

Симуляция экономики внутри игрового мира с поселениями, агентами, торговыми маршрутами, биржами и производством ресурсов.

---

## 🧱 Архитектура

```mermaid
classDiagram
    class ResourceType {
        -int id
        -string name
        -unordered_map~int, int~ componentResourceQuantities
        +string getName()
    }

    class ResourceRegistry {
        -unordered_map~string, ResourceType~ resources
        +ResourceType& createResource(string name)
        +ResourceType& getResourceByName(string name)
    }

    class EconomicEntity {
        -unordered_map~int, int~ storage
        +void addResource(ResourceType, int)
        +bool removeResource(ResourceType, int)
    }

    class BehavioralEconomicEntity {
        -unique_ptr~Behavior~ behavior
        +void step()
    }

    class CaravanEntity {
        -vector~Worker~ workers
        -Route route
        +void load(ResourceType, int)
        +void unload(ResourceType, int)
    }

    class StockExchange {
        -unordered_map~int, StockOrderBook~ orderBooks
        +void placeOrder(StockOrder)
        +void matchOrders()
    }

    class StockOrder {
        -int orderId
        -int entityId
        -bool isBuy
        -int quantity
        -double price
    }

    class StockOrderBook {
        -priority_queue~StockOrder~ buyOrders
        -priority_queue~StockOrder~ sellOrders
        +void match()
    }

    class StockTransaction {
        -int buyerId
        -int sellerId
        -int resourceId
        -int quantity
        -double price
    }
    +
    class GlobalEconomyManager {
        -vector~Ptr~ staticAgents
        -vector~Ptr~ mobileAgents
        +void addStaticAgent(...)
        +void addMobileAgent(...)
    }

    EconomicEntity <|-- BehavioralEconomicEntity
    BehavioralEconomicEntity <|-- CaravanEntity
    BehavioralEconomicEntity <|-- VillageEntity
    CaravanEntity --> StockExchange
    VillageEntity --> StockExchange
