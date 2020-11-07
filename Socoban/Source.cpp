
#include <thread>
#include "Maps\LevelReader.h"
#include "Maps\Levels\Level_1.h"
#include "GameData\Input.h"

#include <ctime>

using namespace Socoban;

int main()
{
	std::srand(time(0));
	auto game = ReadLevel(Levels::kMapLevel1, std::size(Levels::kMapLevel1[0]), std::size(Levels::kMapLevel1));

	std::thread input_thread(KeyboardInput, game.get());

	game->_action_manager.Run();
	
	input_thread.join();

	return 0;
}