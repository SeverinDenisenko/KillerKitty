//
// Created by Severin on 08.03.2023.
//

#ifndef KILLERKITTY_MAINMENU_H
#define KILLERKITTY_MAINMENU_H

#include "engine/Scene.h"

#include "TestScene.h"

class MainMenu : public kke::Scene{
public:
    explicit MainMenu(kke::Game& game) : kke::Scene(game){}

    void Construct() override{
    }

    void ProcessInputs() override{
        if (eventSystem.IsKeyPressed(sf::Keyboard::Escape)) {
            Running = false;
        }
    }
};


#endif //KILLERKITTY_MAINMENU_H
