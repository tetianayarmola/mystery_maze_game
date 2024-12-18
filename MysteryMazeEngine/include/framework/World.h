#pragma once
#include "framework/Core.h" //to be able to use weak/smart pointer

#include <SFML/Graphics.hpp>

namespace mz 
{
	//declare classes World owning so World can work with it
	class Actor;
	class Ghost;
	class World;
	class Application; //declare class which World will belong to
	//Also declare class World in Application.h to tell it how to work with World.

	class World
	{
	public:
		//specify that Application is the owner of World
		World(Application* ownedByApp);

		//function to Begin the World
		void StartPlayInternal(); //template function (core logic, not modifiable)

		//function to Tick the World
		void TickInternal(float deltaTime); //template function (core logic, not modifiable)

		// & - takes RenderWindow as a reference
		void Render(sf::RenderWindow& window);

		//when we need smth to be inherited, we need a virtual destructor:
		virtual ~World();

		template <typename ActorType>
		weak<ActorType> SpawnActor();
		/*{
			shared<ActorType> newActor{ new ActorType{this} };
			_mPendingActors.push_back(newActor);
			return newActor;
		}*/ //it can be implemented in different part of the code below

		sf::Vector2u GetWindowSize() const;

	private:
		//customer modifiable
		void StartPlay(); 
		void Tick(float deltaTime);

		//specify owner locally as well
		Application* _mOwnedByApp;
		bool _mStartedPlay;


		//Actors spawn logic and pointers
		/*separated actors list for pending so it is not causing
		size issues while we are looping through _mActors list*/
		List<shared<Actor>> _mActors;
		List<shared<Actor>> _mPendingActors;

	};

	template<typename ActorType>
	weak<ActorType> World::SpawnActor()
	{
		//initialise newActor with new ActorType and pass with World to constructor
		shared<ActorType> newActor{ new ActorType{this} };
		_mPendingActors.push_back(newActor);
		return newActor;
	}
}