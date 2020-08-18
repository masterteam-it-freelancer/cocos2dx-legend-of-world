#include "LoadingScene_MidlleLevel.h"
#include "Definitons.h"
#include "MainMenuScene.h"
#include "PlayGameScene.h"
#include "PlayGameScene_MiddleLevel.h"

USING_NS_CC;

Scene* LoadingScene_MidlleLevel::createScene() {
    Scene* scene = Scene::create();
    auto* const layer = LoadingScene_MidlleLevel::create();
    scene->addChild(layer);
    return scene;
}
void LoadingScene_MidlleLevel::navigateToPlayGame_MidlleLevel(float timeDelay) {
    Scene* scene = PlayGameScene_MiddleLevel::createScene();
    TransitionFade* transition = TransitionFade::create(2, scene);
    Director::getInstance()->replaceScene(transition);
}

bool LoadingScene_MidlleLevel::init() {
    if (!Scene::init()) {
        return false;
    }
    auto const visibleSize = Director::getInstance()->getVisibleSize();


    backgr = Sprite::create("backgr_02.jpg");
    backgr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    backgr->setScale(1.6);
    this->addChild(backgr);

    auto demoTxt = Label::createWithTTF("Loading to next game...", "fonts/Marker Felt.ttf", FONT_SIZE_DEFAULT);
    demoTxt->setColor(Color3B::WHITE);
    demoTxt->setPosition(Vec2(visibleSize.width / 2, 50));
    this->addChild(demoTxt);

    scheduleOnce(schedule_selector(LoadingScene_MidlleLevel::navigateToPlayGame_MidlleLevel), SSPLASH_TRANSITION_TIME + 1);
    return true;
}
