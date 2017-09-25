#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_

#include "LoaderParams.h"   //专门用于填充参数的简单类  
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