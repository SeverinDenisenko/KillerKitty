//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_KILLERKITTY_H
#define KILLERKITTY_KILLERKITTY_H

#include <Game.h>
#include <Command.h>

#include "CharacterMover.h"

class KillerKitty : public kke::Game{
public:
    KillerKitty() : kke::Game("Killer Kitty") {}

protected:
    void Setup() override;

    void ProcessInputs() override;

    void Shutdown() override{
        kke::Game::Shutdown();


    }
};


#endif //KILLERKITTY_KILLERKITTY_H
