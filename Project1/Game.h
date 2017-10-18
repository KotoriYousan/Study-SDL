#ifndef __Game__  
#define __Game__  
#include <SDL.h>  
#include "TextureManager.h"

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"

#include <vector>

class Game
{
public:
	//Game();
	//~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);  //初始化  
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }   //返回运行状态  
	void quit();

	//由于渲染器指针会被外部使用，因此定义一个get方法  
	SDL_Renderer* getRenderer() const { return m_pRenderer; }


	std::vector<GameObject*> m_gameObjects;
	//GameObject* m_go;
	//GameObject* m_player;
	//GameObject* m_enemy;

	GameStateMachine* m_pGameStateMachine;

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	Game();
	~Game();
	static Game* s_pInstance;

	SDL_Window* m_pWindow;  //窗口资源指针  
	SDL_Renderer* m_pRenderer;  //渲染器资源指针  
	bool m_bRunning;
	//SDL_Texture* m_pTexture;    //纹理指针  
	//SDL_Rect m_srcRect; //纹理的矩形位置  
	//SDL_Rect m_destRect;    //绘制到屏幕上的位置矩形  
	int m_currentFrame;
	//TextureManager m_textureManager;

	

};

typedef Game TheGame;

#endif // __Game__  