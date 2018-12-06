#pragma once
#include <SDL.h>
#include <vector>
#include "GameObject.h"
#include "GameStateMachine.h"

class Game
{
public:
	~Game() {}
	static Game* Instance()
	{
		if (pInstance == nullptr)
		{
			pInstance = new Game();
		}
		return pInstance;
	}
	GameStateMachine* getStateMachine() { return pGameStateMachine; }
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void quit();
	void clean();
	bool isRunning() const { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
	Game() {}
	static Game* pInstance;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	typedef Game TheGame;
	std::vector<GameObject*> gameObjects;
	GameStateMachine* pGameStateMachine;
};
typedef Game TheGame;