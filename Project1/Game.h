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
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);  //��ʼ��  
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }   //��������״̬  
	void quit();

	//������Ⱦ��ָ��ᱻ�ⲿʹ�ã���˶���һ��get����  
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

	SDL_Window* m_pWindow;  //������Դָ��  
	SDL_Renderer* m_pRenderer;  //��Ⱦ����Դָ��  
	bool m_bRunning;
	//SDL_Texture* m_pTexture;    //����ָ��  
	//SDL_Rect m_srcRect; //����ľ���λ��  
	//SDL_Rect m_destRect;    //���Ƶ���Ļ�ϵ�λ�þ���  
	int m_currentFrame;
	//TextureManager m_textureManager;

	

};

typedef Game TheGame;

#endif // __Game__  