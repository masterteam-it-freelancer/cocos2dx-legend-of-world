#pragma once
#include "cocos2d.h"
#include "../BaseClasses/CChampion.h"
#include <fstream>


USING_NS_CC;
enum EHero{
	ELF_ARCHER_01,
	ELF_FAIRY_01,
	GOLEM_01,
	KNIGHT_01,
	KNIGHT_02,
	KNIGHT_03,
	ORC_01,
	TROLL_01,
};

class ChampionManager{
private:
    static ChampionManager* _instance;
  
    int _numberOfChampions;
    // cocos2d::Vector<Champion*> result;

    // /*
    // Index 0: Number of hero
    // Index 1 -> end: Path
    // */
    // //Functions
  
    // cocos2d::Vector<Champion*> GetChampionLists();

public:
    ChampionManager();
    ~ChampionManager();
    void ReadData(std::string path); // Get number of champs,champions file path,v.v
    static ChampionManager* GetInstance();
    std::vector<std::string> _champsData;
    std::vector<Champion*> _allChampsInGame;

    /* Temp code here*/
    //std::string tempStringData;
   
};