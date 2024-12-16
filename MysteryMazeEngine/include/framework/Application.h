// <-- Application is our entire game -->
#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
//if multiple headers are trying to be included, pragma will include it only once
//press ctrl+K+O to quicky switch between header and .cpp file

//create namespace mz - Maze
namespace mz
{
	//telling Application how to work with World
	class World;

	//create a class
	class Application
	{
	public:
		//creating constructor for Application and defining variables
		Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style );
		//create function
		void Run();

		//create the World inside Application and make it a template to make world type different from another
		template <typename WorldType>

		//using weak pointer because it is not supposed to have an ownership
		weak<WorldType> LoadWorld();

	private:
		//function to update based on time
		void TickInternal(float deltaTime);//template function (not modifiable)
		virtual void Tick(float deltaTime); //customer modifiable
		void RenderInternal();//template function (not modifiable)
		virtual void Render(); //customer modifiable


		//declare window from SFML/Graphics
		sf::RenderWindow _mWindow; //m and _ to indicate a private internal member (naming convention)
		float _mTargetFrameRate; //framerate we will be looking for, using fixed framerate to allow game physic behave better
		//clock from SFML to track the time
		sf::Clock _mTickClock;


		//a shared pointer to World
		//using shared because it has an ownership (World type belongs to Application)
		shared<World> currentWorld;

		//<-Assetmanager CleanCycle ->
		sf::Clock _mCleanCycleClock;
		float _mCleanCycleInterval;
	};

	//create a definition 
	//note: template definition cannot be in cpp file, only header files
	template<typename WorldType>
	weak<WorldType> Application::LoadWorld()
	{
		//spawn the world
		//put {this} to constructor because "World(Application* owningApp);" requires and argument(owningApp)
		shared<WorldType> newWorld{ new WorldType{this} };
		//assign current world to newly created:
		currentWorld = newWorld; 
		return newWorld; 
		//the reasen we return newWorld (type: WorldType) and not currentWorld (type: World),
		//because return value needs to be exact same type (WorldType) 
	}
}