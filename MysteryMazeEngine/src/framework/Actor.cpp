#include "framework/Actor.h"
#include "framework/Core.h"

namespace mz
{
	Actor::Actor(World* ownedByWorld, const std::string& texturePath)
	//initialise local _mOwningByWorld to be owningByWorld
		: _mOwnedByWorld{ownedByWorld},
		_mStartedPlay {false}, //set to false to guarantee StarPlay() happens only once
		_mSprite{},
		_mTexture{} //texturePath var is in Actor.h
		

	{
		//call the function to set texture
		SetTexture(texturePath);
	}

	//Actor destructor
	Actor::~Actor()
	{
		//as inheriting Destroy() from Object:
		LOG("Actor destroyed"); 
	}

	// template functions (core logic, not modifiable)
	void Actor::StartPlayInternal()
	{
		if (!_mStartedPlay)
		{
			_mStartedPlay = true;
			StartPlay();
		}

	}


	// customer modifiable functions
	void Actor::StartPlay()
	{
		LOG("Actor start play");
	}
	
	void Actor::Tick(float deltaTime)
	{
		LOG("Actor Ticking");
	}
	//function to set a texture to sprite
	void Actor::SetTexture(const std::string& texturePath)
	{
		_mTexture.loadFromFile(texturePath);
		_mSprite.setTexture(_mTexture);

		//making sure texture fits properly, from top left corner to bottom right corner
		//intRect{TopLeftCornerCoordinates, SizeOfTexture}
		int textureWidth = _mTexture.getSize().x;
		int textureHeight = _mTexture.getSize().y;
		_mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight} });
	}
	void Actor::Render(sf::RenderWindow& window)
	{
		//ask window to draw a sprite
		window.draw(_mSprite);
	}
}