// ☕ Привет
#pragma once

#include "EventGameEngine/FieldData/FieldObjectWithPos.h"
#include "EventGameEngine/EventData/GlobalEventPusher.h"

using namespace EventGameEngine;

namespace Socoban
{
	namespace Object
	{
		class FilledPlaceholdersCounter : public FieldData::FieldObject
		{
			int _empty_placeholders_count;
		public:
			FilledPlaceholdersCounter(int placeholders_count)
				: FieldData::FieldObject()
				, _empty_placeholders_count(placeholders_count)
			{}

			virtual void OnEvent(EventData::Event* event) 
			{
				if (event->_type == CustomEventType::PlaceholderFilled)
				{
					--_empty_placeholders_count;
				}
				else if (event->_type == CustomEventType::PlaceholderUnfilled)
				{
					++_empty_placeholders_count;
				}

				Shared::ConsoleHelper::Console().Print({ 40,10 }, std::to_string(_empty_placeholders_count));

				if (_empty_placeholders_count == 0)
				{
					EventData::PushEvent(new EventData::Event(EventData::ActionEventType::Win));
				}
			}
		};
	}
}