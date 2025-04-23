#pragma once

#include "Module.h"

class M_Audio : public Module
{
public:
	M_Audio(bool start_enabled);
	~M_Audio();

    void Init();
    void Update(RenderWindow& window, float dt);

    // Music
    bool LoadMusic(const string& musicName, const string& filename);
    void PlayMusic(const string& musicName);
    void StopMusic(float fadeSpeed);

    // SFX
    bool LoadSound(const string& soundName, const string& filename);
    void PlaySound(const string& soundName);
    void StopSound(const string& soundName);
    void StopAllSounds();

private:
    //map<string, Music&&> musics;
    unordered_map<string, unique_ptr<Music>> musics;
    Music* playingMusic = nullptr;

    map<string, SoundBuffer> soundBuffers;
    map<string, Sound> sounds;

    bool fadingOut = false;
    float fadeSpeed = 0;
};