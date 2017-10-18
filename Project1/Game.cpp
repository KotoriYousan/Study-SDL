#include <iostream>  
//ע��������VS 2012 EXPRESS��IDE��ʹ��std::cout��  
//��Ҫ����Windows.h��  
//Ȼ�����AllocConsole(); ��freopen("CON", "w", stdout);  
//������������ӵ�main.cpp��  
#include "Game.h"  
#include <SDL_image.h>  
#include <vector>


Game* Game::s_pInstance = 0;

Game::Game()
{

}
Game::~Game()
{

}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)  //SDL_Init�ɹ�������Ҳ��дΪSDL_INIT_VIDEO | SDL_INIT_TIMER  
	{
		std::cout << "SDL init success\n";
		//����SDL�Ĵ������ں��������ش�����Դָ��  
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0)   //���ڴ����ɹ�  
		{
			std::cout << "window creation success\n";
			//������Ⱦ����Դ  
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0)    //��Ⱦ�������ɹ�  
			{
				std::cout << "renderer creation success\n";
				//���õ�ǰ��Ⱦɫ��rgba��������͸����ͨ��  
				SDL_SetRenderDrawColor(m_pRenderer, 0x0, 0x0, 0x66, 0xFF);
			}
			else {
				std::cout << "renderer init fail\n";
				return false;   //��Ⱦ��ʧ��  
			}
		}
		else {
			std::cout << "window init fail\n";
			return false; //���ڴ���ʧ��  
		}
	}
	else{
		std::cout << "SDL init fail\n";
		return false; //SDL���ʼʧ��  
	}


	if (!TheTextureManager::Instance()->load("assets/animate.png", "animate", m_pRenderer))
		return false;
	//load()������boolֵ����������������жϣ�ʧ��ֱ�ӷ���  

	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82,
		"animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82,
		"animate")));


	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());


	std::cout << "init success\n";
	m_bRunning = true;  //���г�ʼ���ɹ������Կ�ʼ��ѭ����  
	return true;
}

void Game::render()
{
	//SDL_RenderClear(m_pRenderer);
	//m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
	//m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
	//TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
	//TheTextureManager::Instance()->drawFrame("animate", 0, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
	//SDL_RenderPresent(m_pRenderer);


	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	// loop through our objects and draw them
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer); // draw to the screen


}

void Game::update()
{
	//ֱ�Ӽ���Game���˽�г�Ա����ǰ֡  
/*	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));*/


	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	//TheInputHandler::Instance()->clean();//ĿǰΪֹ���ò��ϡ������Ҫ���ֱ����д�������Ҫ
	SDL_DestroyWindow(m_pWindow);   //������Դ�����Լ����ж�  
	//if(m_pWindow) { SDL_DestroyWindow(m_pWindow); }  
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	m_bRunning = false;
}