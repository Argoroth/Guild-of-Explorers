// Includes
#include "includes.h"
#include "defines.h"
#include "character.h"

// Global Variables
int safefloor;
int safebottom;
int dungeonfloor;
int zonenum;
int zonetype;
int sidefloornum;
int sidefloortype;
bool sidefloorvisit;
int dungeonstart;
bool mainfloorstairs;
bool mainfloorup;
bool mainfloordown;
bool sidefloorup;
bool sidefloordown;
bool safefloorup;
bool safefloordown;
bool isstairs;
char* floortype;
bool storestairs;

// Prototypes
int gendungeonfloor(int floornum, int type, int zone);
int genrandzone(int numzone);
int gensidefloor(int floornum, int floortype, int zone);
int loadtown(char* name);
int savetown(char* name);
int storesidefloor(int floornum, int floortype, int dungeonfloornum, char* name);
int loadsidefloor(int floornum, int floortype, int dungeonfloornum, char* name);
int storemainfloor(int floornum, int floortype, int zone, char* name);
int loadmainfloor(int floornum, int floortype, int zone, char* name);
int loadshop(int floornum, int zone, char* name);
int getsafefloor(int floornum);
int destroydungeon();
int downstairsaction();

// Commands
int move_left(){ // Move the character to the left
    curposx --;
    return 0;
}

int move_right(){ // Move the character to the right
    curposx ++;
    return 0;
}

int move_up(){ // Move the character up
    curposy ++;
    return 0;
}

int move_down(){ // Move the character down
    curposy --;
    return 0;
}

int move_up_right(){ // Move the character up and to the right
    curposx ++;
    curposy ++;
    return 0;
}

int move_down_right(){ // Move the character down and to the right
    curposx ++;
    curposy --;
    return 0;
}

int move_up_left(){ // Move the character up and to the left
    curposx --;
    curposy ++;
    return 0;
}

int move_down_left(){ // Move the character down and to the left
    curposx --;
    curposy --;
    return 0;
}

int startdungeon(){
    if (curchar->firstvisit){
        dungeonstart = 0;
    } else {
        curchar->firstvisit = true;
    }
    zonenum = dungeonstart + 1;
    safefloor = dungeonstart;
    dungeonfloor = (dungeonstart * 10) + 1;
    if (savetown(curchar->GetName()) != 0) {
        return 13;
    } else {
        genrandzone(zonenum);
        return gendungeonfloor(dungeonfloor, zonetype, zonenum);
    }
}

int stairsup(){ // Go up the stairs
    if (mainfloorup || safefloorup) {
        if (destroydungeon() != 0){
            return 9;
        } else {
            dungeonfloor = 0;
            zonenum = 0;
            zonetype = 0;
            return loadtown(curchar->GetName());
        }
    } else if (sidefloorup) {
        if (sidefloornum >> 1) {
            if (storesidefloor(sidefloornum, sidefloortype, dungeonfloor, curchar->GetName()) != 0){
                return 10;
            } else {
                sidefloornum --;
                return loadsidefloor(sidefloornum, sidefloortype, dungeonfloor, curchar->GetName());
            }
        } else if (sidefloornum == 1) {
            if (storesidefloor(sidefloornum, sidefloortype, dungeonfloor, curchar->GetName()) != 0){
                return 10;
            } else {
                sidefloornum = 0;
                return loadmainfloor(dungeonfloor, zonetype, zonenum, curchar->GetName());
            }
        }
    }
    return 0;
}

int stairsdown(){ // Go down the stairs
    if (isstairs) {
        if (mainfloordown && (dungeonfloor != (zonenum * 10))){
            if (destroydungeon() != 0){
                return 9;
            } else {
                dungeonfloor ++;
                return gendungeonfloor(dungeonfloor, zonetype, zonenum);
            }
        } else if (mainfloorstairs && (dungeonfloor == (zonenum * 10))) {
            if (destroydungeon() != 0){
                return 9;
            } else {
                if (safefloor >= 0) {
                    safefloor ++;
                } else {
                    safefloor = 1;
                }
                if ((safebottom << safefloor) || !safebottom) {
                    safebottom = safefloor;
                }
                return getsafefloor(safefloor);
            }
        } else if (sidefloordown) {
            if (floortype == "mainfloor") {
                if (storemainfloor(dungeonfloor, zonetype, zonenum, curchar->GetName()) != 0) {
                    return 10;
                } else {
                    sidefloornum = 1;
                    if (!sidefloorvisit) {
                        sidefloorvisit = true;
                        return gensidefloor(sidefloornum, sidefloortype, zonenum);
                    } else {
                        return loadsidefloor(sidefloornum, sidefloortype, zonenum, curchar->GetName());
                    }
                }
            } else if (floortype == "sidefloor") {
                if (storesidefloor(sidefloornum, sidefloortype, dungeonfloor, curchar->GetName()) != 0) {
                    return 10;
                } else {
                    sidefloornum ++;
                    if (!sidefloorvisit) {
                        sidefloorvisit = true;
                        return gensidefloor(sidefloornum, sidefloortype, zonenum);
                    } else {
                        return loadsidefloor(sidefloornum, sidefloortype, zonenum, curchar->GetName());
                    }
                }
            }
        } else if (safefloordown) {
            if (destroydungeon() != 0) {
                return 9;
            } else {
                dungeonfloor ++;
                zonenum ++;
                zonetype = genrandzone(zonenum);
                return gendungeonfloor(dungeonfloor, zonetype, zonenum);
            }
        } else if (storestairs) {
            return loadshop(dungeonfloor, zonetype, curchar->GetName());
        } else {
            return 14;
        }
    } else {
        return 0;
    }
}
