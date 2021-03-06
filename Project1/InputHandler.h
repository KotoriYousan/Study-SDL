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

	std::vector <bool> m_mouseButtonStates; //���״̬���飬0��1�У�2��

	Vector2D* m_mousePosition;



	// private functions to handle different event types
	// handle keyboard events
	void onKeyDown();
	void onKeyUp();
	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);
	/*	// handle joysticks events
	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);*/


};

typedef InputHandler TheInputHandler;

#endif//_INPUT_HANDLER_