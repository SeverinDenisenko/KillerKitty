//
// Created by Severin on 20.02.2023.
//

#ifndef PROGRAMMABLE_RESOURCEHOLDER_H
#define PROGRAMMABLE_RESOURCEHOLDER_H

#include <string>
#include <map>

#include <SFML/Graphics.hpp>

namespace kke{

    template <typename Resource, typename Identifier>
    class ResourceHolder{
    public:
        void Load(Identifier id, const std::string& filename){
            std::unique_ptr<Resource> texture(new Resource());

            if(!texture->loadFromFile(filename))
                throw std::runtime_error("TextureHolder::Load: Failed to load " + filename);

            resource.insert(std::make_pair(id, std::move(texture)));
        }

        Resource& get(Identifier id){
            auto found = resource.find(id);

            if(found == resource.end())
                throw std::runtime_error("TextureHolder::get: Failed to get texture.");

            return *found->second;
        }

        const Resource& get(Identifier id) const{
            auto found = resource.find(id);

            if(found == resource.end())
                throw std::runtime_error("TextureHolder::get: Failed to get texture.");

            return *found->second;
        }
    private:
        std::map<Identifier, std::unique_ptr<Resource>> resource;
    };

    template <typename Identifier>
    class ResourceHolder<sf::Shader, Identifier>{
    public:
        void Load(Identifier id, const std::string& vertex, const std::string& fragment){
            std::unique_ptr<sf::Shader> texture(new sf::Shader());

            if(!texture->loadFromFile(vertex, fragment))
                throw std::runtime_error("TextureHolder::Load: Failed to load " + vertex);

            resource.insert(std::make_pair(id, std::move(texture)));
        }

        sf::Shader& get(Identifier id){
            auto found = resource.find(id);

            if(found == resource.end())
                throw std::runtime_error("TextureHolder::get: Failed to get " + std::to_string(id));

            return *found->second;
        }

        const sf::Shader& get(Identifier id) const{
            auto found = resource.find(id);

            if(found == resource.end())
                throw std::runtime_error("TextureHolder::get: Failed to get " + std::to_string(id));

            return *found->second;
        }
    private:
        std::map<Identifier, std::unique_ptr<sf::Shader>> resource;
    };
}


#endif //PROGRAMMABLE_RESOURCEHOLDER_H
