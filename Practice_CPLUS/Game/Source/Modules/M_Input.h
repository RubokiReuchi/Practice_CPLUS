#pragma once

#include "Module.h"

enum KeyState
{
	KEY_IDLE,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class M_Input : public Module
{
public:
	M_Input(bool start_enabled);
	~M_Input();

	void PreUpdate(RenderWindow& window, float dt);

	KeyState GetKeyState(Keyboard::Key key) const;
	KeyState GetMouseButtonState(Mouse::Button button) const;
	Vector2f GetMousePosition() const;

private:
	KeyState keyStates[Keyboard::KeyCount];
	KeyState mouseButtonStates[Mouse::ButtonCount];
	Vector2i mousePos;
};