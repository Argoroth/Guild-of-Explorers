#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED
#include "character.h"

const int numrace = 16;
const int numclass = 20;
const int numgod = 12;
extern int screen_height;
extern int screen_width;
extern int viewmode;
extern bool fullscreen;
extern TCOD_renderer_t renderer;
extern const char* title;
extern const char* version;
extern const char* FullTitle;
extern const char* versionmajor;
extern const char* versionminor;
extern const char* versionbuild;
extern bool endGame;
extern const char* iconfile;
extern int safefloor;
extern int safebottom;
extern int dungeonfloor;
extern int zonenum;
extern int zonetype;
extern int sidefloornum;
extern int sidefloortype;
extern bool sidefloorvisit;
extern int dungeonstart;
extern int curposx;
extern int curposy;
extern const int races[numrace+1][11];
extern const int classes[numclass+1][3];
extern const int gods[numgod+1][3];
extern character *curchar;

#endif // DEFINES_H_INCLUDED
