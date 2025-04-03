#pragma once

#include "Helpers/Globals.h"

using namespace sf;

class App
{
public:
	// Modulos
	std::vector</*Module*/int*> listModules;
private:

	// relacionado con el frametime
	Texture exampleTex;
	Sprite* exampleSprite = nullptr;

public:

	// relacionado con el frametime

	App() {}
	~App();

	void Init();
	void Update();
	void Render(sf::RenderWindow& window);
	void CleanUp();

	void AddModule(/*Module*/int* module);
};

extern App* app;