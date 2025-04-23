#include "M_Scene.h"
#include "M_Input.h"
#include "M_Audio.h"

M_Scene::M_Scene(bool start_enabled) : Module(start_enabled)
{
	Console::print("Module Scene Init");

	cards.push_back(make_unique<Card>("Assets/Sprites/example.png", Vector2f{100,100}, true));
}

M_Scene::~M_Scene() {}

void M_Scene::Update(RenderWindow& window, float dt)
{
	for (auto& card : cards)
	{
		card->Update(dt);
	}
}

void M_Scene::Render(RenderWindow& window)
{
	for (auto& card : cards)
	{
		card->Render(window);
	}
}