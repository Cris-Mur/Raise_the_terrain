//
// Created by cristian on 6/05/20.
//
#include "../Headers/basic_libs.h"

/**
 *
 */
void _close_win(SDL_Window **window, SDL_Surface **img)
{
    //Deallocate surface
    SDL_FreeSurface( *img );
    *img = NULL;
    //Destroy window
    SDL_DestroyWindow( *window );
    *window = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}