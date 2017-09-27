#include <iostream> 
#include "Game.h"  

Game* g_game = 0;   //ȫ��ʵ��  


/*Fixed frames per second (FPS) is
not necessarily always a good option, especially when your game includes more
advanced physics. It is worth bearing this in mind when you move on from this
book and start developing your own games. Fixed FPS will, however, be fine for
the small 2D games, which we will work towards in this book.*/
const int FPS = 60; //�̶�֡�ʵĳ���
const int DELAY_TIME = 1000.0f / FPS;


//������ʾ�˻�����ܽṹ  
int main(int argc, char* argv[])
{
	Uint32 frameStart, frameTime;//��ʼ�͵�ǰʱ��

	std::cout << "game init attempt...\n";
	if (TheGame::Instance()-> init("Chapter3", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
		while (TheGame::Instance()->running())//��ʼ��ѭ��
		{
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();//��������
			TheGame::Instance()->update();//����ʱ�����ײ
			TheGame::Instance()->render();//��Ⱦ����Ļ

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
			//SDL_Delay(10);//��ʱ10���롣������cpuռ���ʵͺܶ�
		}

	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	std::cout << "game closing...\n";
	TheGame::Instance()->clean();//������Դ���˳�
	return 0;


/*	g_game = new Game();    //Game�����ʵ��  
	g_game->init("Charpter 1", 100, 100, 640, 480, 0);  //��ʼ��  
	//���⣺Charpter 1,  
	//x,yλ�ã�100, 100  
	//���ڿ�ߣ�640, 480  
	//���ڱ�־��0  
	//��־����ʹ�ã�SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL  

	while (g_game->running())    //��ʼ��ѭ��  
	{
		g_game->handleEvents(); //��������  
		g_game->update();   //����ʱ�����ײ  
		g_game->render();   //��Ⱦ����Ļ  
	}
	g_game->clean();    //������Դ���˳�  

	return 0;*/
}