#include "MarketplaceScene.h"
#include "Definitons.h"
#include "MainMenuScene.h"
#include "PlayGameScene.h"

USING_NS_CC;

Scene* MarketplaceScene::createScene() {
    Scene* scene = Scene::create();
    auto* const layer = MarketplaceScene::create();
    scene->addChild(layer);
    return scene;
}
void MarketplaceScene::navigateToPlayGame(float timeDelay) {
    Scene* scene = MainMenuScene::createScene();
    TransitionFade* transition = TransitionFade::create(2, scene);
    Director::getInstance()->replaceScene(transition);
}

bool MarketplaceScene::init() {
    if (!Scene::init()) {
        return false;
    }
    auto const visibleSize = Director::getInstance()->getVisibleSize();


    backgr = Sprite::create("backgr_02.jpg");
    backgr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    backgr->setScale(1.6);
    this->addChild(backgr);

    auto demoTxt = Label::createWithTTF("This future update soon...", "fonts/Marker Felt.ttf", FONT_SIZE_DEFAULT + 10);
    demoTxt->setColor(Color3B::WHITE);
    demoTxt->setPosition(Vec2(visibleSize.width / 2, 100));
    this->addChild(demoTxt);

    scheduleOnce(schedule_selector(MarketplaceScene::navigateToPlayGame), SSPLASH_TRANSITION_TIME + 3);
    return true;
}
