//
// Created by Emmanuel Baah on 18.11.2023.
//

#ifndef TIMBERMAN_CLOUDSPRITE_H
#define TIMBERMAN_CLOUDSPRITE_H

#include "ISprite.h"
#include <SFML/Graphics.hpp>


#include <vector>
#include <memory>
#include <string>


namespace Game{
    namespace Sprites{

        class Cloud : public ISprite {
        public:
            Cloud(std::string &assetPath, Position position);

            ~Cloud() = default;

            void Update(sf::Time dt) override;

            void UpdateVisibility(bool visible)  override { m_visible = true; }

        private:
            std::string m_assetPath;
            std::shared_ptr<sf::Sprite> m_cloud;
            bool m_visible = false;
            float m_speed = 0.0;
            bool m_ready = false;
        };
    }

}
#endif //TIMBERMAN_CLOUDSPRITE_H
