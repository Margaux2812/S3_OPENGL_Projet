#pragma once

#include <SDL/SDL_mixer.h>
#include <iostream>

inline int playMusic(){
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){
        std::cout <<"ERROR initializing mix" << std::endl;
        return EXIT_FAILURE;
    }

    Mix_Music *game_music = Mix_LoadMUS( "assets/sounds/game_bg.wav");// load music for the game 
    Mix_PlayMusic(game_music, -1); // play music

    return 1;
}