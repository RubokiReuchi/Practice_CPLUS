#pragma once

#include "Module.h"
#include "../Cards/Card.h"

class M_Scene : public Module
{
public:
	M_Scene(bool start_enabled);
	~M_Scene();

	void Update(RenderWindow& window, float dt);
	void Render(RenderWindow& window);

	vector<unique_ptr<Card>> cards;

private:
};