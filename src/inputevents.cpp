#include "inputevents.hpp"
#include <SFML/Window.hpp>
#include <functional>

using std::function;

InputEvents::InputEvents(InputAdapter *adapter) : input(adapter)
{

}

void InputEvents::processEvents(function<void()> quitEvent)
{
    if (input->shouldQuit())
    {
        quitEvent();
    }
}

int InputEvents::mouseX()
{
    return input->mouseX(); //sf::Mouse::getPosition().x;
}

int InputEvents::mouseY()
{
    return input->mouseY(); // sf::Mouse::getPosition().y;
}

int InputEvents::mouseButton()
{
    return input->mouseDown(0) ? 1 : 0; //sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
