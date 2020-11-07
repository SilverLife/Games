
#include <thread>
#include "Maps\Map.h"
#include "GameData\Input.h"

#include <ctime>

using namespace Socoban;

int main()
{
	std::srand(time(0));
	auto game = GetLevel();

	std::thread input_thread(KeyboardInput, game.get());

	game->_action_manager.Run();
	
	input_thread.join();

	return 0;
}