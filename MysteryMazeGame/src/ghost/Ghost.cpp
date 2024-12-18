#include "ghost/Ghost.h"

namespace mz
{
	Ghost::Ghost(World* ownedByWorld, const std::string& texturePath)
		: Actor{ ownedByWorld, texturePath },
		_mVelocity{} // initialize velocity to be nothing just in case
	{
	}

	void Ghost::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime); 
		AddActorLocationOffset(GetVelocity() * deltaTime); //move with time 
	}
	void Ghost::SetVelocity(const sf::Vector2f& newVelocity)
	{
		_mVelocity = newVelocity;
	}
}