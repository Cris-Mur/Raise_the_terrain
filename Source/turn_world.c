//
// Created by cristian on 16/05/20.
//

#include "../Headers/basic_libs.h"

void gyre(SDL_world_t **pWorld, int a)
{
    SDL_world_t *tmp = NULL;
    size_t w, h;
    float x, Rx, y, Ry;
    float kx, ky, angle;

    tmp = *pWorld;
    angle = a * M_PI / 180;
    kx = (_SCREEN_WIDTH + 100) / 12;
    ky = (_SCREEN_HEIGHT + 10) / 2.5;
    for (h = 0; h < tmp->py; h++)
    {
        for (w = 0; w < tmp->px; w++)
        {
            x = tmp->map[h][w].x;
            y = tmp->map[h][w].y;
            Rx = (x - kx) * cos(angle) - (y - ky) * sin(angle) + kx;
            Ry = (x - kx) * sin(angle) + (y - ky) * cos(angle) + ky;
            tmp->map[h][w].x = Rx;
            tmp->map[h][w].y = Ry;
        }
    }
}