// ☕ Привет
#pragma once

#include "EventGameEngine/GameData/GameData.h"
#include "../Object/Player.h"
#include "CustomEvents.h"

using namespace EventGameEngine;

namespace Socoban
{
	class GameDataWithPlayer : public GameData<CustomEventsCount>
	{
	public:
		Object::Player* _player;

		GameDataWithPlayer(Size field_size)
			: GameData(field_size)
		{}
	};
}