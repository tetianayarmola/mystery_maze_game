#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{
	mz::Application* app = GetApplication();
	app->Run();
	delete app;
}