//
// Created by Severin on 08.03.2023.
//

#include "MusicPlayer.h"

#include <utility>

namespace kke {
    void MusicPlayer::Load(const std::string& id, std::string filename) {
        filenames[id] = std::move(filename);
    }

    MusicPlayer::MusicPlayer(): volume(100.f) {

    }

    void MusicPlayer::Play(const std::string& id) {
        if (!music.openFromFile(filenames[id]))
            throw std::runtime_error("Music " + id + " could not be loaded.");

        music.setVolume(volume);
        music.setLoop(true);
        music.play();
    }

    void MusicPlayer::Stop() {
        music.stop();
    }

    void MusicPlayer::Pause(bool pause) {
        if (pause)
            music.pause();
        else
            music.play();
    }
} // kke