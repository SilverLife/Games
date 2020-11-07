// ☕ Привет
#pragma once

#include "EventGameEngine/GameData/GameData.h"
#include "../Object/Player.h"

using namespace EventGameEngine;

namespace Socoban
{
	class GameDataWithPlayer : public GameData<1>
	{
	public:
		Object::Player* _player;

		GameDataWithPlayer(Size field_size)
			: GameData(field_size)
		{}
	};
}