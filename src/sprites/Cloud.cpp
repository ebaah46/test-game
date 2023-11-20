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
    m_cloudTexture = std::make_shared<sf::Texture>();
    auto isLoaded = m_cloudTexture->loadFromFile(assetPath);
    if (!isLoaded){
        // Log error at this point
    }
    m_cloud = std::make_shared<sf::Sprite>();
    m_cloud->setTexture(*m_cloudTexture);
    m_cloud->setPosition(position.x,position.y);
    m_ready = true;
}


void Cloud::Update(sf::Time dt) {
    if(m_ready){
        // Log and exit
        return;
    }
    if (!m_visible){
        srandom(time(nullptr)*10); //seed the random generator
        m_speed = static_cast<float>((arc4random() % 200));
        // how high the cloud is
        srandom(time(nullptr)*10);
        // starting position of a cloud
        auto height = static_cast<float>((arc4random() % 150)+100);
        m_cloud->setPosition(-200,height);
        m_visible = true;
    } else {
        m_cloud->setPosition(m_cloud->getPosition().x + m_speed*dt.asSeconds(),m_cloud->getPosition().y);
        // When cloud goes out of view
        if(m_cloud->getPosition().x > screenWidth){
            m_visible = false;
        }
    }
}

void Cloud::Render(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(*m_cloud);
}
