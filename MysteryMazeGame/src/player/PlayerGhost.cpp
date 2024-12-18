#include "player/PlayerGhost.h"

namespace mz
{
	PlayerGhost::PlayerGhost(World* ownedByWorld, const std::string& path)
		: Ghost{ownedByWorld, path},
		_mMoveInput{},
		_mSpeed{200.f}//initialise speed value
	{
	}


	void PlayerGhost::Tick(float deltaTime)
	{
		//call Ghost Tick in here
		Ghost::Tick(deltaTime);
		//and call HandleInput after a Tick
		HandleInput();
		ApplyInput(deltaTime);
	}
	
	void PlayerGhost::HandleInput()
	{
		//check which keys are being pressed using SFML library
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // W 
		{
			_mMoveInput.y = -1.f; //go up
		} 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // S
		{
			_mMoveInput.y = 1.f; //go down
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // A
		{
			_mMoveInput.x = -1.f; //go left
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // S
		{
			_mMoveInput.x = 1.f; //go right
		}
	}

	void PlayerGhost::ApplyInput(float deltaTime)
	{
		//set velocity based on move input from keyboard
		SetVelocity(_mMoveInput * _mSpeed);
		_mMoveInput.x = _mMoveInput.y = 0.f; // reset move input after being applied
	}
}