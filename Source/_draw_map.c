//
// Created by cristian on 10/05/20.
//
#include "../Headers/basic_libs.h"

void _draw_map(SDL_world_t **pWorld)
{
    size_t w, h;
    float x, wx, Wx, y, wy, Wy, z;
    float inx, iny = 0.7;
    float kx, ky;

    kx = _SCREEN_WIDTH / 2.2;
    ky = _SCREEN_HEIGHT / 3.2;

    for (h = 0; h < (*pWorld)->py; h++)
    {
        for (w = 0; w < (*pWorld)->px; w++)
        {
            x = (*pWorld)->map[h][w].x;
            y = (*pWorld)->map[h][w].y;
            z = (*pWorld)->map[h][w].z;
            wx = (inx * (x - y)) + kx;
            wy = ((iny - 1) * (x + y) - z) + ky;
            if (h < (*pWorld)->py - 1)
            {
                x = (*pWorld)->map[h + 1][w].x;
                y = (*pWorld)->map[h + 1][w].y;
                z = (*pWorld)->map[h + 1][w].z;
                Wx = (inx * (x - y)) + kx;
                Wy = ((iny - 1) * (x - y) - z) + ky;
                SDL_RenderDrawLine((*pWorld)->render, wx, wy, Wx, Wy);
            }
            if (w < (*pWorld)->px - 1)
            {
                x = (*pWorld)->map[h][w + 1].x;
                y = (*pWorld)->map[h][w + 1].y;
                z = (*pWorld)->map[h][w + 1].z;
                Wx = (inx * (x - y)) + kx;
                Wy = ((iny - 1) * (x - y) - z) + ky;
                SDL_RenderDrawLine((*pWorld)->render, wx, wy, Wx, Wy);
            }
        }
    }
}
