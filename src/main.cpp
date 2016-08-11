//Includes
#include "includes.h"
#include "character.h"
#include "defines.h"

// Prototypes
void mainmenu(int x, int y, bool fullscreen = false);

// Global Variables
int screen_height = 96, screen_width = 128, viewmode = 32;
bool fullscreen = false;
TCOD_renderer_t renderer = TCOD_RENDERER_SDL;
const char* title = "Guild of Explorers";
const char* version = "0.0.1";
const char* FullTitle = "Guild of Explorers v0.0.1";
const char* versionmajor = "0";
const char* versionminor = "0";
const char* versionbuild = "1";
bool endGame = false;
const char* iconfile = "";
extern TCODConsole *menuscreen;

int main ( int argc, char *argv[] )
{
    TCODConsole::initRoot(screen_width, screen_height, FullTitle, fullscreen, renderer);
    //TCODConsole::setColorControl(TCOD_COLCTRL_1,TCODColor::red,TCODColor::black);
    //TCODConsole::root->setDefaultBackground(TCODColor::black);
    //TCODConsole::root->setDefaultForeground(TCODColor::white);
    /*TCODConsole::root->printEx(screen_width/2,2,TCOD_BKGND_NONE,TCOD_CENTER,"Welcome to\n%c%s%c\nV%s",TCOD_COLCTRL_1,title,TCOD_COLCTRL_STOP,version);
    for (int i = 0; i <= screen_width; i++) {
        TCODConsole::root->print(i,8,"=");
        TCODConsole::root->print(i,9,"=");
    }*/
    mainmenu(screen_height,screen_width,fullscreen);
    TCODConsole::blit(menuscreen,0,0,0,0,TCODConsole::root,0,0,1.0f,1.0f);
    while (!endGame && !TCODConsole::isWindowClosed()) {
        // ... draw on TCODConsole::root
        TCODConsole::flush();
        TCOD_key_t key;
        TCOD_mouse_t mouse;
        TCOD_event_t ev = TCODSystem::waitForEvent(TCOD_EVENT_ANY,&key,&mouse,true);
        //... update world, using key
        if (ev == TCOD_EVENT_KEY_PRESS && ((key.c == 'Q' ) || (key.vk = TCODK_ESCAPE))) {
            endGame = true;
        }
    }

    exit(0);
}
