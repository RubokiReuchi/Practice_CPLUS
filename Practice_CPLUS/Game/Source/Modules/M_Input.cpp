#include "M_Input.h"

M_Input::M_Input(bool start_enabled) : Module(start_enabled)
{
    Console::print("Module Input Init");

    for (int i = 0; i < Keyboard::KeyCount; ++i) {
        keyStates[i] = KEY_IDLE;
    }

    for (int i = 0; i < Mouse::ButtonCount; ++i) {
        mouseButtonStates[i] = KEY_IDLE;
    }
}

M_Input::~M_Input() {}

void M_Input::PreUpdate(RenderWindow& window, float dt)
{
    // Keyboard
    for (int i = 0; i < Keyboard::KeyCount; ++i) {
        if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(i)))
        {
            if (keyStates[i] == KEY_IDLE) keyStates[i] = KEY_DOWN;
            else if (keyStates[i] == KEY_DOWN) keyStates[i] = KEY_REPEAT;
        }
        else {
            if (keyStates[i] == KEY_DOWN || keyStates[i] == KEY_REPEAT) keyStates[i] = KEY_UP;
            else if (keyStates[i] == KEY_UP) keyStates[i] = KEY_IDLE;
        }
    }

    // Mouse
    for (int i = 0; i < Mouse::ButtonCount; ++i) {
        if (Mouse::isButtonPressed(static_cast<Mouse::Button>(i)))
        {
            if (mouseButtonStates[i] == KEY_IDLE) mouseButtonStates[i] = KEY_DOWN;
            else if (mouseButtonStates[i] == KEY_DOWN) mouseButtonStates[i] = KEY_REPEAT;
        }
        else {
            if (mouseButtonStates[i] == KEY_DOWN || mouseButtonStates[i] == KEY_REPEAT) mouseButtonStates[i] = KEY_UP;
            else if (mouseButtonStates[i] == KEY_UP) mouseButtonStates[i] = KEY_IDLE;
        }
    }

    mousePos = Mouse::getPosition(window);
}

KeyState M_Input::GetKeyState(Keyboard::Key key) const
{
    return keyStates[static_cast<int>(key)];
}

KeyState M_Input::GetMouseButtonState(Mouse::Button button) const
{
    return mouseButtonStates[static_cast<int>(button)];
}

Vector2f M_Input::GetMousePosition() const
{
    return Vector2f(mousePos);
}