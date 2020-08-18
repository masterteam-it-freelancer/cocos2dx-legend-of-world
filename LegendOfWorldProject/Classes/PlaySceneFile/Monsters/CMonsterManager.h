#pragma once
#include "cocos2d.h"
#include "../BaseClasses/CMonster.h"
#include <fstream>


USING_NS_CC;
enum EMonster {
    TINY_GOLEM_01,
    TINY_GOLEM_02,
    TINY_GOLEM_03,
};

class MonsterManager {
private:
    static MonsterManager* _instance;

    int _numberOfMonsters;
    // cocos2d::Vector<Monster*> result;

    // /*
    // Index 0: Number of hero
    // Index 1 -> end: Path
    // */
    // //Functions

    // cocos2d::Vector<Monster*> GetMonsterLists();

public:
    MonsterManager();
    ~MonsterManager();
    void ReadData(std::string path); // Get number of champs,Monsters file path,v.v
    static MonsterManager* GetInstance();
    std::vector<std::string> _monsterData;
    std::vector<Monster*> _allMonsterInGame;

    /* Temp code here*/
    //std::string tempStringData;

};