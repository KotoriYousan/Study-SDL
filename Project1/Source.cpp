#include<SDL.h>
SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow("sdl test", //窗口名字，注意VS7以后版本全部都是宽字符格式，要用中文的话用宽字符标志
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480,
			SDL_WINDOW_SHOWN);
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else
	{
		return 1;
	}
	SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255); //第2，3，4的参数分别代表RGB值，这样窗口是红色
		SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);
	SDL_Delay(5000); //中断5秒，只是为了测试
		SDL_Quit();
	return 0;
}