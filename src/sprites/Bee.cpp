//
// Created by Emmanuel Baah on 18.11.2023.
//

#include "sprites/Bee.h"

using namespace Game;
using namespace Game::Sprites;


Bee::Bee(std::string &assetPath, Game::Utils::Position position) {
    if(assetPath.empty()){
        // Log error at this point
        return;
    }
    sf::Texture beeTexture;
    auto isLoaded = beeTexture.loadFromFile(assetPath);
    if (!isLoaded){
        // Log error at this point
    }
    m_bee->setTexture(beeTexture);
    m_bee->setPosition(position.x,position.y);
}

Bee::~Bee(){
    // closing protocol
}

void Bee::UpdatePosition(Game::Utils::Position position) {
    m_bee->setPosition(position.x,position.y);
}