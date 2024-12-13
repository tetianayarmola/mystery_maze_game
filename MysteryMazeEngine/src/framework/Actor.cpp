#include "framework/Actor.h"
#include "framework/Core.h"

namespace mz
{
	Actor::Actor(World* ownedByWorld)
	//initialise local _mOwningByWorld to be owningByWorld
		: _mOwnedByWorld{ownedByWorld},
		_mStartedPlay {false} //set to false to guarantee StarPlay() happens only once
		

	{

	}

	Actor::~Actor()
	{
		//empty, Actor destructor
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
}