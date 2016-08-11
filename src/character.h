#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED


#include "includes.h"

class character {
protected:
    int strength = 8;
    int intelligence = 8;
    int dexterity = 8;
    int constitution = 8;
    int wisdom = 8;
    int charisma = 8;
    char* cname = "";
    int cclass = 0;
    int crace = 0;
    int hunger = 1000;
    int level = 1;
    int experience = 0;
    bool dead = false;
    int health = 10;
    int maxhealth = 10;
    int mana = 0;
    int maxmana = 0;
    int score = 0;
public:
    bool firstvisit = true;
    character(char* name, int newrace, int newclass);
    void SetStats(int NewStr, int NewCon, int NewDex, int NewInt, int NewWis, int NewCha);
    void ChangeStats(int NewStr,int NewCon,int NewDex,int NewInt,int NewWis,int NewCha);
    void SetName(char* NewName);
    void SetCClass(int NewCClass);
    void SetCRace(int NewCRace);
    void ChangeHunger(int NewHunger);
    void ChangeLvl(int LvlChange);
    void ChangeExp(int ExpChange);
    void ChangeHP(int HPChange);
    void ChangeMaxHP(int MaxChange);
    void ChangeMP(int MPChange);
    void ChangeMaxMP(int MaxChange);
    int GetStr();
    int GetDex();
    int GetCon();
    int GetInt();
    int GetWis();
    int GetCha();
    char* GetName();
    int GetCClass();
    int GetCRace();
    int GetHunger();
    int GetLvl();
    int GetExp();
    int GetHP();
    int GetMaxHP();
    int GetMP();
    int GetMaxMP();
    int characterdump();
};

#endif // CHARACTER_H_INCLUDED
