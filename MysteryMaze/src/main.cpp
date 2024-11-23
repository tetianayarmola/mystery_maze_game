#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
	// <-- Game Window section starts -->
	sf::RenderWindow renderWindow{ sf::VideoMode(100,100), "GameWindow" };
	//prevent window from closing:
	//create infinite loop
	while (renderWindow.isOpen())
	{
		//add window event handling to unfreeze the window functionality
		//create new variable with type Event and pass it to the pollEvent() function
		//note - we are passing windowEvent as Event but not as a constant Event, which guarantee that event will be changed.
		sf::Event windowEvent;
		while (renderWindow.pollEvent(windowEvent))
		{
			//As event will be changed, we need to proccess changes
			//If event matches Closed
			if (windowEvent.type == sf::Event::EventType::Closed)
			{
				//program closes the window
				renderWindow.close();
			}
		}

	}
	// <-- Game Window section ends -->

	std::cout << "Helloe, Mystery Maze!" << std::endl;
}