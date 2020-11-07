// ☕ Привет
#pragma once

#include "EventGameEngine/FieldData/FieldObjectWithPos.h"
#include "EventGameEngine/EventData/GlobalEventPusher.h"

using namespace EventGameEngine;

namespace Socoban
{
	namespace Object
	{
		class BlockPlaceholder : public FieldData::FieldObject
		{
			static constexpr unsigned char kSymbol = 176;
			bool _is_block_here = false;
		public:
			BlockPlaceholder()
				: FieldData::FieldObject(kSymbol, Shared::ConsoleHelper::Color::LightCyan)
			{}

			void OnDraw(Point point_to_draw) override;
			int OnPassiveIntersect(Point active_pos, Point passive_pos, FieldData::FieldObject* intersected_object) override;

			bool IsBlockHere() const { return _is_block_here; }
		};
	}
}