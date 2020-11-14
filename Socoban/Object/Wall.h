// ☕ Привет
#pragma once

#include "EventGameEngine/FieldData/FieldObjectWithPos.h"
#include "EventGameEngine/EventData/GlobalEventPusher.h"

using namespace EventGameEngine;

namespace Socoban
{
	namespace Object
	{
		class Wall : public FieldData::FieldObject
		{
		public:
			Wall()
				: FieldData::FieldObject(219)
			{}
		};
	}
}