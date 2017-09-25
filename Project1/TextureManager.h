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
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE); //Ĭ��Ϊ����ת  
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int CurrentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);  //������ָ���к�֡  
	
	static TextureManager* Instance()   //��̬ʵ��  
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance; //���ʵ���Ѵ��ڣ�ֱ�ӷ���ʵ��ָ��  
	}

private:
	std::map <std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;
	TextureManager() {} //����������Ϊ˽��

};

typedef TextureManager TheTextureManager;//��֪����������Բ���

#endif // __TEXTURE_MANAGER__  