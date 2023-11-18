//
// Created by Emmanuel Baah on 14.11.2023.
//

#include "core/Game.h"

Game::Game(){
    auto m_window = sf::RenderWindow{ { 1920u, 1080u }, "TimberMan " };
    m_window.setFramerateLimit(144);
}

void Game::ProcessEvents() const {
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

void Game::Run() const {
    while(m_window->isOpen()){
        ProcessEvents();
        Update();
        Render();
    }
}

void Game::Update() const {

}

void Game::Render() const {

}