#pragma once
#include "cocos2d.h"
#include "CScene.h"

class AboutScene : public cocos2d::Scene {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(AboutScene);

private:
	cocos2d::Sprite* backgr;
	void navigateToPlayGame(float timeDelay);
};
