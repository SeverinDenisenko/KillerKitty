//
// Created by Severin on 07.03.2023.
//

#include "engine/Camera.h"

namespace kke {
    Camera::Camera(sf::RenderWindow& window) : window(window) {

    }

    void Camera::setSize(int width, int height) {
        sf::View defaultView = window.getDefaultView();

        float ratio = (float)width / (float)height;
        float currentWidth = defaultView.getSize().x;
        float currentHeight = defaultView.getSize().y;
        float currentRatio = currentWidth / currentHeight;

        sf::View view = sf::View(sf::FloatRect(0, 0, width, height));

        if (currentRatio > ratio){
            float offset = (1.f - (currentHeight * ratio) / currentWidth) / 2;
            view.setViewport(sf::FloatRect(offset, 0, 1 - offset * 2, 1));
        } else {
            float offset = (1.f - currentWidth / (ratio * currentHeight)) / 2;
            view.setViewport(sf::FloatRect(0, offset, 1, 1 - offset * 2));
        }

        window.setView(view);
    }
} // kke