//
// Created by Severin on 07.03.2023.
//

#ifndef KILLERKITTY_SCENE_H
#define KILLERKITTY_SCENE_H

#include "Entity.h"
#include "CommandQueue.h"
#include "ResourceHolder.h"
#include "EventSystem.h"
#include "Camera.h"

namespace kke {

    class Scene {
    public:
        explicit Scene(sf::RenderWindow& window);

        void Run();

        virtual void Construct() {}
        virtual void Update() {}
        virtual void ProcessInputs() {}
        virtual void Deconstruct() {}

        virtual ~Scene() = default;

    protected:
        Entity root;
        CommandQueue<std::string> commandQueue;
        ResourceHolder<sf::Texture, std::string> textureHolder;
        EventSystem eventSystem;
        Camera camera;
        sf::Time deltaTime;

        bool Running = true;

    private:
        sf::RenderWindow &window;
        sf::Clock clock;
    };

} // kke

#endif //KILLERKITTY_SCENE_H
