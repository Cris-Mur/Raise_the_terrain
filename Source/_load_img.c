//
// Created by cristian on 5/05/20.
//
#include "../Headers/basic_libs.h"

/**
 *
 */
int _load_img(SDL_Surface **img)
{
    SDL_Surface *l_img = NULL;

    l_img = SDL_LoadBMP("../Source/re_src/3720.bmp");
    if (l_img == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "../Source/re_src/3720.bmp", SDL_GetError() );
        return (-1);
    }
    *img = l_img;
    return (1);
}