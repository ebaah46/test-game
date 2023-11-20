//
// Created by Emmanuel Baah on 14.11.2023.
//

#include "core/Game.h"
#include "core/Utils.h"
#include "sprites/Background.h"
#include "sprites/Tree.h"
#include "sprites/Bee.h"
#include "sprites/Cloud.h"

#include "iostream"

using namespace Game::Utils;
using namespace Game::Sprites;

GameEngine::GameEngine(){
    if(!m_window){
        m_window = std::make_shared<sf::RenderWindow>(
                sf::VideoMode(screenWidth, screenHeight), "Timberman"
        );
        m_window->setFramerateLimit(144);
    }
}

void GameEngine::Setup() {
    // Initialize all sprites in game

    std::string bp(backgroundPath);
    auto background = std::make_shared<Background>(bp,Position{0.0f,0.0f});

    std::string tp(treePath);
    auto tree = std::make_shared<Tree>(tp,Position{810.0f,0.0f});

    std::string bPath(beePath);
    auto bee = std::make_shared<Bee>(bPath,Position{0.0f,800.0f});

    std::string cP(cloudPath);
    auto cloud1 = std::make_shared<Cloud>(cP, Position{0.0,150});
    auto cloud2 = std::make_shared<Cloud>(cP, Position{0.0,250});
    auto cloud3 = std::make_shared<Cloud>(cP, Position{0.0,50});

    m_sprites.emplace_back(background);
    m_sprites.emplace_back(tree);
    m_sprites.emplace_back(bee);
    m_sprites.emplace_back(cloud1);
    m_sprites.emplace_back(cloud2);
    m_sprites.emplace_back(cloud3);
}

void GameEngine::ProcessEvents() const {
    for (auto event = sf::Event{}; m_window->pollEvent(event);){
        if (event.type == sf::Event::Closed){
            m_window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            m_window->close();
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){

        }

    }
}

void GameEngine::Run() const {
    while(m_window->isOpen()){
        ProcessEvents();
        Update();
        m_window->clear();
        Render();
        m_window->display();
    }
}

void GameEngine::Update() const {
    for (auto &sprite: m_sprites){
        sprite->Update(m_lastUpdate);
    }
}

void GameEngine::Render() const {
    for(auto &sprite: m_sprites){
        sprite->Render(m_window);
    }
}