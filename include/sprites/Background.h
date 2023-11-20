//
// Created by Emmanuel Baah on 18.11.2023.
//

#ifndef TIMBERMAN_BACKGROUNDSPRITE_H
#define TIMBERMAN_BACKGROUNDSPRITE_H

#include "ISprite.h"
#include <SFML/Graphics.hpp>


#include <vector>
#include <memory>
#include <string>

namespace Game {
    namespace Sprites{

        class Background : public ISprite {
        public:
            Background(std::string &assetPath, Position position);

            ~Background();

            void Update(sf::Time dt) override;

            void UpdateVisibility(bool visible)  override { m_visible = visible; }

            void Render(std::shared_ptr<sf::RenderWindow> window) override;

        private:
            std::string m_assetPath;
            std::shared_ptr<sf::Sprite> m_background = nullptr;
            std::shared_ptr<sf::Texture> m_backgroundTexture = nullptr;
            bool m_visible = true;
            bool m_ready = false;
        };
    }
}

#endif //TIMBERMAN_BACKGROUNDSPRITE_H
