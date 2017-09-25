#include <iostream> 
#include "Game.h"  

Game* g_game = 0;   //ȫ��ʵ��  

//������ʾ�˻�����ܽṹ  
int main(int argc, char* argv[])
{
	std::cout << "game init attempt...\n";
	if (TheGame::Instance()-> init("Chapter3", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
		while (TheGame::Instance()->running())//��ʼ��ѭ��
		{
			TheGame::Instance()->handleEvents();//��������
			TheGame::Instance()->update();//����ʱ�����ײ
			TheGame::Instance()->render();//��Ⱦ����Ļ

			SDL_Delay(10);//��ʱ10���롣������cpuռ���ʵͺܶ�
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