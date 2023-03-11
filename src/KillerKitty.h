//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_KILLERKITTY_H
#define KILLERKITTY_KILLERKITTY_H

#include "engine/Game.h"
#include "TestScene.h"
#include "MainMenu.h"

class KillerKitty : public kke::Game{
public:
    KillerKitty() : kke::Game("Killer Kitty") {}

protected:
    void Setup() override{
        kke::Game::Setup();

        AddScene(std::make_unique<MainMenu>(*this));
    }

    void Shutdown() override{
        kke::Game::Shutdown();
    }
};


#endif //KILLERKITTY_KILLERKITTY_H
