#pragma once
#include <SFML/Graphics.hpp>
//if multiple headers are trying to be included, pragma will include it only once
//press ctrl+K+O to quicky switch between header and .cpp file

//create namespace mz - Maze
namespace mz
{
	//create a class
	class Application
	{
	public:
		//creating constructor
		Application();
		//create function
		void Run();
	private:
		//function to update based on time
		void TickInternal(float deltaTime);//template function
		virtual void Tick(float deltaTime); //defined and changed by customer
		void RenderInternal();//template function
		virtual void Render(); //defined and changed by customer


		//declare window from SFML/Graphics
		sf::RenderWindow _mWindow; //m and _ to indicate a private internal member (naming convention)
		float _mTargetFrameRate; //framerate we will be looking for, using fixed framerate to allow game physic behave better
		//clock from SFML to track the time
		sf::Clock _mTickClock;
	};
}