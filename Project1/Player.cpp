#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) :
SDLGameObject(pParams)
{

}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}
	SDLGameObject::update();
}
void Player::clean()
{
}