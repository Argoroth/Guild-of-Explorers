// Includes
#include "includes.h"
#include "character.h"
#include "defines.h"

// Global Variables
 character *curchar = new character("Argoroth", 1, 1);

// Prototypes

// Commands
//DefineCharacters
character::character(char* newname, int newrace, int newclass){
    SetName(newname);
    SetCRace(newrace);
    SetCClass(newclass);
};
//Set Character Strength
void character::SetStats(int NewStr, int NewCon, int NewDex, int NewInt, int NewWis, int NewCha) {
    if (NewStr != 0){
        strength = NewStr;
    }
    if (NewCon != 0){
        constitution = NewCon;
    }
    if (NewDex != 0){
        dexterity = NewDex;
    }
    if (NewInt != 0){
        intelligence = NewInt;
    }
    if (NewWis != 0){
        wisdom = NewWis;
    }
    if (NewCha != 0){
        charisma = NewCha;
    }
};
//Change Character Stats
void character::ChangeStats(int StrChange,int ConChange,int DexChange,int IntChange,int WisChange,int ChaChange) {
    if (StrChange != 0){
        if ((GetStr() + StrChange) < 0){
            strength = 0;
        } else {
            strength = GetStr() + StrChange;
        }
    }
    else if (ConChange != 0){
        if ((GetCon() + ConChange) < 0){
            constitution = 0;
        } else {
            constitution = GetCon() + ConChange;
        }
    }
    else if (DexChange != 0){
        if ((GetDex() + DexChange) < 0){
            dexterity = 0;
        }
        else {
            dexterity = GetDex() + DexChange;
        }
    }
    else if (IntChange != 0){
        if ((GetInt() + IntChange) < 0){
            intelligence = 0;
        }
        else {
            intelligence = GetInt() + IntChange;
        }
    }
    else if (WisChange != 0){
        if ((GetWis() + WisChange) < 0){
            wisdom = 0;
        }
        else {
            wisdom = GetWis() + WisChange;
        }
    }
    else if (ChaChange != 0){
        if ((GetCha() + ChaChange) < 0){
            charisma = 0;
        }
        else {
            charisma = GetCha() + ChaChange;
        }
    }
};
//Set Character Name
void character::SetName(char* NewName) {
    if (cname == "") {
        cname = NewName;
    }
};
//Set Character Class
void character::SetCClass(int NewCClass) {
    if (cclass == 0) {
        cclass = NewCClass;
    }
};
//Set Character Race
void character::SetCRace(int NewCRace){
    if (crace == 0) {
        if (NewCRace >> 0) {
            crace = NewCRace;
            SetStats(races[NewCRace][3], races[NewCRace][4], races[NewCRace][5], races[NewCRace][6], races[NewCRace][7], races[NewCRace][8]);
        }
    }
};
//Change Character Hunger
void character::ChangeHunger(int HungerChange) {
    if ((GetHunger() + HungerChange) < -1000) {
        hunger = -1000;
    } else if ((GetHunger() + HungerChange) > 1000) {
        hunger = 1000;
    } else {
        hunger = GetHunger() + HungerChange;
    }
};
//Change Character Level
void character::ChangeLvl(int LvlChange) {
    if ((GetLvl() + LvlChange) < 1) {
        level = 1;
    } else {
        level = GetLvl() + LvlChange;
    }
};
//Change Character Experience
void character::ChangeExp(int ExpChange) {
    if ((GetExp() + ExpChange) < 0){
        experience = 0;
    } else {
        experience = GetExp() + ExpChange;
    }
};
//Change Character Health
void character::ChangeHP(int HPChange){
    if ((GetHP() + HPChange) < 0) {
        health = 0;
        dead = true;
    } else if ((GetHP() + HPChange) > GetMaxHP()){
        health = maxhealth;
    } else {
        health = GetHP() + HPChange;
    }
}
//Change Character Max HP
void character::ChangeMaxHP(int MaxChange){
    if ((GetMaxHP() + MaxChange) < 2) {
        maxhealth = 2;
    } else {
        maxhealth = GetMaxHP() + MaxChange;
    }
}
//Change Character Mana
void character::ChangeMP(int MPChange){
    if ((GetMP() + MPChange) < 0) {
        mana = 0;
    } else if ((GetMP() + MPChange) > GetMaxMP()) {
        mana = GetMaxMP();
    } else {
        mana = GetMP() + MPChange;
    }
}
//Change Character Max Mana
void character::ChangeMaxMP(int MaxChange){
    if ((GetMaxMP() + MaxChange) < 0){
        maxmana = 0;
    } else {
        maxmana = GetMaxMP() + MaxChange;
    }
}
//Get Character Strength
int character::GetStr(){
    return strength;
};
//Get Character Dexterity
int character::GetDex(){
    return dexterity;
};
//Get Character Constitution
int character::GetCon(){
    return constitution;
};
//Get Character Intelligence
int character::GetInt(){
    return intelligence;
};
//Get Character Wisdom
int character::GetWis(){
    return wisdom;
};
//Get Character Charisma
int character::GetCha(){
    return charisma;
};
//Get Character Name
char* character::GetName(){
    return cname;
};
//Get Character Class
int character::GetCClass(){
    return cclass;
};
int character::GetCRace(){
    return crace;
};
//Get Character Hunger
int character::GetHunger(){
    return hunger;
};
//Get Character Level
int character::GetLvl(){
    return level;
};
//Get Character Experience
int character::GetExp(){
    return experience;
};
//Get Character Health
int character::GetHP(){
    return health;
}
//Get Character Max Health
int character::GetMaxHP(){
    return maxhealth;
}
//Get Character Mana
int character::GetMP(){
    return mana;
}
//Get Character Max Mana
int character::GetMaxMP(){
    return maxmana;
}
//Print Character Info
int character::characterdump() {
    if (cname != "") {
        cout << "Name: " << cname << endl << "Race: " << crace << endl << "Class: " << cclass << endl;
        cout << "HP: " << health << "/" << maxhealth << endl;
        cout << "Str: " << strength << endl << "Dex: " << dexterity << endl << "Con: " << constitution << endl;
        cout << "Int: " << intelligence << endl << "Wis: " << wisdom << endl << "Cha: " << charisma << endl;
        cout << "Level: " << level << endl << "Exp: " << experience << endl;
        return 0;
    } else {
        return 1;
    }
};
