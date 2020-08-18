#include "CMonsterManager.h"

#include "ResourceManager.h"

MonsterManager* MonsterManager::_instance = nullptr;

MonsterManager::MonsterManager() = default;

MonsterManager::~MonsterManager(){
	
}

MonsterManager* MonsterManager::GetInstance() {
    if (_instance == nullptr)
        _instance = new MonsterManager();
    return _instance;
}

void MonsterManager::ReadData(std::string path) {

    if (!FileUtils::getInstance()->isFileExist(path)) {
    }
    auto tempStringData = FileUtils::getInstance()->getStringFromFile(path);

    std::stringstream tokenStr(tempStringData);
    std::string tokenSeg;
    while (std::getline(tokenStr, tokenSeg, ',')) {
        _monsterData.push_back(tokenSeg);
    }

    for (int i = 0; i < _monsterData.size(); i++) {
        std::string temp = _monsterData.at(i);
    }

    if (!_monsterData.empty()) {
        for (int index = 2; index < _monsterData.size(); index++) {
            if (index % 2 != 0) {
                std::string monsterData = _monsterData.at(index);
                monsterData.erase(remove_if(monsterData.begin(), monsterData.end(), isspace), monsterData.end());

                if (FileUtils::getInstance()->isFileExist(monsterData)) {
                    std::string monsterStrData = FileUtils::getInstance()->getStringFromFile(monsterData);

                    if (monsterStrData != "") {
                        std::stringstream monsterDataStrStream(monsterStrData);
                        std::string monsterDataStrSeg;
                        std::vector<std::string> monsterTokenData;
                        while (std::getline(monsterDataStrStream, monsterDataStrSeg, ',')) {
                            monsterTokenData.push_back(monsterDataStrSeg);
                        }

                        Monster* tokenMonster = new Monster();
                        tokenMonster->createMonster(monsterTokenData);
                        _allMonsterInGame.push_back(tokenMonster);
                        ResourceManager::getInstance()->_allMonster.push_back(tokenMonster);
                        cocos2d::log("Create completed a monster");

                    }
                }
            }
        }

    }
}

// cocos2d::Vector<Monster*> MonsterManager::GetMonsterLists(){
//     return _allChampsInGame;
// }
