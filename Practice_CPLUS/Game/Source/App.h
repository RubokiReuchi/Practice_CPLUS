#pragma once

#include "Helpers/Globals.h"

class Module;
class M_Input;
class M_Audio;
class M_Scene;

class App
{
public:
	// Modulos
	vector<shared_ptr<Module>> listModules;

	shared_ptr<M_Input> input;
	shared_ptr<M_Audio> audio;
	shared_ptr<M_Scene> scene;

private:
	Clock deltaClock;
	float deltaTime = 0;

public:

	App() {}
	~App() {}

	void Init();
	void Update(RenderWindow& window);
	void Render(RenderWindow& window);
	void CleanUp();

	void AddModule(shared_ptr<Module> module);
};

extern App* app;