#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

mz::Application* GetApplication()
{
	return new mz::GameApplication{};
}

namespace mz
{
	GameApplication::GameApplication()
		: Application{600, 980, "Mystery Maze", sf::Style::Titlebar | sf::Style::Close} // titlebar or close, no resize 
	{
		//load and run the World in game
		weak<World> newWorld = LoadWorld<World>();

		//because it is a weak reference, we have to lock it first
		//then spawn a regular actor
		newWorld.lock()->SpawnActor<Actor>();
		_mActorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		_mActorToDestroy.lock()->SetTexture("C:/CMake_Projects/Uni_Coursework/CMake_learning_projects/MysteryMaze/MysteryMazeGame/assets/SpaceShooterRedux/PNG/playerShip2_red.png");
		counter = 0;
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
			if (!_mActorToDestroy.expired()) 
			{
				//lock it first to get a corresponding share pointer
				// and ask the Actor to be destroyed
				_mActorToDestroy.lock()->Destroy();

			}
			
		}
	}
}

//there is no main function in game files, it is hidden(encaplulated) in Engine so main is like a Template Function now
//but the main function in GameEngine Entry point files requires GetApplication() function from Game folder files

//Note: Application holds only one world, and the World holds a List of Actors (can be many)