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
    sf::Texture backgroundTexture;
    auto isLoaded = backgroundTexture.loadFromFile(assetPath);
    if (!isLoaded){
        // Log error at this point
        return;
    }
    m_background->setTexture(backgroundTexture);
    m_background->setPosition(position.x,position.y);
}

Background::~Background() {
    // closing protocol
}

void Background::Update(sf::Time dt) {
    // no background update required for now.
}
