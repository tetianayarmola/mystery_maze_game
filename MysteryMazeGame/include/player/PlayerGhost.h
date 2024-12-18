#pragma once
#include "ghost/Ghost.h"

namespace mz 
{
	class PlayerGhost : public Ghost //publicly inheriting from Ghost
	{
	public:
		//seting up World and Texture
		PlayerGhost(World* ownedByWorld, const std::string& path="SpaceShooterRedux/PNG/playerShip2_red.png");
	};

}