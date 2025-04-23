#pragma once

#include "../Helpers/Globals.h"

#define CARD_WIDTH 150
#define CARD_HEIGHT 250
#define CARD_SIZE_VARIATION 1.2f

enum CARD_SIZE_STATE {
	IDLE,
	INCREASE,
	DECREASE
};

class Card {
public:
	Card(const string& imagePath, Vector2f position, bool startVisible);
	~Card() {}

	void Update(float dt);
	void Render(RenderWindow& window);
	void SetVisibility(bool visible);
	void ToggleVisibility();

	void ChangeSizeState(CARD_SIZE_STATE state)
	{
		sizeState = state;
	}

	void BindState(bool state)
	{
		mouseBinded = state;
	}

private:
	Texture texture;
	shared_ptr<Sprite> sprite;
	bool visible;

	Vector2f originalScale;
	CARD_SIZE_STATE sizeState = IDLE;
	bool mouseContained = false;
	bool mouseBinded = false;
	Vector2f mouseOffset;
};