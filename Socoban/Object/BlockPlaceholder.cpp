// ☕ Привет
#pragma once

#include "BlockPlaceholder.h"
#include "Block.h"
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
			}
			return 0;
		}
	}
}