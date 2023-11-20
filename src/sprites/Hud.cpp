//
// Created by Emmanuel Baah on 20.11.2023.
//

#include "sprites/Hud.h"

using namespace Game;
using namespace Game::Sprites;


Hud::Hud(std::string &assetPath, Position position) {
    if(assetPath.empty()){
        // Log error at this point
        return;
    }
    sf::Font font;
    font.loadFromFile(assetPath);
    m_messageText = std::make_shared<sf::Text>();
    m_scoreText = std::make_shared<sf::Text>();
    m_messageText->setFont(font);
    m_scoreText->setFont(font);
    m_messageText->setCharacterSize(50);
    m_scoreText->setCharacterSize(65);
    m_messageText->setFillColor(sf::Color::White);
    m_scoreText->setFillColor(sf::Color::White);

    m_messageText->setString("Press Enter to Start!!!");
    m_scoreText->setString("Score = 0");

    sf::FloatRect textRect = m_messageText->getLocalBounds();
    m_messageText->setOrigin(textRect.left +
                          textRect.width / 2.0f,
                          textRect.top +
                          textRect.height / 2.0f);
    m_messageText->setPosition(screenWidth / 2.0f,	screenHeight / 2.0f);
    m_scoreText->setPosition(20, 20);

    // Timebar setup
    m_timeBar = std::make_shared<sf::RectangleShape>();
    m_timeBar->setFillColor(sf::Color::Red);
    m_timeBar->setSize(sf::Vector2f(m_timeBarWidth,m_timeBarHeight));
    m_timeBar->setPosition(screenWidth/(2)- m_timeBarWidth / 2,980);

}

void Hud::Update(sf::Time dt) {
    std::stringstream ss;
    ss<<"Score:"<<m_score;
    m_scoreText->setString(ss.str());
}

void Hud::Render(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(*m_scoreText);
}

void Hud::RenderMessage(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(*m_messageText);
}