#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"
#include <SDL_image.h>
#include <iostream>
#include "MenuState.h"
#include "PlayState.h"


Game* Game::pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		Uint32 flags;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
		}
		else
		{
			flags = SDL_WINDOW_SHOWN;
		}

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		SDL_SetRenderDrawColor(m_pRenderer, 0, 40, 60, 255);
		if (!TextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}

		gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		gameObjects.push_back(new Enemy(new LoaderParams(0, 0, 128, 82, "animate")));

		pGameStateMachine = new GameStateMachine();
		pGameStateMachine->changeState(MenuState::Instance());

		m_bRunning = true;
	}
	else
	{
		m_bRunning = false;
	}
	return m_bRunning;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	pGameStateMachine->update();
}

void Game::quit()
{
	m_bRunning = false;
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	InputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	InputHandler::Instance()->update();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		pGameStateMachine->changeState(PlayState::Instance());
	}

}