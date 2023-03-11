//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_CAMERA_H
#define KILLERKITTY_CAMERA_H

#include "SFML/Graphics.hpp"

namespace kke {

    class Camera {
    public:
        explicit Camera(sf::RenderWindow& window);
        void setSize(int width, int height);

    private:

        sf::RenderWindow& window;
    };

} // kke

#endif //KILLERKITTY_CAMERA_H
