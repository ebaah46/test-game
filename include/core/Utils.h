//
// Created by Emmanuel Baah on 18.11.2023.
//

#ifndef TIMBERMAN_ASSETS_H
#define TIMBERMAN_ASSETS_H

#include <string>

namespace Game{
    namespace Utils{
        /*
         * This method is responsible for returning the path to the assets' directory.
         * */
        static  std::string  GetAssetPath(){
            return PROJECT_PATH + std::string("/assets");
        }
        /*
         * This structure represents the position of a sprite on the screen.
         * The horizontal and vertical positions X and Y are the members of this struct
         * */
        struct Position{
            float x,y  = 0.0;
        };

        static unsigned int screenWidth = 1920u;
        static unsigned int  screenHeight = 1080u;
    }
}
#endif //TIMBERMAN_ASSETS_H

