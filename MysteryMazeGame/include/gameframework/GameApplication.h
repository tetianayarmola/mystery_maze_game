#pragma once
#include <framework/Application.h>
#include <framework/Core.h>

namespace mz
{
	//declare Actor class as we making reference to an Actor here
	class Actor;
	//class GameApplication inherit from Application
	class GameApplication : public Application
	{
		//create constructor for GameApplication
	public:
		GameApplication();
		virtual void Tick(float deltaTime) override;
	private:
		float counter;
		weak<Actor> _mActorToDestroy;
	};
}