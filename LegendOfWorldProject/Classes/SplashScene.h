#pragma once
#include "cocos2d.h"
#include "CScene.h"

class SplashScene: public cocos2d::Scene{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(SplashScene);
private:
    void NavigateToMainMenuScene(float timeDelay);
};
