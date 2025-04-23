#include "Helpers/Globals.h"
#include "App.h"

int main(int argc, char** argv)
{
	Console::print("Starting game 'Practice C++'");

    srand(time(NULL));

    app = new App();

    app->Init();
    
    // Crear una ventana
    RenderWindow window(VideoMode({800, 600}, 32), "Mi Juego 2D");

    // Frame Limit
    window.setFramerateLimit(60);
    
    // Bucle principal
    while (window.isOpen())
    {
        app->Update(window);

        // Process events
        while (const optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        // Render
        app->Render(window);

        // Update the window
        window.display();
    }

	delete app;
	Console::print("Exiting game 'Practice C++'");
	return 0;
}