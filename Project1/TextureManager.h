#ifndef __TEXTURE_MANAGER__  
#define __TEXTURE_MANAGER__  
#include <string>  
#include <map>  

#include <SDL.h>  
#include <SDL_image.h>  

class TextureManager
{
public:
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE); //默认为不翻转  
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int CurrentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);  //参数中指定行和帧  
	
	static TextureManager* Instance()   //静态实例  
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance; //如果实例已存在，直接返回实例指针  
	}

private:
	std::map <std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;
	TextureManager() {} //将构造声明为私有

};

typedef TextureManager TheTextureManager;//不知道放在这里对不对

#endif // __TEXTURE_MANAGER__  