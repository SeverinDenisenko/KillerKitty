//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_GAME_H
#define KILLERKITTY_GAME_H

#include "Scene.h"

namespace kke {

    class Game {
    public:
        explicit Game(const std::string& name);
        virtual ~Game() = default;

        void Run();

    protected:
        virtual void Setup() {}
        virtual void Shutdown() {}

        std::queue<std::unique_ptr<Scene>> sceneQueue;

        sf::RenderWindow window;
    };

} // kke

#endif //KILLERKITTY_GAME_H
