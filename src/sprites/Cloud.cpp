//
// Created by Emmanuel Baah on 18.11.2023.
//
#include "sprites/Cloud.h"

using namespace Game;
using namespace Game::Sprites;

Cloud::Cloud(std::string &assetPath, Position position){
    if(assetPath.empty()){
        // Log error at this point
        return;
    }
    sf::Texture cloudTexture;
    auto isLoaded = cloudTexture.loadFromFile(assetPath);
    if (!isLoaded){
        // Log error at this point
    }
    m_cloud->setTexture(cloudTexture);
    m_cloud->setPosition(position.x,position.y);
}

Cloud::~Cloud(){
    // closing protocol
}

void Cloud::UpdatePosition(Game::Utils::Position position) {
    m_cloud->setPosition(position.x,position.y);
}