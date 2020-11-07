// ☕ Привет
#pragma once

#include "../GameData/GameDataWithPlayer.h"
#include "../Object/Wall.h"
#include "../Object/Block.h"
#include "../Object/BlockPlaceholder.h"
#include "../Object/FilledPlaceholdersCounter.h"
#include <memory>
#include <string_view>

using namespace EventGameEngine;

namespace Socoban
{
	std::unique_ptr<GameDataWithPlayer> ReadLevel(const std::string_view* map, PointCoordsType w, PointCoordsType h)
	{
		auto game = std::make_unique<GameDataWithPlayer>(Size{ w, h });

		int block_count = 0;
		int placeholders_count = 0;

		for (PointCoordsType x = 0; x < w; x++)
		{
			for (PointCoordsType y = 0; y < h; y++)
			{
				const Point pos(x, y);

				const auto symbol = map[y][x];

				if (symbol == 'P')
				{
					game->_player = new Object::Player(pos);
					game->_field.AddObject(pos, game->_player);
				}
				else if (symbol == '#')
				{
					game->_field.AddObject(pos, new Object::Wall);
				}
				else if (symbol == 'B')
				{
					game->_field.AddObject(pos, new Object::Block);
					++block_count;
				}
				else if (symbol == 'H')
				{
					game->_field.AddObject(pos, new Object::BlockPlaceholder);
					++placeholders_count;
				}
			}
		}

		if (block_count != placeholders_count)
		{
			throw std::logic_error("Incorrect map");
		}

		const auto filled_placeholders_counter = new Object::FilledPlaceholdersCounter(block_count);
		game->_action_manager.SubscribeToCustomEvent(filled_placeholders_counter, CustomEventType::PlaceholderFilled);
		game->_action_manager.SubscribeToCustomEvent(filled_placeholders_counter, CustomEventType::PlaceholderUnfilled);
				
		return game;
	}
}