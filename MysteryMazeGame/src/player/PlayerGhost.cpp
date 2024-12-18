#include "player/PlayerGhost.h"
#include "framework/MathUtility.h"
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // A
		{
			_mMoveInput.x = -1.f; //go left
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // S
		{
			_mMoveInput.x = 1.f; //go right
		}

		//stop actor from going beyond game window edges
		StopInputOnEdge();

		//normalise input vector so speed is applied properly when player moves diagonaly
		Normaliseinput();
	}

	void PlayerGhost::Normaliseinput()
	{
		Normalise(_mMoveInput);
		LOG("move input is now: %f, %f", _mMoveInput.x, _mMoveInput.y);
	}

	void PlayerGhost::StopInputOnEdge()
	{
		//get actor Location
		sf::Vector2f actorLocation = GetActorLocation();
		if (actorLocation.x < 0 && _mMoveInput.x == -1) //if actor is on the edge and still moving left
		{
			_mMoveInput.x = 0.f; //then stop actor to move on x
		}
		if (actorLocation.x > GetWindowSize().x && _mMoveInput.x == 1.f) //if actor is on the edge and still moving right
		{
			_mMoveInput.x = 0.f; //then stop actor to move on x
		}

		if (actorLocation.y < 0 && _mMoveInput.y == -1) //if moves beyond the top edge
		{
			_mMoveInput.y = 0.f; //then stop actor to move on y
		}
		if (actorLocation.y > GetWindowSize().y && _mMoveInput.y == 1.f) //if moves beyond bottom edge
		{
			_mMoveInput.y = 0.f; //then stop actor to move on y
		}
	}

	void PlayerGhost::ApplyInput(float deltaTime)
	{
		//set velocity based on move input from keyboard
		SetVelocity(_mMoveInput * _mSpeed);
		_mMoveInput.x = _mMoveInput.y = 0.f; // reset move input after being applied
	}
}