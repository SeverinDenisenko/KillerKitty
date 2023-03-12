//
// Created by Severin on 08.03.2023.
//

#ifndef KILLERKITTY_MAINMENU_H
#define KILLERKITTY_MAINMENU_H

#include "engine/Scene.h"
#include "engine/UI/Button.h"

class MainMenu : public kke::Scene{
public:
    explicit MainMenu(kke::Game& game) : kke::Scene(game){}

    void Construct() override;

    void ProcessInputs() override;
};


#endif //KILLERKITTY_MAINMENU_H
