// Includes
#include "includes.h"

// Prototypes

// Global Variables
SDL_Surface *screen;

// Start the Screen
int MainScreen(int x, int y, const char* title = "", const char* filename = "", bool fullscreen = false, int viewmode = 32){
    // Initialize SDL
    if(SDL_Init( SDL_INIT_VIDEO )) {
        fprintf(stderr, "Could not initialize SDL: %s.\n", SDL_GetError());
        return -1;
    }
    // Open Main Screen
    screen = SDL_SetVideoMode(x, y, viewmode, SDL_SWSURFACE|SDL_ANYFORMAT);
    if ( screen == NULL ) {
        fprintf(stderr, "Couldn't set %sx$sx$s video mode: %s\n", x, y, viewmode, SDL_GetError());
        return -1;
    }
    // Set Screen Caption
    SDL_WM_SetCaption(title, filename);
    return 0;
}

// Change the Main Screen's size
int ScreenSize(int x, int y, int viewmode = 32){
    screen = SDL_SetVideoMode(x, y, viewmode, SDL_SWSURFACE|SDL_ANYFORMAT);
    if ( screen == NULL ) {
        fprintf(stderr, "Couldn't set %sx$sx$s video mode: %s\n", x, y, viewmode, SDL_GetError());
        return -1;
    }
    return 0;
}
