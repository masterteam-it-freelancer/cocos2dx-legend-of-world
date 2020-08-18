#include "ResourceManager.h"
ResourceManager* ResourceManager::_instance = nullptr;

ResourceManager::ResourceManager() = default;

ResourceManager::~ResourceManager() = default;

ResourceManager* ResourceManager::getInstance(){
	if (_instance == nullptr)
		_instance = new ResourceManager();
	return _instance;
}

void ResourceManager::addChampion(Champion* aChampion){
		_allChampion.push_back(aChampion);
}

void ResourceManager::addMonster(Monster* monster){
	if (monster != nullptr)
		_allMonster.push_back(monster);
}

std::vector<Champion*> ResourceManager::getAllChampionAdded(){
	return _allChampion;
}

std::vector<Monster*> ResourceManager::getAllMonsterAdded() {
	return _allMonster;
}
