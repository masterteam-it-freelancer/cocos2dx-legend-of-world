#pragma once
#include <vector>


#include "PlaySceneFile/BaseClasses/CChampion.h"
#include "PlaySceneFile/BaseClasses/CDynamicObject.h"
#include "PlaySceneFile/BaseClasses/CMonster.h"

class ResourceManager{
	
private:
	static ResourceManager* _instance;
	ResourceManager();
	~ResourceManager();
	
	
public:
	std::vector<Champion*> _allChampion;
	std::vector<DynamicObject* >_allSpriteAdd;
	std::vector<Monster*> _allMonster;
	
	static ResourceManager* getInstance();
	std::vector<DynamicObject*> getAllSpriteAdded();
	std::vector<Champion*> getAllChampionAdded();
	std::vector<Monster*> getAllMonsterAdded();
	void addMonster(Monster* monster);
	void addChampion(Champion* aChampion);
};
