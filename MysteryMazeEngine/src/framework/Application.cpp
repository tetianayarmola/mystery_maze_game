// <-- Application is our entire game -->

//include header file
#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/AssetManager.h"



namespace mz
{
	Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style)
		: _mWindow{ sf::VideoMode(windowWidth, windowHeight), title, style },
		_mTargetFrameRate{ 60.f },
		_mTickClock{},
		//making sure currentWorld starts with the null pointer
		currentWorld{ nullptr },
		_mCleanCycleClock{},
		_mCleanCycleInterval{2.f} //2 seconds
	{

	}

	void Application::Run()
	{
		//restart the clock
		_mTickClock.restart(); //restarts the clock and returns the amount of time which has elapsed 
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / _mTargetFrameRate; //1 sec div by _mTargetFrameRate (60)

		//prevent window from closing:
		//create infinite loop
		while (_mWindow.isOpen())
		{
			//add window event handling to unfreeze the window functionality
			//create new variable with type Event and pass it to the pollEvent() function
			//note - we are passing windowEvent as Event but not as a constant Event, which guarantee that event will be changed.
			sf::Event windowEvent;
			while (_mWindow.pollEvent(windowEvent))
			{
				//As event will be changed, we need to proccess changes
				//If event matches Closed
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					//program closes the window
					_mWindow.close();
				}
			}

			//refresh, frames per second
			float frameDeltaTime = _mTickClock.restart().asSeconds(); //adds the time which elapsed before reset and converts it to float format
			accumulatedTime += frameDeltaTime;
			while (accumulatedTime > targetDeltaTime) //if true we need to update
			{
				//reducing accumulated time
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);

				//Rendering
				RenderInternal(); 
				AssetManager::Get().CleanCycle();
			}

		}
	}


	// <- Template functions definitions (core logic, not modifiable) ->
	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);

		//if the currentWorld is there
		if (currentWorld)
		{
			currentWorld->StartPlayInternal();
			currentWorld->TickInternal(deltaTime);
		}

		//check if the CycleClean interval passed and clean asset manager
		if (_mCleanCycleClock.getElapsedTime().asSeconds() >= _mCleanCycleInterval)
		{
			//restart the clock
			_mCleanCycleClock.restart();
			//ask AssetManager to clean 
		}
	}


	void Application::RenderInternal()
	{
		//creating a canvas:
		//tell the Window to clear itself
		_mWindow.clear();

		Render();

		//tell the Window to display a new change to apply everything above
		_mWindow.display();

	}
	//<- Temlate functions definitions end ->


	//<- Virtual functions definitions ( customer modifiable ) ->

	//specifying what to render
	void Application::Render()
	{
		//ask Application to render the World
		if (currentWorld)
		{
			currentWorld->Render(_mWindow);
		}
	}

	//specifying what happens on each Tick
	void Application::Tick(float deltaTime)
	{
		
	}
	//<- Virtual functions definitions end ->
}


