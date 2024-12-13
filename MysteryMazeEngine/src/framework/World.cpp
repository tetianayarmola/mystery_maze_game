#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace mz
{
	//create constructor
	World::World(Application* ownedByApp)
		//initialiser list
		: _mOwnedByApp{ownedByApp}, //initialise local _mOwningApp to be owningApp
		_mStartedPlay{ false },
		_mActors{}, //initialise Actors lists to be empty at the start
		_mPendingActors{}
	{

	}
	void World::StartPlayInternal() // template function (core logic, not modifiable)
	{
		//check if started playing:
		if (!_mStartedPlay) //if have not started play yet
		{
			//then start to play
			//because _mStartedPlay is boolean, it making sure we will see it only once
			_mStartedPlay = true; 
			StartPlay();
		}
	}
	void World::TickInternal(float deltaTime) //template function (core logic, not modifiable)
	{
		//on every tick interval: bring items from the pending actors list to the actors list
		for (shared<Actor> actor : _mPendingActors)
		{
			_mActors.push_back(actor);
			//make actors to start play
			actor->StartPlayInternal();
		} 

		// empty Pending Actors list after we've moved them
		_mPendingActors.clear(); 

		//update the _mActors list
		for (shared<Actor> actor : _mActors)
		{
			actor->Tick(deltaTime);
		}

		Tick(deltaTime);
	}

	World::~World()
	{
		//is empty for the destructor
	}


	void World::StartPlay() //customer modifiable
	{
		LOG("Started to Play");
	}

	void World::Tick(float deltaTime) //customer modifiable
	{
		LOG("Ticking at frame rate: %f", 1.f / deltaTime);
	}
}