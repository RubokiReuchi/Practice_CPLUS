#pragma once

#include "Helpers/Globals.h"
#include "Modules/Module.h"

using namespace sf;

class App
{
public:
	// Modulos
	std::vector<Module*> listModules;

private:
	Clock deltaClock;
	float deltaTime = 0;

	Texture exampleTex;
	Sprite* exampleSprite = nullptr;

public:

	App() {}
	~App();

	void Init();
	void Update();
	void Render(sf::RenderWindow& window);
	void CleanUp();

	void AddModule(Module* module);
};

extern App* app;