//
// Created by Emmanuel Baah on 18.11.2023.
//

#include "sprites/Tree.h"

using namespace Game;
using namespace Game::Sprites;

Tree::Tree(std::string &assetPath,Position position) {
    if(assetPath.empty()){
        // Log error at this point
        return;
    }
    sf::Texture treeTexture;
    auto isLoaded = treeTexture.loadFromFile(assetPath);
    if (!isLoaded){
        // Log error at this point
    }
    m_tree->setTexture(treeTexture);
    m_tree->setPosition(position.x,position.y);
}
Tree::~Tree() {
// closing protocol
}

void Tree::UpdatePosition(Position position) {
    m_tree->setPosition(position.x,position.y);
}


