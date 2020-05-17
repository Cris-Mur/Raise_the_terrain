//
// Created by cristian on 16/05/20.
//

#include "../Headers/basic_libs.h"
/**
 * horizon - function that handle SDL events
 * @pWorld: SDL system and map points
 * Return: always 0 or 1 if quit
 */
int horizon(SDL_world_t **pWorld)
{
    //Event handler
    SDL_Event e;
    //Handle events on queue
    while (SDL_PollEvent(&e) != 0)
    {
        //User requests quit
        if (e.type == SDL_QUIT) {
             return (1);
        }
        else if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    return (1);
                    break;
                case SDLK_LEFT:
                    gyre(pWorld, -2);
                    break;
                case SDLK_RIGHT:
                    gyre(pWorld, 2);
                    break;
                default:
                    return (0);

            }
        }
    }
}
