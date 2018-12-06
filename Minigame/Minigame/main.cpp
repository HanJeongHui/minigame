#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
	Uint32 frameStart, frameTime;
	std::cout << "game init attempt...\n";
	if (TheGame::Instance()->init("PP15.FSM", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
		while (TheGame::Instance()->isRunning())
		{
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			SDL_Delay(10);
		}
	}
	else {
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	std::cout << "game closing...\n";
	TheGame::Instance()->clean();


	return 0;
}