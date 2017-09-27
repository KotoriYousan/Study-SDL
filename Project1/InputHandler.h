#ifndef _INPUT_HANDLER_
#define _INPUT_HANDLER_

#include "SDL.h"
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}

		return s_pInstance;
	}

	void update();

	void clean();

	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D* getMousePosition() { return m_mousePosition; }

	const Uint8* m_keystates;

	bool isKeyDown(SDL_Scancode key);

private:
	InputHandler();
	~InputHandler(){}
	static InputHandler* s_pInstance;

	std::vector <bool> m_mouseButtonStates; //鼠标状态数组，0左，1中，2右

	Vector2D* m_mousePosition;
};

typedef InputHandler TheInputHandler;

#endif//_INPUT_HANDLER_