// Defines

#define STB_IMAGE_IMPLEMENTATION

#define SCREEN_WIDTH 1600.0f
#define SCREEN_HEIGHT 900.0f


// Local includes

#include "engine_core.h"


// Application entry point
int main()
{
	std::unique_ptr<engine::EngineCore> gameEngine(new engine::EngineCore);


	// Try to initialize the engine... if no issues then start it.
	if (gameEngine->init(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Engine"))
	{
		engine::Game game;
		gameEngine->run(game);
	}

	return 0;
}