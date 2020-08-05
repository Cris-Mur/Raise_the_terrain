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
	FILE *log = NULL;
	size_t lenny = 0, w = 0, h = 0;
	char *buffersito = NULL, *tk = NULL;
	SDL_world_t *tmp = NULL;

	tmp = *pWorld;
	tmp = file_catch(&tmp);
	if (tmp->path) {
		log = fopen(tmp->path, "r");
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
				tmp->map[h][w].x = (_SCREEN_WIDTH / (tmp->px + 8)) * (h + 1);
				tmp->map[h][w].y = (_SCREEN_HEIGHT / (tmp->py + 3)) * (w + 1);
				tmp->map[h][w].z = (atof(tk)) * 2;
				tk = strtok(NULL, " \n");
			}
		}
		free(buffersito);
		fclose(log);
	}
	*pWorld = tmp;
	return (1);
}

/**
 * _file_catch - generate a matrix
 * @path - input path of the map file
 * Return: matrix of Z coordinates
 */
SDL_world_t *file_catch(SDL_world_t **pWorld)
{
	FILE *log;
	size_t lenny, lennx, tblk = 0;
	char *buffersito, *tk;
	SDL_world_t *tmp = NULL;

	tmp = *pWorld;
	if (tmp->path)
	{
		log = fopen(tmp->path, "r");
		if (!log)
		{
			write(STDERR_FILENO,
			      "ERROR can't open file...\n", 25);
			return (NULL);
		}
		//get size of the matrix
		for (; getline(&buffersito, &lenny, log) != -1;
		     tmp->py++)
			if (tmp->py == 0)
			{
				tk = strtok(buffersito, " \n");
				for (; tk; tmp->px++)
					tk = strtok(NULL, " \n");
			}
		//allocated matrix [part_y]
		tmp->map = malloc(sizeof(cartesian_t *) * tmp->py);
		if (!tmp->map)
		{
			write(STDERR_FILENO,
			      "Allocate map[y] FAILED...\n", 23);
			return (NULL);
		}
		//allocated matrix [y][part_x]
		for (lenny = 0; lenny < tmp->py; lenny++)
		{
			tmp->map[lenny] = malloc(sizeof(cartesian_t) * tmp->px);
			if (!tmp->map[lenny])
			{
				write(STDERR_FILENO,
				      "Allocate map[y][x] FAILED...\n", 23);
				return (NULL);
			}
			for (lennx = 0; lennx < tmp->px; lennx++)
			{
				tmp->map[lenny][lennx].x = 0;
				tmp->map[lenny][lennx].y = 0;
				tmp->map[lenny][lennx].z = 0;
				tblk++;
			}
		}
		free(buffersito);
		fclose(log);
	}
	return (tmp);
}
