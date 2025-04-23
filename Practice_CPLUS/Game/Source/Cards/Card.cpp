#include "Card.h"
#include "../App.h"
#include "../Modules/M_Input.h"

Card::Card(const string& imagePath, Vector2f position, bool startVisible = true)
{
	texture.loadFromFile(imagePath);
	sprite = make_shared<Sprite>(texture);
	originalScale = { CARD_WIDTH / (float)texture.getSize().x, CARD_HEIGHT / (float)texture.getSize().y };
	sprite->setScale(originalScale);
	sf::FloatRect bounds = sprite->getLocalBounds();
	sprite->setOrigin(Vector2f(bounds.size.x / 2.0f, bounds.size.y / 2.0f));
	sprite->setPosition(position);
	visible = startVisible;
}

void Card::Update(float dt)
{
	// Sprite Scale
	Vector2f mousePos = app->input->GetMousePosition();
	if (!mouseContained && sprite->getGlobalBounds().contains(mousePos))
	{
		mouseContained = true;
		sizeState = CARD_SIZE_STATE::INCREASE;
	}
	else if (mouseContained && !sprite->getGlobalBounds().contains(mousePos))
	{
		mouseContained = false;
		sizeState = CARD_SIZE_STATE::DECREASE;
	}

	float speed = 1 + (CARD_SIZE_VARIATION * dt);
	if (sizeState == CARD_SIZE_STATE::INCREASE)
	{
		Vector2f newScale = sprite->getScale() * speed;
		if (newScale.x >= originalScale.x * 1.2f)
		{
			newScale = originalScale * 1.2f;
			sizeState = CARD_SIZE_STATE::IDLE;
		}
		sprite->setScale(newScale);
	}
	else if (sizeState == CARD_SIZE_STATE::DECREASE)
	{
		Vector2f newScale = sprite->getScale() / speed;
		if (newScale.x <= originalScale.x)
		{
			newScale = originalScale;
			sizeState = CARD_SIZE_STATE::IDLE;
		}
		sprite->setScale(newScale);
	}

	// Sprite Position
	if (mouseContained && !mouseBinded && app->input->GetMouseButtonState(Mouse::Button::Left) == KEY_DOWN)
	{
		mouseBinded = true;
		mouseOffset = mousePos - sprite->getPosition();
	}
	if (mouseBinded && app->input->GetMouseButtonState(Mouse::Button::Left) == KEY_UP) mouseBinded = false;
	if (mouseBinded) sprite->setPosition(app->input->GetMousePosition() - mouseOffset);
}

void Card::Render(RenderWindow& window)
{
	if (!visible) return;
	window.draw(*sprite);
}

void Card::SetVisibility(bool visible)
{
	this->visible = visible;
}

void Card::ToggleVisibility()
{
	visible = !visible;
}