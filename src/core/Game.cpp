//
// Created by Emmanuel Baah on 14.11.2023.
//

#include "core/Game.h"
#include "core/Utils.h"

using namespace Game::Utils;

GameEngine::GameEngine(){
    if(!m_window){
        m_window = std::make_shared<sf::RenderWindow>(
                sf::VideoMode(screenWidth, screenHeight), "Timberman"
        );
        m_window->setFramerateLimit(144);
    }
}

void GameEngine::ProcessEvents() const {
    while(m_window->isOpen()){
        for (auto event = sf::Event{}; m_window->pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                m_window->close();
            }
        }
    }
}

void GameEngine::Run() const {
    while(m_window->isOpen()){
        ProcessEvents();
        Update();
        Render();
    }
}

void GameEngine::Update() const {
    for (auto &sprite: m_sprites){
        sprite->Update(m_lastUpdate);
    }
}

void GameEngine::Render() const {
    for(auto &sprite: m_sprites){
        sprite->Render();
    }
}