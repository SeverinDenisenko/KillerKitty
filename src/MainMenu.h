//
// Created by Severin on 08.03.2023.
//

#ifndef KILLERKITTY_MAINMENU_H
#define KILLERKITTY_MAINMENU_H

#include "engine/Scene.h"
#include "engine/UI/Button.h"

#include "TestScene.h"

class MainMenu : public kke::Scene{
public:
    explicit MainMenu(kke::Game& game) : kke::Scene(game){}

    std::unique_ptr<kke::Button> exitButton;
    std::unique_ptr<kke::Button> playButton;

    void Construct() override{
        exitButton = std::make_unique<kke::Button>(0, 0, 100, 100, ui);
        playButton = std::make_unique<kke::Button>(100, 0, 100, 100, ui);
    }

    void ProcessInputs() override{
        if (eventSystem.IsKeyPressed(sf::Keyboard::Escape)) {
            Running = false;
        }

        if (exitButton->pressed){
            Running = false;
        }

        if (playButton->pressed){
            Running = false;
            game.AddScene(std::make_unique<TestScene>(game));
        }
    }
};


#endif //KILLERKITTY_MAINMENU_H
