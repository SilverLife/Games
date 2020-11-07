// ☕ Привет
#pragma once

#include <conio.h>
#include "GameDataWithPlayer.h"
#include "EventGameEngine\EventData\GlobalEventPusher.h"

using namespace EventGameEngine;

namespace Socoban
{
	void KeyboardInput(GameDataWithPlayer* game_data)
	{
		char ch;
		do
		{
			ch = _getch();

			const auto player_pos = game_data->_player->Pos();

			switch (ch)
			{
			case 'a': EventData::PushEvent(new EventData::EventMoveObject(player_pos, player_pos + Point{-1,  0})); break;
			case 'w': EventData::PushEvent(new EventData::EventMoveObject(player_pos, player_pos + Point{ 0, -1})); break;
			case 's': EventData::PushEvent(new EventData::EventMoveObject(player_pos, player_pos + Point{ 0,  1})); break;
			case 'd': EventData::PushEvent(new EventData::EventMoveObject(player_pos, player_pos + Point{ 1,  0})); break;
			}

		} while (ch != 27);

		exit(0);
	}
}