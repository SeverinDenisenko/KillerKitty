//
// Created by Severin on 08.03.2023.
//

#ifndef KILLERKITTY_MUSICPLAYER_H
#define KILLERKITTY_MUSICPLAYER_H

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <map>

namespace kke {

    class MusicPlayer : sf::NonCopyable {
    public:
        MusicPlayer();

        void Load(const std::string& id, std::string filename);

        void Play(const std::string& id);
        void Stop();

        void Pause(bool pause);

        float volume;

    private:
        sf::Music music;
        std::map<std::string, std::string> filenames;
    };

} // kke

#endif //KILLERKITTY_MUSICPLAYER_H
