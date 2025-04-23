#include "App.h"

#include "Modules/Module.h"
#include "Modules/M_Input.h"
#include "Modules/M_Audio.h"
#include "Modules/M_Scene.h"

App* app = NULL;

void App::Init()
{
	input = make_shared<M_Input>(true);
	audio = make_shared<M_Audio>(true);
	scene = make_shared<M_Scene>(true);

	AddModule(input);
	AddModule(audio);
	AddModule(scene);

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

void App::Update(RenderWindow& window)
{
	deltaTime = deltaClock.restart().asSeconds();

	// Call PreUpdate() in all enabled modules
	for (unsigned int i = 0; i < listModules.size(); i++)
	{
		if (listModules[i]->enabled) listModules[i]->PreUpdate(window, deltaTime);
	}

	// Call Update() in all enabled modules
	for (unsigned int i = 0; i < listModules.size(); i++)
	{
		if (listModules[i]->enabled) listModules[i]->Update(window, deltaTime);
	}

	// Call PostUpdate() in all enabled modules
	for (unsigned int i = 0; i < listModules.size(); i++)
	{
		if (listModules[i]->enabled) listModules[i]->PostUpdate(window, deltaTime);
	}
}

void App::Render(RenderWindow& window)
{
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

void App::AddModule(shared_ptr<Module> module)
{
	listModules.push_back(module);
}