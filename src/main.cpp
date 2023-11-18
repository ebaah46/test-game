//
// Created by Emmanuel Baah on 14.11.2023.
//
//#include "core/Game.h"
#include <SFML/Graphics.hpp>
int main() {

    auto window = sf::RenderWindow{ { 1920u, 1080u }, "Timberman" };
    window.setFramerateLimit(144);
    sf::Texture textureBackground;
//    auto projectPath = std::getenv("PROJECT_PATH");

    std::string backgroundPath = "/assets/graphics/background.png";
    backgroundPath = PROJECT_PATH +backgroundPath;
    textureBackground.loadFromFile(backgroundPath);
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0,0);
   while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(spriteBackground);
        window.display();
    }
/*    auto window = sf::RenderWindow(sf::VideoMode(1920u, 1080u), "SFML window");
    window.setFramerateLimit(144);
*/


}