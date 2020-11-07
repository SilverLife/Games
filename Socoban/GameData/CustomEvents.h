// ☕ Привет
#pragma once

#include "EventGameEngine\EventData\Event.h"

using namespace EventGameEngine;

namespace Socoban
{
	enum CustomEventType : EventData::EventTypeInt
	{
		PlaceholderFilled,
		PlaceholderUnfilled,

		CustomEventsCount
	};
}