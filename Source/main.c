#include "../Headers/basic_libs.h"

int main(int argc, char **argv) {

    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    //The window we'll be rendering to
    SDL_Window *window = NULL;
    //The surface contained by the window
    SDL_Surface *screen = NULL;
    //The image that will be load
    SDL_Surface *img = NULL;

    int t = 0;

    // write test
    write(STDOUT_FILENO, "Raise the terrain\n", 18);
    //Start SDL
    if (!_Sdl_born(SCREEN_WIDTH, SCREEN_HEIGHT, &window, &screen))
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load image
        if (!_load_img(&img))
        {
            printf("Failed to load image!\n");
        }
        else
        {
            //Apply image
            SDL_BlitSurface( img, NULL, screen, NULL );
            //Update the surface
            SDL_UpdateWindowSurface( window );
            //Wait two seconds
            SDL_Delay( 10000 );
        }
    }
    //Free resources and close SDL
    _close_win(&window, &img);
    return 0;
}