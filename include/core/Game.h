//
// Created by Emmanuel Baah on 14.11.2023.
//

#ifndef TEST_GAME_GAME_H
#define TEST_GAME_GAME_H

#include "IGame.h"
#include "sprites/ISprite.h"
#include "Hud.h"

#include <SFML/Graphics.hpp>
#include <memory>

using namespace Game::Sprites;
using namespace Game;

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
    void PauseGame();
    void StartGame();
    bool IsGamePaused();


    std::shared_ptr<sf::RenderWindow> m_window = nullptr;
    std::vector<std::shared_ptr<ISprite>> m_sprites;
    std::shared_ptr<sf::Time> m_lastUpdate;
    std::shared_ptr<sf::Clock> m_clock;
    bool m_gamePaused = false;
    bool m_playerDied = false;
    unsigned int m_timeRemaining = 0;
    std::shared_ptr<Hud>m_hud;
    int m_score = 0;
};

#endif //TEST_GAME_GAME_H
