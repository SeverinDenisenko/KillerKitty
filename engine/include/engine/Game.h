//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_GAME_H
#define KILLERKITTY_GAME_H

#include "Scene.h"

namespace kke {

    class Scene;

    class Game {
    public:
        explicit Game(const std::string& name);
        virtual ~Game() = default;

        void Run();

        void AddScene(std::unique_ptr<Scene> scene);

        sf::RenderWindow& GetWindow();
        bool Running = false;
    protected:
        virtual void Setup() {}
        virtual void Shutdown() {}
    private:
        std::queue<std::unique_ptr<Scene>> sceneQueue;
        sf::RenderWindow window;
    };

} // kke

#endif //KILLERKITTY_GAME_H
