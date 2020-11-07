
#include <thread>
#include "Maps\Map.h"
#include "GameData\Input.h"
using namespace Socoban;

int main()
{
	auto game = GetLevel();

	std::thread input_thread(KeyboardInput, game.get());

	game->_action_manager.Run();
	
	input_thread.join();

	return 0;
}