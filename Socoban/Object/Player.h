// ☕ Привет
#pragma once

#include "EventGameEngine/FieldData/FieldObjectWithPos.h"
#include "EventGameEngine/EventData/GlobalEventPusher.h"

using namespace EventGameEngine;

namespace Socoban
{
	namespace Object
	{
		class Player : public FieldData::FieldObjectWithPos
		{
		public:
			Player(Point pos)
				: FieldData::FieldObjectWithPos(pos, '#', Shared::ConsoleHelper::Color::Yellow)
			{}
		};
	}
}