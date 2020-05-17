//
// Created by cristian on 10/05/20.
//
#include "../Headers/basic_libs.h"
/**
 * _draw_map - function that draw a map in iso-view 3d
 * @pWorld: input main structure
 * Return: void
 */
void _draw_map(SDL_world_t **pWorld)
{
    SDL_world_t *tmp = NULL;
    size_t w, h;
    float x, wx, Wx, y, wy, Wy, z;
    float inx = -1.3, iny = 0.6;
    float kx, ky;

    tmp = *pWorld;
    kx = (_SCREEN_WIDTH + 120) / 1.05;
    ky = _SCREEN_HEIGHT / 2.9;
    for (h = 0; h < tmp->py; h++)
    {
        for (w = 0; w < tmp->px; w++)
        {
            x = tmp->map[h][w].x;
            y = tmp->map[h][w].y;
            z = tmp->map[h][w].z;
            wx = ((inx * x) - y) + kx;
            wy = ((iny - 1) * x + (1 - iny) * (y - z)) + ky;
            if (h < tmp->py - 1)
            {
                x = tmp->map[h + 1][w].x;
                y = tmp->map[h + 1][w].y;
                z = tmp->map[h + 1][w].z;
                Wx = ((inx * x) - y) + kx;
                Wy = ((iny - 1) * x + (1 - iny) * (y - z)) + ky;
                SDL_RenderDrawLine(tmp->render, wx, wy, Wx, Wy);
            }
            if (w < tmp->px - 1)
            {
                x = tmp->map[h][w + 1].x;
                y = tmp->map[h][w + 1].y;
                z = tmp->map[h][w + 1].z;
                Wx = ((inx * x) - y) + kx;
                Wy = ((iny - 1) * x + (1 - iny) * (y - z)) + ky;
                SDL_RenderDrawLine(tmp->render, wx, wy, Wx, Wy);
            }
        }
    }
}
