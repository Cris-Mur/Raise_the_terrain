//
// Created by cristian on 5/05/20.
//
#include "../Headers/basic_libs.h"

/**
 * _Sdl_born - this function initialise SDL
 * @S_w: Size weith of window
 * @S_h: Size height of window
 * @window: input addres window
 * @S_surface: input addres screen
 * Return: Always (1) if success (-1) if failed
 */
int _Sdl_born(SDL_world_t **window)
{
	SDL_world_t *tmp = NULL;

	if (!window)
		return (-1);

	tmp = malloc(sizeof(SDL_world_t));
	if (!tmp)
		return (-1);
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		//write in a terminal Error message
		printf( "SDL could not initialize! SDL_Error: %s\n",
			SDL_GetError() );
		return (-1);
	}
	tmp->window = NULL;
	//Create window
	tmp->window = SDL_CreateWindow( "Raise the terrain",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					_SCREEN_WIDTH,
					_SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN);
	if(tmp->window == NULL)
	{
		printf( "Window could not be created! SDL_Error: %s\n",
			SDL_GetError() );
		//FREE structure
		free(tmp);
		//Quit SDL subsystems
		SDL_Quit();
		return (-1);
	}
    SDL_SetWindowResizable(tmp->window, 1);
	tmp->render = NULL;
	//Get window surface
	tmp->render = SDL_CreateRenderer(tmp->window, -1,
					 SDL_RENDERER_ACCELERATED |
					 SDL_RENDERER_PRESENTVSYNC);
	if (tmp->render == NULL)
	{
		printf("Render could not be created!! SDL_Error: %s\n",
		       SDL_GetError());
		//Destroy window
		SDL_DestroyWindow(tmp->window);
		//FREE structure
		free(tmp);
		//Quit SDL subsystems
		SDL_Quit();
		return (-1);
	}
	tmp->path = NULL;
	tmp->map = NULL;
	tmp->px = 0;
	tmp->py = 0;
	//assing tmp to main struct
	*window = tmp;
	return (1);
}
