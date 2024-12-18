#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"
#include "framework/World.h"

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

	void Actor::TickInternal(float deltaTime)
	{
		//tick the actor if not pending to destroy, called from World.cpp
		if (!IsPendingDestroy())
		{
			Tick(deltaTime);
		}
	}


	// customer modifiable functions
	void Actor::StartPlay()
	{
		
	}
	
	void Actor::Tick(float deltaTime)
	{
		
	}
	//function to set a texture to sprite
	void Actor::SetTexture(const std::string& texturePath)
	{
		//asking asset manager to load textures
		_mTexture = AssetManager::Get().LoadTexture(texturePath);
		//if we cannot load anything - return
		if (!_mTexture) return;
		_mSprite.setTexture(*_mTexture); // use * to reference _mTexture shared pointer to get the value

		//making sure texture fits properly, from top left corner to bottom right corner
		//intRect{TopLeftCornerCoordinates, SizeOfTexture}
		int textureWidth = _mTexture->getSize().x;
		int textureHeight = _mTexture->getSize().y;
		_mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight} });
		//set Sprite pivit point to the centre
		CenterPivit();
	}
	void Actor::Render(sf::RenderWindow& window)
	{
		//ask window to draw a sprite
		window.draw(_mSprite);
	}


	void Actor::SetActorLocation(const sf::Vector2f& newLocation)
	{
		_mSprite.setPosition(newLocation);
	}

	void Actor::SetActorRotation(float newRotation)
	{
		_mSprite.setRotation(newRotation);
	}

	void Actor::AddActorLocationOffset(const sf::Vector2f& offsetAmount)
	{
		SetActorLocation(GetActorLocation() + offsetAmount);
	}

	void Actor::AddActorRotationOffset(float offsetAmount)
	{
		SetActorRotation(GetActorRotation() + offsetAmount);
	}

	sf::Vector2f Actor::GetActorLocation() const
	{
		return _mSprite.getPosition();
	}

	float Actor::GetActorRotation() const
	{
		return _mSprite.getRotation();
	}

	//determine Actor direction
	sf::Vector2f Actor::GetActorForwardDirection() const
	{
		return RotationToVector(GetActorRotation());
	}

	sf::Vector2f Actor::GetActorRightDirection() const
	{
		return RotationToVector(GetActorRotation() + 90.f);
	}


	//get size of the window
	sf::Vector2u Actor::GetWindowSize() const
	{
		return _mOwnedByWorld->GetWindowSize();
	}

	void Actor::CenterPivit()
	{
		//gets the bounts of the sprite
		sf::FloatRect bound = _mSprite.getGlobalBounds();
		//set pivit to the centre
		_mSprite.setOrigin(bound.width / 2.f, bound.height / 2.f);
	}
}