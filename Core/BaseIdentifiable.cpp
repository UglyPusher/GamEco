#include "BaseIdentifiable.h"

/// [AI: INIT] Инициализация глобального счётчика ID.
std::atomic<IIdentifiable::IdType> BaseIdentifiable::counter{ 0 };
