//
// Created by cristian on 6/05/20.
//
#include "../Headers/basic_libs.h"

/**
 *
 */
void close_win(SDL_world_t **window)
{
    size_t h;
    for (h = 0; h < (*window)->py; h++)
    {
        free((*window)->map[h]);
    }
    free((*window)->map);
    (*window)->map = NULL;
    //Destroy render
    SDL_DestroyRenderer((*window)->render);
    (*window)->render = NULL;
    //Destroy window
    SDL_DestroyWindow((*window)->window);
    (*window)->window = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}