#pragma once
#include "cocos2d.h"
#include <functional>
#include "CScene.h"

using namespace std;
USING_NS_CC;
class MainMenuScene : public cocos2d::Scene {
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainMenuScene);
private:
    Label* demoTxt;
    void createButton(string title, Vec2 position,int _sceneID, float _delayTime);
};