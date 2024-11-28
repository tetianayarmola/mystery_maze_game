//include header file
#include "framework/Application.h"
#include <iostream>



namespace mz
{
	//creating definition of the default constructor
	Application::Application()
		//initialise window
		// initialiser list. Preferable way when you constructed without anything else
		: _mWindow{ sf::VideoMode(1920, 1920), "Mystery Maze" },
		_mTargetFrameRate{ 60.f },
		_mTickClock{} 
		
	{
		//nothing in here
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
			accumulatedTime += _mTickClock.restart().asSeconds(); //adds the time which elapsed before reset and converts it to float format
			while (accumulatedTime > targetDeltaTime) //if true we need to update
			{
				//reducing accumulated time
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);

				//Rendering
				RenderInternal(); 

			}
		}
	}


	// <- Template functions definitions to NOT be changed by user / customer ->
	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
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


	//<- Virtual functions definitions to be changed by user/customer ->

	//specifying what to render
	void Application::Render()
	{
		//create a circle with the radius
		sf::CircleShape circle{ 30 };
		circle.setOrigin(30, 30); //sets pivit point tothe centre (diameter/2)
		circle.setPosition(_mWindow.getSize().x / 2.f, _mWindow.getSize().y / 2.f); //coordinates x and y of the  game window divided by 2, sets to the centre
		circle.setFillColor(sf::Color::White);
		//tell the window to draw the circle
		_mWindow.draw(circle);
	}

	//specifying what happens on each Tick
	void Application::Tick(float deltaTime)
	{
		std::cout << "Ticking at framerate: " << 1.f / deltaTime << std::endl;
	}
	//<- Virtual functions definitions end ->
}


