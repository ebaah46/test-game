//
// Created by Emmanuel Baah on 14.11.2023.
//

#ifndef TEST_GAME_GAME_H
#define TEST_GAME_GAME_H

#include "IGame.h"
#include "sprites/ISprite.h"

#include <SFML/Graphics.hpp>
#include <memory>

using namespace Game::Sprites;

class GameEngine :public IGame{

public:
    GameEngine();
    void Setup();
public:
    // from IGame
    void Run() const override;
    void ProcessEvents() const override;
    void Update() const override;
    void Render() const override;
private:
    std::shared_ptr<sf::RenderWindow> m_window = nullptr;
    std::vector<std::shared_ptr<ISprite>> m_sprites;
    sf::Time m_lastUpdate;

};

#endif //TEST_GAME_GAME_H
