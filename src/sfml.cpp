#include "sfml.hpp"

SFML::SFML()
{
}

bool SFML::mouseDown(int button)
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

int SFML::mouseX()
{
    return sf::Mouse::getPosition(window).x;
}

int SFML::mouseY()
{
    return sf::Mouse::getPosition(window).y;
}

bool SFML::shouldQuit()
{
    sf::Event event;

    // while there are pending events...
    while (window.pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
            case sf::Event::Closed:
                return true;
            break;
        }
    }

    return false;
}

void SFML::open(unsigned int width, unsigned int height)
{
    window.setVerticalSyncEnabled(true);
    window.create(sf::VideoMode(width, height), "SGE2");
}

void SFML::render()
{
    window.display();
}

void SFML::drawRect(int x, int y, int w, int h, unsigned int color)
{
    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(w, h));
    shape.setPosition(sf::Vector2f(x, y));
    shape.setFillColor(sf::Color(static_cast<sf::Uint32>(color)));
    window.draw(shape);
}




