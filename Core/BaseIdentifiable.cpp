#include "BaseIdentifiable.h"

/// [AI: INIT] ������������� ����������� �������� ID.
std::atomic<IIdentifiable::IdType> BaseIdentifiable::counter{ 0 };
