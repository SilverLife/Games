// ☕ Привет
#pragma once

#include "BlockPlaceholder.h"
#include "Block.h"
#include "Player.h"
#include "../GameData/CustomEvents.h"
using namespace EventGameEngine;

namespace Socoban
{
	namespace Object
	{
		void BlockPlaceholder::OnDraw(Point point_to_draw)
		{
			const auto color = _is_block_here ? Shared::ConsoleHelper::Color::LightBlue : Shared::ConsoleHelper::Color::LightCyan;
			Shared::ConsoleHelper::Console().Print(point_to_draw, kSymbol, color);
		}

		int BlockPlaceholder::OnPassiveIntersect(Point active_pos, Point passive_pos, FieldData::FieldObject* intersected_object)
		{
			if (dynamic_cast<Block*>(intersected_object) != nullptr)
			{
				_is_block_here = true;
				OnDraw(passive_pos);
				EventData::PushEvent(new EventData::Event(CustomEventType::PlaceholderFilled, EventData::EventGroup::Custom));
			}
			else if (dynamic_cast<Player*>(intersected_object) != nullptr && _is_block_here)
			{
				const auto delta = -(active_pos - passive_pos);

				EventData::PushEvent(new EventData::EventAddObject(passive_pos + delta, new Block));
				_is_block_here = false;
				OnDraw(passive_pos);
				EventData::PushEvent(new EventData::Event(CustomEventType::PlaceholderUnfilled, EventData::EventGroup::Custom));
			}
			return 0;
		}
	}
}