//
// Created by Emmanuel Baah on 20.11.2023.
//

#include "core/Hud.h"
#include "core/Utils.h"

using namespace Game;
using namespace Game::Utils;


Hud::Hud(std::string &assetPath) {
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
    m_timeBar->setPosition(screenWidth/(2.0)- m_timeBarWidth / 2.0,980);

}

void Hud::Update(sf::Time dt) {
    std::stringstream ss;
    ss<<"Score:"<<m_score;
    m_scoreText->setString(ss.str());
    m_timeRemaining -= dt.asSeconds();
    m_timeBar->setSize(sf::Vector2f(m_timeBarWithSecond * m_timeRemaining,m_timeBarHeight));
    if(m_timeRemaining <= 0.0f){
        // pause game
        // trigger game pause event
    }
}

void Hud::Render(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(*m_scoreText);
}

void Hud::RenderMessage(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(*m_messageText);
}

void Hud::ResetGameData(){
    m_timeRemaining = 6.0;
    m_score = 0.0;
}
