//
// Created by cristian on 9/05/20.
//
#include "../Headers/basic_libs.h"
/**
 * _init_map - function that create a map with cartesian struct
 * @pWorld: input matrix map
 * Return: (1) if success (-1) if fail
 */
int init_map(SDL_world_t **pWorld)
{
    FILE *log;
    size_t lenny, w, h;
    char *buffersito, *tk;

    file_catch((SDL_world_t **) pWorld);

    if ((*pWorld)->path) {
        log = fopen((*pWorld)->path, "r");
        if (!log) {
            write(STDERR_FILENO,
                  "ERROR can't open file...\n", 25);
            return (-1);
        }
        //get size of the matrix
        for (h = 0; getline(&buffersito, &lenny, log) != -1; h++)
        {
            tk = strtok(buffersito, " \n");
            for (w = 0; tk; w++)
            {
                printf("px: %u", (*pWorld)->px);
                printf("py: %u", (*pWorld)->py);
                (*pWorld)->map[h][w].x = (_SCREEN_WIDTH / (*pWorld)->px + 8) * (h + 1);
                (*pWorld)->map[h][w].y = (_SCREEN_HEIGHT / (*pWorld)->py + 8) * (w + 1);
                (*pWorld)->map[h][w].z = atof(tk);
                tk = strtok(NULL, " \n");
            }
        }
        free(buffersito);
        fclose(log);
    }
    return (1);
}

/**
 * _file_catch - generate a matrix
 * @path - input path of the map file
 * Return: matrix of Z coordinates
 */
void file_catch(SDL_world_t **pWorld)
{
    FILE *log;
    size_t lenny, lennx, tblk = 0;
    char *buffersito, *tk;

    if ((*pWorld)->path)
    {
        log = fopen((*pWorld)->path, "r");
        if (!log)
        {
            write(STDERR_FILENO,
                    "ERROR can't open file...\n", 25);
            return;
        }
        //get size of the matrix
        for (; getline(&buffersito, &lenny, log) != -1;
        (*pWorld)->py++)
            if ((*pWorld)->py == 0)
            {
                tk = strtok(buffersito, " \n");
                for (; tk; (*pWorld)->px++)
                    tk = strtok(NULL, " \n");
            }
        //allocated matrix [part_y]
        (*pWorld)->map = malloc(sizeof(cartesian_t *) * (*pWorld)->py);
        if (!(*pWorld)->map)
        {
            write(STDERR_FILENO,
                    "Allocate map[y] FAILED...\n", 23);
            return;
        }
        //allocated matrix [y][part_x]
        for (lenny = 0; lenny < (*pWorld)->py; lenny++)
        {
            (*pWorld)->map[lenny] = malloc(sizeof(cartesian_t) * (*pWorld)->px);
            if (!(*pWorld)->map[lenny])
            {
                write(STDERR_FILENO,
                      "Allocate map[y][x] FAILED...\n", 23);
                return;
            }
            for (lennx = 0; lennx < (*pWorld)->px; lennx++)
            {
                (*pWorld)->map[lenny][lennx].x = 0;
                (*pWorld)->map[lenny][lennx].y = 0;
                (*pWorld)->map[lenny][lennx].z = 0;
                tblk++;
            }
        }
        free(buffersito);
        fclose(log);
    }
}