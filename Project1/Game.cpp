#include <iostream>  
//注：对于在VS 2012 EXPRESS的IDE中使用std::cout，  
//需要包含Windows.h，  
//然后调用AllocConsole(); 和freopen("CON", "w", stdout);  
//将上述内容添加到main.cpp中  
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
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)  //SDL_Init成功。参数也可写为SDL_INIT_VIDEO | SDL_INIT_TIMER  
	{
		std::cout << "SDL init success\n";
		//调用SDL的创建窗口函数，返回窗口资源指针  
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0)   //窗口创建成功  
		{
			std::cout << "window creation success\n";
			//创建渲染器资源  
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0)    //渲染器创建成功  
			{
				std::cout << "renderer creation success\n";
				//设置当前渲染色，rgba，红绿蓝透明四通道  
				SDL_SetRenderDrawColor(m_pRenderer, 0x0, 0x0, 0x66, 0xFF);
			}
			else {
				std::cout << "renderer init fail\n";
				return false;   //渲染器失败  
			}
		}
		else {
			std::cout << "window init fail\n";
			return false; //窗口创建失败  
		}
	}
	else{
		std::cout << "SDL init fail\n";
		return false; //SDL库初始失败  
	}


	if (!TheTextureManager::Instance()->load("assets/animate.png", "animate", m_pRenderer))
		return false;
	//load()方法是bool值，可以在这里加入判断，失败直接返回  

	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82,
		"animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82,
		"animate")));


	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());


	std::cout << "init success\n";
	m_bRunning = true;  //所有初始都成功，可以开始主循环了  
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
	//直接计算Game类的私有成员：当前帧  
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
	//TheInputHandler::Instance()->clean();//目前为止还用不上。如果需要对手柄进行处理，则需要
	SDL_DestroyWindow(m_pWindow);   //销毁资源，可以加上判断  
	//if(m_pWindow) { SDL_DestroyWindow(m_pWindow); }  
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	m_bRunning = false;
}