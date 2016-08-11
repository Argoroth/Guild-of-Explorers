// Includes
#include "includes.h"
#include "defines.h"
#include "character.h"

// Global Variables
TCODConsole *menuscreen = new TCODConsole(screen_width, screen_height);

// Prototypes
int loadcharacter();
// Commands

void mainmenu(int x, int y, bool fullscreen = false){
    //menuscreen->setDefaultBackground(TCODColor::black);
    //menuscreen->setDefaultForeground(TCODColor::white);
    menuscreen->clear();
    TCODConsole::setColorControl(TCOD_COLCTRL_1, TCODColor::red, TCODColor::black);
    menuscreen->printEx(x/2,2,TCOD_BKGND_NONE,TCOD_CENTER,"Welcome to\n%c%s%c\nV%s",TCOD_COLCTRL_1,title,TCOD_COLCTRL_STOP,version);
    for (int i = 0; i <= x; i++) {
        menuscreen->print(i,8,"=");
        menuscreen->print(i,9,"=");
    }
}

int loadcharacter(){
    character *curchar = new character("Argoroth", 1, 1);
}
