// ☕ Привет
#pragma once

#include "../GameData/GameDataWithPlayer.h"
#include "../Object/Wall.h"
#include "../Object/Block.h"
#include <memory>

using namespace EventGameEngine;

namespace Socoban
{
	std::unique_ptr<GameDataWithPlayer> GetLevel()
	{
		auto game = std::make_unique<GameDataWithPlayer>(Size{ 20,10 });

		for (int i = 0; i < 10; i++)
		{
			const Point pos(std::rand() % 20, std::rand() % 10);
			if (!game->_field.IsEmpty(pos))
			{
				continue;
			}

			game->_field.AddObject(pos, new Object::Wall);
		}

		for (int i = 0; i < 5; i++)
		{
			const Point pos(std::rand() % 20, std::rand() % 10);
			if (!game->_field.IsEmpty(pos))
			{
				continue;
			}

			game->_field.AddObject(pos, new Object::Block);
		}

		while (true)
		{
			const Point pos(std::rand() % 20, std::rand() % 10);
			if (!game->_field.IsEmpty(pos))
			{
				continue;
			}

			game->_player = new Object::Player(pos);
			game->_field.AddObject(pos, game->_player);
			break;
		}

		return game;
	}
}