// ☕ Привет
#pragma once

#include "EventGameEngine/FieldData/FieldObjectWithPos.h"
#include "EventGameEngine/EventData/GlobalEventPusher.h"
#include "Player.h"

using namespace EventGameEngine;

namespace Socoban
{
	namespace Object
	{
		class Block : public FieldData::FieldObject
		{
		public:
			Block()
				: FieldData::FieldObject(177)
			{}

			virtual int OnPassiveIntersect(Point active_pos, Point passive_pos, FieldData::FieldObject* intersected_object)
			{
				if (dynamic_cast<Player*>(intersected_object) != nullptr)
				{
					const auto delta = -(active_pos - passive_pos);

					EventData::PushEvent(new EventData::EventMoveObject(passive_pos, passive_pos + delta));
					EventData::PushEvent(new EventData::EventMoveObject(active_pos, passive_pos));
				}
				return 0;
			}
		};
	}
}