#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_

#include "LoaderParams.h"   //ר�������������ļ���  
#include <SDL.h>
#include <iostream>

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};

#endif //_GAME_OBJECT_