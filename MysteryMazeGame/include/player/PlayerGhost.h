#pragma once
#include "ghost/Ghost.h"

namespace mz 
{
	class PlayerGhost : public Ghost //publicly inheriting from Ghost
	{
	public:
		//seting up World and Texture
		PlayerGhost(World* ownedByWorld, const std::string& path="SpaceShooterRedux/PNG/playerShip2_red.png");

		// function to control player with buttons
		virtual void Tick(float deltaTime) override; 
		void SetSpeed(float newSpeed) { _mSpeed = newSpeed; }
		float GetSpeed() const { return _mSpeed; }
	private:
		void HandleInput();
		void Normaliseinput();
		void StopInputOnEdge();
		void ApplyInput(float deltaTime);
		sf::Vector2f _mMoveInput;
		float _mSpeed;

	};

}