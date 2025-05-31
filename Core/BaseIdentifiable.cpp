#include "BaseIdentifiable.h"

std::atomic<IIdentifiable::IdType> BaseIdentifiable::counter{ 0 };