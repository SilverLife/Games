// ☕ Привет
#pragma once

#include "EventGameEngine/FieldData/FieldObjectWithPos.h"
#include "EventGameEngine/EventData/GlobalEventPusher.h"
#include "Player.h"
#include "BlockPlaceholder.h"

using namespace EventGameEngine;

namespace Socoban
{
	namespace Object
	{
		class Block : public FieldData::FieldObject
		{
		public:
			Block()
				: FieldData::FieldObject(177, Shared::ConsoleHelper::Color::LightGreen)
			{}

			int OnPassiveIntersect(Point active_pos, Point passive_pos, FieldData::FieldObject* intersected_object) override
			{
				if (dynamic_cast<Player*>(intersected_object) != nullptr)
				{
					const auto delta = -(active_pos - passive_pos);

					EventData::PushEvent(new EventData::EventMoveObject(passive_pos, passive_pos + delta));
					EventData::PushEvent(new EventData::EventMoveObject(active_pos, passive_pos));
				}
				return 0;
			}

			int OnActiveIntersect(Point active_pos, Point passive_pos, FieldObject* intersected_object) override 
			{
				const auto block_placeholder = dynamic_cast<BlockPlaceholder*>(intersected_object);
				if (block_placeholder != nullptr && !block_placeholder->IsBlockHere())
				{
					return FieldData::IntersectResult::IntResIsDead;
				}
				return 0; 
			}

		};
	}
}