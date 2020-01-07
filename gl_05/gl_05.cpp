#include "GameEngine.h"

int main()
{	
	try
	{
		GameEngine::getInstance().init();
		GameEngine::getInstance().run();
	}
	catch (exception e)
	{
		cout << "Exception: " << e.what() << endl;
	}

	return 0;
}
