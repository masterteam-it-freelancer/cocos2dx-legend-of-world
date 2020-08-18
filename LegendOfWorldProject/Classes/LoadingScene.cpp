#include "LoadingScene.h"
#include "Definitons.h"
#include "MainMenuScene.h"
#include "PlayGameScene.h"

USING_NS_CC;

Scene* LoadingScene::createScene() {
    Scene* scene = Scene::create();
    auto* const layer = LoadingScene::create();
    scene->addChild(layer);
    return scene;
}
void LoadingScene::navigateToPlayGame(float timeDelay) {
    Scene* scene = PlayGameScene::createScene();
    TransitionFade* transition = TransitionFade::create(2, scene);
    Director::getInstance()->replaceScene(transition);
}

bool LoadingScene::init() {
    if (!Scene::init()) {
        return false;
    }
    auto const visibleSize = Director::getInstance()->getVisibleSize();

   
    backgr = Sprite::create("backgr_02.jpg");
    backgr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    backgr->setScale(1.6);
    this->addChild(backgr);
	
    auto demoTxt = Label::createWithTTF("Loading to game...", "fonts/Marker Felt.ttf", FONT_SIZE_DEFAULT);
    demoTxt->setColor(Color3B::WHITE);
    demoTxt->setPosition(Vec2(visibleSize.width / 2, 50));
    this->addChild(demoTxt);
	
    scheduleOnce(schedule_selector(LoadingScene::navigateToPlayGame), SSPLASH_TRANSITION_TIME + 1);
	return true;
}
