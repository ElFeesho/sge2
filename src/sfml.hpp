#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "graphicsadapter.hpp"
#include "inputadapter.hpp"

class SFML : public GraphicsAdapter, public InputAdapter
{
public:
    SFML();

    bool mouseDown(int button) override;
    int mouseX() override;
    int mouseY() override;
    bool shouldQuit() override;

    void open(unsigned int width, unsigned int height) override;
    void render() override;
    void drawRect(int x, int y, int w, int h, unsigned int colour) override;
private:
    sf::RenderWindow window;
};
