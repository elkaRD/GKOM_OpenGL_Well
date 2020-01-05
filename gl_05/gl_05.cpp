#include "GameEngine.h"

int main()
{	
	GameEngine::getInstance().init();
	GameEngine::getInstance().run();

	return 0;
}
