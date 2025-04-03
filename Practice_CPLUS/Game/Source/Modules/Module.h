#pragma once

#include "../Helpers/Globals.h"

class Application;

class Module
{
public:
	Module(bool start_enabled = true)
	{
		enabled = start_enabled;
	}

	virtual ~Module() {}

	// Call it when Module is created
	virtual void Init() {}

	// Called when module is set active
	virtual void Start() {}

	virtual void PreUpdate(float dt) {}

	virtual void Update(float dt) {}

	virtual void PostUpdate(float dt) {}

	virtual void Render(sf::RenderWindow& window) {}

	virtual void CleanUp() {}

	bool enabled;
};