#include<SDL.h>
SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow("sdl test", //�������֣�ע��VS7�Ժ�汾ȫ�����ǿ��ַ���ʽ��Ҫ�����ĵĻ��ÿ��ַ���־
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
	SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255); //��2��3��4�Ĳ����ֱ����RGBֵ�����������Ǻ�ɫ
		SDL_RenderClear(g_pRenderer);
	SDL_RenderPresent(g_pRenderer);
	SDL_Delay(5000); //�ж�5�룬ֻ��Ϊ�˲���
		SDL_Quit();
	return 0;
}