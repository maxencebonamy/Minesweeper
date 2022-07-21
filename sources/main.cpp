#include "grid.h"
#include <time.h>


int main() {
    srand(time(0));

    sf::VideoMode videoMode { (unsigned int)WINDOW_SIZE.getX(), (unsigned int)WINDOW_SIZE.getY() };
    sf::RenderWindow window(videoMode, WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(WINDOW_FPS);

    sf::Image icon;
    icon.loadFromFile("dependencies/assets/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Grid grid;
    sf::Mouse mouse;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            else if (event.type == sf::Event::MouseButtonPressed) grid.updateEvents(mouse, window);
        }

        window.clear();

        grid.display(window);

        window.display();
    }

    return EXIT_SUCCESS;
}