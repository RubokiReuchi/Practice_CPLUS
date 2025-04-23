#include "M_Audio.h"

#include <SFML/Audio.hpp>

M_Audio::M_Audio(bool start_enabled) : Module(start_enabled)
{
    Console::print("Module Audio Init");
}

M_Audio::~M_Audio() {}

void M_Audio::Init()
{
    LoadMusic("Example", "Assets/Audio/Music/exampleMusic.wav");
    LoadSound("Clap", "Assets/Audio/SFX/Clap.wav");
}

void M_Audio::Update(RenderWindow& window, float dt)
{
    if (fadingOut) {
        float volume = playingMusic->getVolume() - fadeSpeed * dt;
        if (volume <= 0)
        {
            volume = 0;
            playingMusic->setVolume(100);
            playingMusic->stop();
            playingMusic = nullptr;
            fadingOut = false;
            fadeSpeed = 0;
        }
        else playingMusic->setVolume(volume);
    }
}

bool M_Audio::LoadMusic(const std::string& musicName, const std::string& filename) {
    unique_ptr<Music> music = make_unique<Music>();
    if (!music->openFromFile(filename))
    {
        Console::print("Error al cargar la musica: " + filename);
        return false;
    }

    musics.emplace(musicName, std::move(music));

    return true;
}

void M_Audio::PlayMusic(const std::string& musicName) {
    auto it = musics.find(musicName);
    if (it != musics.end())
    {
        it->second->play();//FADEEEEEEEEEEEEEEEE
        playingMusic = it->second.get();
    }
    else Console::print("El sonido no se ha encontrado: " + musicName);
}

void M_Audio::StopMusic(float fadeSpeed) {
    if (playingMusic) {
        fadingOut = true;
        this->fadeSpeed = fadeSpeed;
    }
}

bool M_Audio::LoadSound(const std::string& soundName, const std::string& filename) {
    SoundBuffer buffer;

    // Cargar el archivo de sonido en el buffer
    if (!buffer.loadFromFile(filename)) {
        Console::print("Error al cargar el sonido: " + filename);
        return false;
    }

    // Guardar el buffer en el mapa
    soundBuffers[soundName] = buffer;

    sounds.emplace(soundName, Sound{ soundBuffers[soundName] });

    return true;
}

void M_Audio::PlaySound(const std::string& soundName) {
    auto it = sounds.find(soundName);
    if (it != sounds.end())
    {
        it->second.play();
    }
    else Console::print("El sonido no se ha encontrado: " + soundName);
}

void M_Audio::StopSound(const std::string& soundName) {
    auto it = sounds.find(soundName);
    if (it != sounds.end()) {
        it->second.stop();
    }
    else Console::print("El sonido no se ha encontrado: " + soundName);
}

void M_Audio::StopAllSounds() {
    for (auto& sound : sounds) {
        sound.second.stop();
    }
}