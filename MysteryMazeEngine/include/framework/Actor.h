#pragma once
#include<SFML/Graphics.hpp>

#include "framework/Core.h"
#include "framework/Object.h"

namespace mz
{
	//declare World
	class World;
	//create class for everything which will be spawned/added to the World
	//make class to be inheriting from Object
	class Actor : public Object
	{
	public:
		//tell that the World is an owner of Actor, passing as an argument
		Actor(World* ownedByWorld, const std::string& texturePath = "");

		//virtual destructor
		virtual ~Actor();

		//below functions are in public to be able to overwrite them and call in the child class
		void StartPlayInternal(); //template function (core logic, not modifiable)
		virtual void StartPlay(); //customer modifiable
		virtual void Tick(float deltaTime); // no need in Tick Internal() here
		//function to assign a texture
		void SetTexture(const std::string& texturePath);
		//creating way to render actors/sprites
		void Render(sf::RenderWindow& window);

	private:
		//specify the owner locally as well
		World* _mOwnedByWorld;
		bool _mStartedPlay;

		// making Actor renderable 
		//ctrl + click on Sprite -> Sprite is smth drawable and transformable (set position, rotation, move, etc)
		sf::Sprite _mSprite;
		sf::Texture _mTexture;
	};
}