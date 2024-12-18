#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "framework/AssetManager.h"
#include "player/PlayerGhost.h"
#include "config.h"

mz::Application* GetApplication()
{
	return new mz::GameApplication{};
}

namespace mz
{
	GameApplication::GameApplication()
		: Application{1400, 1200, "Mystery Maze", sf::Style::Titlebar | sf::Style::Close} // titlebar or close, no resize 
	{
		// calling AssetManager function to set root dir for assets
		AssetManager::Get().SetAssetRootDirectory(GetResourceDir());
		//load and run the World in game
		weak<World> newWorld = LoadWorld<World>();

		//because it is a weak reference, we have to lock it first
		//then spawn a regular actor
		newWorld.lock()->SpawnActor<Actor>();
		testPlayerGhost = newWorld.lock()->SpawnActor<PlayerGhost>();

		// !- texture now set in the Player.Ghost.h constructor
		//testPlayerGhost.lock()->SetTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip2_red.png"); //GetResourceDir() is defined in config file

		testPlayerGhost.lock()->SetActorLocation(sf::Vector2f(700.f, 600.f)); //move to the centre of the screen
		testPlayerGhost.lock()->SetActorRotation(0.f); //rotate 90 degree                       
	}
	void GameApplication::Tick(float deltaTime)
	{
		//for test purposes
		counter += deltaTime;
		//after 2 seconds
		if (counter > 2.f)
		{
			//if actor is not destroyed already
			//expired means that the corresponding pointer is removed, thus does not exist anymore
			if (!testPlayerGhost.expired()) 
			{
				//lock it first to get a corresponding share pointer
				// and ask the Actor to be destroyed
				testPlayerGhost.lock()->Destroy();

			}
			
		}
	}
}

//there is no main function in game files, it is hidden(encaplulated) in Engine so main is like a Template Function now
//but the main function in GameEngine Entry point files requires GetApplication() function from Game folder files

//Note: Application holds only one world, and the World holds a List of Actors (can be many)