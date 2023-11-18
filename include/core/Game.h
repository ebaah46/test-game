//
// Created by Emmanuel Baah on 14.11.2023.
//

#ifndef TEST_GAME_GAME_H
#define TEST_GAME_GAME_H

#include "IGame.h"

#include <SFML/Graphics.hpp>
#include <memory>


class Game :public IGame{

public:
    Game();
    // from IGame
    void Run() const override;
    void ProcessEvents() const override;
    void Update() const override;
    void Render() const override;
private:
    std::shared_ptr<sf::RenderWindow> m_window = nullptr;
};

#endif //TEST_GAME_GAME_H
