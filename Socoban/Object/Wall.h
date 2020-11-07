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

			virtual int OnActiveIntersect(FieldData::FieldObject* intersected_object)
			{
				throw std::logic_error("Walls cannot move");
			}

			virtual int OnPassiveIntersect(FieldData::FieldObject* intersected_object)
			{
				// Кто бы не пытался наступить на стену, сделать он это не сможет, и выживет
				return 0;
			}

			void OnRemove() override
			{
				throw "Cannot remove wall";
			}
		};
	}
}