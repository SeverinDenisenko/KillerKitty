//
// Created by Severin on 06.03.2023.
//

#ifndef KILLERKITTY_GAME_H
#define KILLERKITTY_GAME_H

#include "Entity.h"
#include "ResourceHolder.h"

namespace kke {

    class Game {
    public:
        Game(const std::string& name);
        virtual ~Game() = default;

        void Run();

        ResourceHolder<sf::Texture, std::string> textures;
        Entity root;
        sf::Time deltaTime;

        bool Running = true;

    protected:
        virtual void Setup() {}
        virtual void Update();
        virtual void Render();
        virtual void Shutdown() {}
        virtual void ProcessInputs();

        sf::RenderWindow window;
        sf::Clock clock;
    };

} // kke

#endif //KILLERKITTY_GAME_H
