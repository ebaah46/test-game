//
// Created by Emmanuel Baah on 18.11.2023.
//

#include "sprites/Background.h"

using namespace Game;
using namespace Game::Sprites;

Background::Background(std::string &assetPath, Position position){
    if(assetPath.empty()){
        // Log error at this point
        return;
    }
    m_backgroundTexture = std::make_shared<sf::Texture>();
    auto isLoaded = m_backgroundTexture->loadFromFile(assetPath);
    if (!isLoaded){
        // Log error at this point
        return;
    }
    m_background = std::make_shared<sf::Sprite>();
    m_background->setTexture(*m_backgroundTexture);
    m_background->setPosition(position.x,position.y);
    m_ready = true;
}

Background::~Background() {
    // closing protocol
}

void Background::Update(sf::Time dt) {
    // no background update required for now.
}

void Background::Render(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(*m_background);
}