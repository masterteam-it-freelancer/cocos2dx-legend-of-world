#include "AboutScene.h"
#include "Definitons.h"
#include "MainMenuScene.h"
#include "PlayGameScene.h"

USING_NS_CC;

Scene* AboutScene::createScene() {
    Scene* scene = Scene::create();
    auto* const layer = AboutScene::create();
    scene->addChild(layer);
    return scene;
}
void AboutScene::navigateToPlayGame(float timeDelay) {
    Scene* scene = MainMenuScene::createScene();
    TransitionFade* transition = TransitionFade::create(2, scene);
    Director::getInstance()->replaceScene(transition);
}

bool AboutScene::init() {
    if (!Scene::init()) {
        return false;
    }
    auto const visibleSize = Director::getInstance()->getVisibleSize();


    backgr = Sprite::create("backgr_02.jpg");
    backgr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    backgr->setScale(1.6);
    this->addChild(backgr);

    auto demoTxt = Label::createWithTTF("This game is product of VTC Academy ", "fonts/Marker Felt.ttf", 18);
    demoTxt->setColor(Color3B::WHITE);
    demoTxt->setPosition(Vec2(visibleSize.width / 2, 200));
    this->addChild(demoTxt);

    auto demoTxt_2 = Label::createWithTTF("Using Cocos2d-x Engine version 3.17", "fonts/Marker Felt.ttf", 18);
    demoTxt_2->setColor(Color3B::WHITE);
    demoTxt_2->setPosition(Vec2(visibleSize.width / 2, 180));
    this->addChild(demoTxt_2);

    auto demoTxt_3 = Label::createWithTTF("Made by Nguyen Manh Quynh( GD18) and Hoang Duy( GD17)", "fonts/Marker Felt.ttf", 18);
    demoTxt_3->setColor(Color3B::WHITE);
    demoTxt_3->setPosition(Vec2(visibleSize.width / 2, 160));
    this->addChild(demoTxt_3);
	
    auto demoTxt_4 = Label::createWithTTF("Support by teacher: Ho Nguyen Hoang Phuong", "fonts/Marker Felt.ttf", 18);
    demoTxt_4->setColor(Color3B::WHITE);
    demoTxt_4->setPosition(Vec2(visibleSize.width / 2, 140));
    this->addChild(demoTxt_4);
	
    scheduleOnce(schedule_selector(AboutScene::navigateToPlayGame), SSPLASH_TRANSITION_TIME + 5);
    return true;
}
