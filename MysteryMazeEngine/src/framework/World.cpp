#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"
#include "framework/Application.h"

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
		//we use the iterators loop as it is easier to add or remove and update items
		//if we call Destroy on any Actor, it should be destroyed in the next loop iteration
		for (auto iter = _mActors.begin(); iter != _mActors.end(); )
		{
			if (iter->get()->IsPendingDestroy()) //if Actor Destroy() did set IsPendingDestroy = true
			{
				//then remove the Actor[iter] from the list
				iter = _mActors.erase(iter);

				//no need in iter++ as erase() returns to the next iteraror after removing
			}
			else //if destroying is not the case, we increase
			{
				//we Tick the Actor[iter]
				iter->get()->TickInternal(deltaTime);
				//and we increment the iterator
				++iter;
			}
		}

		Tick(deltaTime);
	}

	void World::Render(sf::RenderWindow& window)
	{
		//loop through all Actors and ask them to be rendered
		for (auto& actor : _mActors) //put auto as a reference so we don't have a copy
		{
			actor->Render(window);
		}
	}

	World::~World()
	{
		//is empty for the destructor
	}


	sf::Vector2u World::GetWindowSize() const
	{
		return _mOwnedByApp->GetWindowSize();
	}

	void World::StartPlay() //customer modifiable
	{
		
	}

	void World::Tick(float deltaTime) //customer modifiable
	{
		
	}
}