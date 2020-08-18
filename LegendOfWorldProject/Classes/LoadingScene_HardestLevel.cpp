#include "LoadingScene_HardestLevel.h"
#include "Definitons.h"
#include "MainMenuScene.h"
#include "PlayGameScene_HardestLevel.h"

USING_NS_CC;

Scene* LoadingScene_HardestLevel::createScene() {
    Scene* scene = Scene::create();
    auto* const layer = LoadingScene_HardestLevel::create();
    scene->addChild(layer);
    return scene;
}
void LoadingScene_HardestLevel::navigateToPlayGame_HardestLevel(float timeDelay) {
    Scene* scene = PlayGameScene_HardestLevel::createScene();
    TransitionFade* transition = TransitionFade::create(2, scene);
    Director::getInstance()->replaceScene(transition);
}

bool LoadingScene_HardestLevel::init() {
    if (!Scene::init()) {
        return false;
    }
    auto const visibleSize = Director::getInstance()->getVisibleSize();


    backgr = Sprite::create("backgr_03.jpg");
    backgr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    backgr->setScale(1.6);
    this->addChild(backgr);

    auto demoTxt = Label::createWithTTF("Loading to game...", "fonts/Marker Felt.ttf", FONT_SIZE_DEFAULT);
    demoTxt->setColor(Color3B::WHITE);
    demoTxt->setPosition(Vec2(visibleSize.width / 2, 50));
    this->addChild(demoTxt);

    scheduleOnce(schedule_selector(LoadingScene_HardestLevel::navigateToPlayGame_HardestLevel), SSPLASH_TRANSITION_TIME + 1);
    return true;
}
