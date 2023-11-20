//
// Created by Emmanuel Baah on 20.11.2023.
//

#ifndef TIMBERMAN_HUD_H
#define TIMBERMAN_HUD_H

#include "ISprite.h"
#include <sstream>
#include "SFML/Graphics.hpp"


namespace Game {
    namespace Sprites{

        /*
         * This class provides access to the game status and game play information
         * */
        class Hud : ISprite{
        public:
            Hud(std::string &assetPath, Position position);
            ~Hud() = default;
            void Update(sf::Time dt) override;
            void UpdateVisibility(bool visible)  override { m_visible = visible; }

            void Render(std::shared_ptr<sf::RenderWindow> window) override;
            void RenderMessage(std::shared_ptr<sf::RenderWindow> window);
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
    }

} // Game

#endif //TIMBERMAN_HUD_H
