#include "CChampionManager.h"

#include "ResourceManager.h"

ChampionManager* ChampionManager::_instance = nullptr;

ChampionManager::ChampionManager(){

}

ChampionManager* ChampionManager::GetInstance(){
    if(_instance == nullptr)
        _instance = new ChampionManager();
    return _instance;
}

void ChampionManager::ReadData(std::string path){
    if(!FileUtils::getInstance()->isFileExist(path)){
        cocos2d::log("Not found source file");
    }
    auto tempStringData = FileUtils::getInstance()->getStringFromFile(path);

    std::stringstream tokenStr(tempStringData);
    std::string tokenSeg;
    while(std::getline(tokenStr,tokenSeg,',')){
        _champsData.push_back(tokenSeg);
    }

    for (int i = 0; i < _champsData.size(); i++) {
        std::string temp = _champsData.at(i);
	}

    if(!_champsData.empty()){
    	for(int index = 2; index < _champsData.size(); index++){
          if(index % 2 != 0){
              std::string heroData = _champsData.at(index);
              heroData.erase(remove_if(heroData.begin(), heroData.end(), isspace), heroData.end());

              if (FileUtils::getInstance()->isFileExist(heroData)) {
                  std::string heroStrData = FileUtils::getInstance()->getStringFromFile(heroData);
              	  if(heroStrData != ""){

	                  std::stringstream heroDataStrStream(heroStrData);
	                  std::string heroDataStrSeg;
	                 std::vector<std::string> heroTokenData;
	                 while (std::getline(heroDataStrStream, heroDataStrSeg, ',')) {
	                     heroTokenData.push_back(heroDataStrSeg);
	                 }

	                 Champion* tokenChamp = new Champion();
	                 tokenChamp->createChamp(heroTokenData);
	                 _allChampsInGame.push_back(tokenChamp);
                     ResourceManager::getInstance()->_allChampion.push_back(tokenChamp);
                     cocos2d::log("Create completed a champion");
              	  }
			  }
		  }
		}

    }
}

// cocos2d::Vector<Champion*> ChampionManager::GetChampionLists(){
//     return _allChampsInGame;
// }
