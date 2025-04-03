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
	///////////////////
	// Call Init() in all modules
	for (int i = 0; i < listModules.size(); i++)
	{
		listModules[i]->Init();
	}

	// Call Start() in all enabled modules
	for (unsigned int i = 0; i < listModules.size(); i++)
	{
		if (listModules[i]->enabled) listModules[i]->Start();
	}
}

void App::Update()
{
	deltaTime = deltaClock.restart().asSeconds();

	// Call PreUpdate() in all enabled modules
	for (unsigned int i = 0; i < listModules.size(); i++)
	{
		if (listModules[i]->enabled) listModules[i]->PreUpdate(deltaTime);
	}

	// Call Update() in all enabled modules
	for (unsigned int i = 0; i < listModules.size(); i++)
	{
		if (listModules[i]->enabled) listModules[i]->Update(deltaTime);
	}

	// Call PostUpdate() in all enabled modules
	for (unsigned int i = 0; i < listModules.size(); i++)
	{
		if (listModules[i]->enabled) listModules[i]->PostUpdate(deltaTime);
	}
}

void App::Render(RenderWindow& window)
{
	window.draw(*exampleSprite);
	//////////
	// Call Render() in all enabled modules
	for (unsigned int i = 0; i < listModules.size(); i++)
	{
		if (listModules[i]->enabled) listModules[i]->Render(window);
	}
}

void App::CleanUp()
{
	// Call CleanUp() in all modules
	for (unsigned int i = 0; i < listModules.size(); i++)
	{
		listModules[i]->CleanUp();
	}
}

void App::AddModule(Module* module)
{
	listModules.push_back(module);
}