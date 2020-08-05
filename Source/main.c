#include "../Headers/basic_libs.h"
/**
 * main - program that draw a grid using isometric projection
 * @argc: ARGument Counter
 * @argv: ARGument Vector
 * Return: Always 0 (success)
 */
int main(int argc, char **argv) {
	//The Window structure
	SDL_world_t *win;
	//Main loop flag
	int quit = 0;

	if (argc < 2 || argc > 2)
    {
	    write(STDERR_FILENO,
	            "Usage [APP] <depth file (*.map)>\n", 34);
	    exit (-1);
    }
	// write test
	write(STDOUT_FILENO, "Raise the terrain\n", 18);
	//Start SDL
	if (!_Sdl_born(&win))
	{
		printf("Failed to initialize!\n");
		exit (-1);
	}
	else
	{
	    win->path = strdup(argv[1]);
        //initialize marix map values
        if (init_map(&win))
        {
            // cycle of the program
            while (!quit)
            {
                //Set Render Color
                SDL_SetRenderDrawColor(
                        win->render, 0, 0, 0, 0);
                // Render Clear
                SDL_RenderClear(win->render);
                //handle events
                quit = horizon(&win);
                //Set Render Color
                SDL_SetRenderDrawColor(
                        win->render, 255, 0, 255, 255);
                _draw_map(&win);
                //Update Render
                SDL_RenderPresent(win->render);
            }
        }
	}
	//Free resources and close SDL
	close_win(&win);
	write(STDOUT_FILENO, "Bye...\n",7);
	return 0;
}
