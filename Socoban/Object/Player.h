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

			//void OnRemove() override
			//{
			//}
			//
			//void OnTick(int tick_num) override
			//{
			//}
			//
			//int OnActiveIntersect(FieldObject* intersected_object) override
			//{
			//}
			//
			//int OnPassiveIntersect(FieldObject* intersected_object) override
			//{
			//}
		};
	}
}