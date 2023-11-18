//
// Created by Emmanuel Baah on 18.11.2023.
//

#ifndef TIMBERMAN_TREE_H
#define TIMBERMAN_TREE_H


#include "ISprite.h"
#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <string>

namespace Game {
    namespace Sprites{

        class Tree : public ISprite {
        public:
            Tree(std::string &assetPath, Position position);

            ~Tree();

            void UpdatePosition(Position position) override;

            void UpdateVisibility(bool visible) override{ m_visible = visible;}

        private:
            std::string m_assetPath;
            std::shared_ptr<sf::Sprite> m_tree;
            bool m_visible  = false;
        };
    }
}

#endif //TIMBERMAN_TREE_H

