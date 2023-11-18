//
// Created by Emmanuel Baah on 18.11.2023.
//

#ifndef TIMBERMAN_ISPRITES_H
#define TIMBERMAN_ISPRITES_H

#include "core/Utils.h"
using namespace Game::Utils;

/*
 * This is an interface provides access to the basic functionality of sprites in this game.
 *
 * */

namespace Game{
    namespace Sprites{

        class ISprite {
        public:
            ISprite();

            ~ISprite();

            /*
             * This method provides access change the geometric position of a sprite
             * in a frame.
             *
             * @param newXPosition Position value indicating the horizontal and vertical coordinates of the sprite on the screen.
             */
            virtual void UpdatePosition(Position position)  = 0;

            /*
             * This method provides access to change the visibility of a sprite.
             *
             * @param visible Boolean value indicating if the sprite is visible or not.
             */
            virtual void UpdateVisibility(bool visible)  = 0;
        };

        }
    }

#endif //TIMBERMAN_ISPRITES_H