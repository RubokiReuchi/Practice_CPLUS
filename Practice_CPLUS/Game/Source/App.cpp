#include "App.h"

App* app = NULL;

App::~App()
{
	for (int i = listModules.size() - 1; i >= 0; --i)
	{
		delete listModules[i];
		listModules[i] = nullptr;
	}

	listModules.clear();
}

void App::Init()
{
	exampleTex.loadFromFile("Assets/Sprites/example.png");
	exampleSprite = new Sprite(exampleTex);
}

void App::Update()
{
	
}

void App::Render(RenderWindow& window)
{
	window.draw(*exampleSprite);
}

void App::CleanUp()
{
	
}

void App::AddModule(/*Module*/int* module)
{
	listModules.push_back(module);
}