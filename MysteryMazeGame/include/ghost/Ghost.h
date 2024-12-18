#pragma once
#include "framework/Actor.h"
#include "framework/AssetManager.h"

namespace mz
{
	class Ghost : public Actor //publicly inheriting from Actor
	{
	public:
		//tell that the World is an owner of Ghost
		Ghost(World* ownedByWorld, const std::string& texturePath = "");
		virtual void Tick(float deltaTime) override;//to override Tick
		void SetVelocity(const sf::Vector2f& newVelocity);
		sf::Vector2f GetVelocity() const { return _mVelocity; }
	private:
		sf::Vector2f _mVelocity;

	};

}