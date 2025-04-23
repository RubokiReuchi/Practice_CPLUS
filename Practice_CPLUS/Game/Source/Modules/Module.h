#pragma once

#include "../Helpers/Globals.h"
#include "../App.h"

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

	virtual void PreUpdate(RenderWindow& window, float dt) {}

	virtual void Update(RenderWindow& window, float dt) {}

	virtual void PostUpdate(RenderWindow& window, float dt) {}

	virtual void Render(RenderWindow& window) {}

	virtual void CleanUp() {}

	bool enabled;
};