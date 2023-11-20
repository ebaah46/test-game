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
    m_treeTexture = std::make_shared<sf::Texture >();
    auto isLoaded = m_treeTexture->loadFromFile(assetPath);
    if (!isLoaded){
        // Log error at this point
    }
    m_tree = std::make_shared<sf::Sprite>();
    m_tree->setTexture(*m_treeTexture);
    m_tree->setPosition(position.x,position.y);
}
Tree::~Tree() {
// closing protocol
}

void Tree::Update(sf::Time dt) {

}

void Tree::Render(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(*m_tree);
}

