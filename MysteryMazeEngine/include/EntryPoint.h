#pragma once

namespace mz
{
	class Application;
}
//extern means that this needs to be implemented somewhere else (in GameApplication.h and GameApplication.cpp)
 extern mz::Application* GetApplication(); 