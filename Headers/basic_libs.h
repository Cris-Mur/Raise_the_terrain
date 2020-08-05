//
// Created by cristian on 5/05/20.
//

#ifndef RAISE_THE_TERRAIN_BASIC_LIBS_H
#define RAISE_THE_TERRAIN_BASIC_LIBS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <math.h>

#ifndef RAISE_THE_TERRAIN_GLOBAL_VARIABLES
#define RAISE_THE_TERRAIN_GLOBAL_VARIABLES

//Screen dimension constants
#define _SCREEN_WIDTH 640
#define _SCREEN_HEIGHT 420
/**
 * struct cartesian - Structure of the cartesian coordinates
 * @x: x value
 * @y: y value
 * @z: z value
 */
typedef struct cartesian
{
    float x;
    float y;
    float z;
} cartesian_t;
/**
 * struct SDL_world - structure that contain SDL win & Render
 * and system of coordinates
 * @window: address of window instance
 * @Sourface: of the window
 */
typedef struct SDL_world
{
    //The window we'll be rendering to
    SDL_Window *window;
    //The surface contained by the window
    SDL_Renderer *render;
    // size of map
    size_t px;
    size_t py;
    // Cartesian map
    cartesian_t **map;
    //depth file
    char *path;
} SDL_world_t;
#endif //RAISE_THE_TERRAIN_GLOBAL_VARIABLES

int _Sdl_born(SDL_world_t **pWorld);
void close_win(SDL_world_t **pWorld);
int init_map(SDL_world_t **pWorld);
SDL_world_t *file_catch(SDL_world_t **pWorld);
void _draw_map(SDL_world_t **pWorld);
int horizon(SDL_world_t **pWorld);
void gyre(SDL_world_t **pWorld, int a);

#endif //RAISE_THE_TERRAIN_BASIC_LIBS_H