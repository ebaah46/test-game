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
            void Update(sf::Time dt) override;

            void UpdateVisibility(bool visible) override{ m_visible = visible;}

            void Render(std::shared_ptr<sf::RenderWindow> window) override;
        private:
            std::string m_assetPath;
            std::shared_ptr<sf::Sprite> m_tree;
            std::shared_ptr<sf::Texture> m_treeTexture;
            bool m_visible  = true;
        };
    }
}

#endif //TIMBERMAN_TREE_H

