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
	{
		//load and run the World in game
		weak<World> newWorld = LoadWorld<World>();

		//because it is a weak reference, we have to lock it first
		//then spawn a regular actor
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
	}
}

//there is no main function in game files, it is hidden(encaplulated) in Engine so main is like a Template Function now
//but the main function in GameEngine Entry point files requires GetApplication() function from Game folder files

//Note: Application holds only one world, and the World holds a List of Actors (can be many)