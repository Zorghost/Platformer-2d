#include "Engine.h"
#include "TextureManager.h"
#include <iostream>
#include "Warrior.h"
#include "Input.h"
#include "Timer.h"
#include "MapParser.h"
Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;
Warrior* player_run = nullptr;
bool Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
	{
		SDL_Log("falied to initialize SDL : ", SDL_GetError());
		return false;
	}
	m_window = SDL_CreateWindow("Projekt vertiefung Programmierung : Platformer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_HEIGHT, 0);
	if (m_window == nullptr)
	{
		SDL_Log("falied to Create Window : ", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) 
	{
		SDL_Log("falied to Create Renderer : ", SDL_GetError()); 
		return false;  
	}
	if (MapParser::GetInstance()->Load())
	{
		std::cout << "Failed to Load Map " << std::endl;
	}
	//m_LevelMap = MapParser::GetInstance()->GetMap("level1");
	TextureManager::GetInstance()->Load("player", "C:/Users/Rayen/OneDrive/Bureau/Studium/Vertiefung in der Programmierung/resources/Medieval Warrior (Version 1.2)/Idle.png");
	TextureManager::GetInstance()->Load("player_run", "C:/Users/Rayen/OneDrive/Bureau/Studium/Vertiefung in der Programmierung/resources/Medieval Warrior (Version 1.2)/Run.png");
	player = new Warrior(new Properties("player" , 200 , 200 ,184 , 137));
	return m_IsRunning = true;
}

bool Engine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_window);
	IMG_Quit();
	SDL_Quit();
	return NULL;
}

void Engine::Quit()
{
	m_IsRunning = false;
}

void Engine::Update()
{
	    float dt = Timer::GetInstance()->GetDeltaTime();
		//m_LevelMap->Update();
		player->Update(dt);
	
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 124, 210, 215 , 154);
	SDL_RenderClear(m_Renderer);
	//m_LevelMap->Render();
	player->Draw();
	SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
	Input::GetInstance()->Listen();


}
