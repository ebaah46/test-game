//
// Created by Emmanuel Baah on 18.11.2023.
//

#include "sprites/Bee.h"

using namespace Game;
using namespace Game::Sprites;


Bee::Bee(std::string &assetPath, Position position) {
    if(assetPath.empty()){
        // Log error at this point
        return;
    }
    m_beeTexture = std::make_shared<sf::Texture>();
    auto isLoaded = m_beeTexture->loadFromFile(assetPath);
    if (!isLoaded){
        // Log error at this point
    }
    m_bee = std::make_shared<sf::Sprite>();
    m_bee->setTexture(*m_beeTexture);
    m_bee->setPosition(position.x,position.y);
    m_ready = true;
}

void Bee::Update(sf::Time dt) {
    // Bee moves from right to left
    if(!m_ready){
        // Log and exit
        return;
    }
    // Before the bee is initially drawn in the view area
    if (!m_visible){
        srandom(time(nullptr)*10); //seed the random generator
        m_speed = static_cast<float>((arc4random() % 200) + 200);
        // how high the bee is
        srandom(time(nullptr)*10);
        // starting position of a bee
        auto height = static_cast<float>((arc4random() % 500) + 500);
        auto width = static_cast<float>(screenWidth);
        m_bee->setPosition(width,height);
        m_visible = true;
    } else {
        m_bee->setPosition(m_bee->getPosition().x - m_speed*dt.asSeconds(),m_bee->getPosition().y);
        // At the edge of the screen, bee must restart route to new bee illusion
        if(m_bee->getPosition().x < -100){
            m_visible = false;
        }
    }
}

void Bee::Render(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(*m_bee);
}
