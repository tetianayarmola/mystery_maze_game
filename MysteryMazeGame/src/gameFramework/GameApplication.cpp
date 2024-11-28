#include "gameFramework/GameApplication.h"

mz::Application* GetApplication()
{
	return new mz::GameApplication{};
}

namespace mz
{

}

//there is no main function in game files, it is hidden(encaplulated) in Engine so main is like a Template Function now
//but the main function in GameEngine Entry point files requires GetApplication() function from Game folder files