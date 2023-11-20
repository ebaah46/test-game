//
// Created by Emmanuel Baah on 18.11.2023.
//

#ifndef TIMBERMAN_ISPRITES_H
#define TIMBERMAN_ISPRITES_H

#include "core/Utils.h"
#include <SFML/Graphics.hpp>
using namespace Game::Utils;

/*
 * This is an interface provides access to the basic functionality of sprites in this game.
 *
 * */

namespace Game{
    namespace Sprites{

        class ISprite {
        public:
            ISprite() =default;

            ~ISprite()=default;

            /*
             * This method provides acess to update the internal details of the sprite.
             * @param dt The time past since the last update
             * */
            virtual void Update(sf::Time dt) = 0;

            /*
             * This method provides access to change the visibility of a sprite.
             *
             * @param visible Boolean value indicating if the sprite is visible or not.
             */
            virtual void UpdateVisibility(bool visible)  = 0;

            /*
             * This method provides access to draw a sprite on the screen.
             * */
            virtual void Render(std::shared_ptr<sf::RenderWindow> window) = 0;
        };

        }
    }

#endif //TIMBERMAN_ISPRITES_H