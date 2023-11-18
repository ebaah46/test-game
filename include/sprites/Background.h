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

            void UpdatePosition(Position position)  override;

            void UpdateVisibility(bool visible)  override{m_visible = visible;}

        private:
            std::string m_assetPath;
            std::shared_ptr<sf::Sprite> m_background;
            bool m_visible = false;
        };
    }
}

#endif //TIMBERMAN_BACKGROUNDSPRITE_H
