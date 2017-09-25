#include <iostream> 
#include "Game.h"  

Game* g_game = 0;   //全局实例  

//这里演示了基本框架结构  
int main(int argc, char* argv[])
{
	std::cout << "game init attempt...\n";
	if (TheGame::Instance()-> init("Chapter3", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
		while (TheGame::Instance()->running())//开始主循环
		{
			TheGame::Instance()->handleEvents();//处理输入
			TheGame::Instance()->update();//计算时间和碰撞
			TheGame::Instance()->render();//渲染到屏幕

			SDL_Delay(10);//延时10毫秒。可以让cpu占用率低很多
		}

	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	std::cout << "game closing...\n";
	TheGame::Instance()->clean();//清理资源，退出
	return 0;


/*	g_game = new Game();    //Game类对象实例  
	g_game->init("Charpter 1", 100, 100, 640, 480, 0);  //初始化  
	//标题：Charpter 1,  
	//x,y位置：100, 100  
	//窗口宽高：640, 480  
	//窗口标志：0  
	//标志建议使用：SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL  

	while (g_game->running())    //开始主循环  
	{
		g_game->handleEvents(); //处理输入  
		g_game->update();   //计算时间和碰撞  
		g_game->render();   //渲染到屏幕  
	}
	g_game->clean();    //清理资源，退出  

	return 0;*/
}