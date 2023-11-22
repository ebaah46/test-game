//
// Created by Emmanuel Baah on 20.11.2023.
//

#ifndef TIMBERMAN_HUD_H
#define TIMBERMAN_HUD_H

#include <sstream>
#include "SFML/Graphics.hpp"


namespace Game {

    /*
     * This class provides access to the game status and game play information
     * */
    class Hud{
    public:
        Hud(std::string &assetPath);
        ~Hud() = default;
        void Update(sf::Time dt);
        void UpdateVisibility(bool visible) { m_visible = visible; }

        void Render(std::shared_ptr<sf::RenderWindow> window);
        void RenderMessage(std::shared_ptr<sf::RenderWindow> window);

    public:
        void ResetGameData();
        float GetTimeRemaining() const { return m_timeRemaining;};
        float GetScore() const { return m_score;};
    private:
        bool m_visible = false;
        int m_score = 0;
        std::shared_ptr<sf::RectangleShape> m_timeBar;
        float m_timeBarWidth = 400;
        const float m_timeBarHeight = 80;
        float m_timeRemaining = 6;
        float m_timeBarWithSecond;
        std::shared_ptr<sf::Time> m_gameTimeTotal;
        std::shared_ptr<sf::Text> m_scoreText;
        std::shared_ptr<sf::Text> m_messageText;

    };
} // Game

#endif //TIMBERMAN_HUD_H
