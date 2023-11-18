//
// Created by Emmanuel Baah on 18.11.2023.
//

#ifndef TIMBERMAN_BEESPRITE_H
#define TIMBERMAN_BEESPRITE_H

#include "ISprite.h"
#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <string>

namespace Game{
    namespace Sprites{

        class Bee : public ISprite {
        public:
            Bee(std::string &assetPath, Position position);

            ~Bee() = default;

            void Update(sf::Time dt) override;

            void UpdateVisibility(bool visible)  override{m_visible = visible;};

        private:
            std::string m_assetPath;
            std::shared_ptr<sf::Sprite> m_bee;
            bool m_visible = false;
            float m_speed = 0.0;
            bool m_ready = false;
        };
    }
}
#endif //TIMBERMAN_BEESPRITE_H
