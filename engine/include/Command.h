//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_COMMAND_H
#define KILLERKITTY_COMMAND_H

#include <functional>

#include "Entity.h"

namespace kke{
    class Entity;

    template<typename T>
    class Command {
    public:
        T category;
        std::function<void(Entity&, sf::Time)> action;
    };
}

#endif //KILLERKITTY_COMMAND_H
