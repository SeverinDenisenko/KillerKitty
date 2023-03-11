//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_SCENE_H
#define KILLERKITTY_SCENE_H

#include "engine/Entities/Entity.h"
#include "CommandQueue.h"
#include "ResourceHolder.h"
#include "EventSystem.h"
#include "Camera.h"
#include "MusicPlayer.h"
#include "Game.h"

namespace kke {

    class Game;

    class Scene {
    public:
        explicit Scene(Game& game);

        void Run();

        virtual void Construct() {}
        virtual void Update() {}
        virtual void ProcessInputs() {}
        virtual void Deconstruct() {}

        virtual ~Scene() = default;

    protected:
        CommandQueue<std::string> commandQueue;
        ResourceHolder<sf::Texture, std::string> textureHolder;
        EventSystem eventSystem;
        Camera camera;
        MusicPlayer musicPlayer;
        Entity root;

        bool Running = true;
        Game& game;

        sf::Time deltaTime;
        sf::RenderWindow &window;
        sf::Clock clock;
    };

} // kke

#endif //KILLERKITTY_SCENE_H
