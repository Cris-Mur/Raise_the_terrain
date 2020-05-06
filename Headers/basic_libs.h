//
// Created by cristian on 5/05/20.
//

#ifndef RAISE_THE_TERRAIN_BASIC_LIBS_H
#define RAISE_THE_TERRAIN_BASIC_LIBS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>

#ifndef RAISE_THE_TERRAIN_GLOBAL_VARIABLES
#define RAISE_THE_TERRAIN_GLOBAL_VARIABLES

#endif //RAISE_THE_TERRAIN_GLOBAL_VARIABLES

int _Sdl_born(const int S_w, const int S_H, SDL_Window **window, SDL_Surface **S_surface);
int _load_img(SDL_Surface **img);
void _close_win(SDL_Window **window, SDL_Surface **img);

#endif //RAISE_THE_TERRAIN_BASIC_LIBS_H