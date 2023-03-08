//
// Created by Severin on 08.03.2023.
//

#ifndef KILLERKITTY_MAINMENU_H
#define KILLERKITTY_MAINMENU_H

#include <Scene.h>

#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/EditBox.hpp"

class MainMenu : public kke::Scene{
public:
    explicit MainMenu(sf::RenderWindow& renderWindow) : kke::Scene(renderWindow){}

    void Construct() override{
        camera.setSize(15 * 16, 12 * 16);

        auto button = tgui::Button::create();
        button->setText("Hello!");
        button->setSize("30%", "10%");
        button->getRenderer()->setBackgroundColor(sf::Color(255, 0, 0, 255));
        gui.add(button);
    }

    void ProcessInputs() override{
        if (eventSystem.IsKeyPressed(sf::Keyboard::Escape)) {
            Running = false;
        }
    }
};


#endif //KILLERKITTY_MAINMENU_H
