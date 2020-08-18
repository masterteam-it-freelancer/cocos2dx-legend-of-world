#include "MainMenuScene.h"
#include "ui/UIButton.h"
#include "PlayGameScene.h"
#include "MarketplaceScene.h"
#include "SettingGameScene.h"
#include "AboutScene.h"
#include "LoadingScene.h"
#include "LoadingScene_MidlleLevel.h"
#include "SplashScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene() {
    Scene* scene = Scene::create();
    auto* const layer = MainMenuScene::create();
    scene->addChild(layer);
    return scene;
}


bool MainMenuScene::init() {
    if (!Scene::init()) {
        return false;
    }

    auto const visibleSize = Director::getInstance()->getVisibleSize();
    demoTxt = Label::createWithTTF("Legend OF World", "fonts/Marker Felt.ttf", FONT_SIZE_DEFAULT * 2);
    auto backgr = Sprite::create("backgr_01.jpg");
    backgr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    backgr->setScale(1.6);
    this->addChild(backgr);
    demoTxt->setColor(Color3B::WHITE);
    demoTxt->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 10));
    this->addChild(demoTxt);


    ui::Button* btn_play = ui::Button::create();
    btn_play->setTitleColor(Color3B::WHITE);
    btn_play->setTitleText("PLAY GAME");
    btn_play->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 70));
    btn_play->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Scene* fixBugScene = LoadingScene::createScene();
            TransitionFade* transitionFixBug = TransitionFade::create(1, fixBugScene);
            Director::getInstance()->replaceScene(transitionFixBug);
            break;

        }
        });
    this->addChild(btn_play);


    ui::Button* btn_marketplace = ui::Button::create();
    btn_marketplace->setTitleColor(Color3B::WHITE);
    btn_marketplace->setTitleText("MARKET PLACE");
    btn_marketplace->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 100));
    btn_marketplace->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Scene* fixBugScene = MarketplaceScene::createScene();
            TransitionFade* transitionFixBug = TransitionFade::create(1, fixBugScene);
            Director::getInstance()->replaceScene(transitionFixBug);
            break;

        }
        });
    this->addChild(btn_marketplace);


    ui::Button* btn_about = ui::Button::create();
    btn_about->setTitleColor(Color3B::WHITE);
    btn_about->setTitleText("ABOUT");
    btn_about->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 130));
    btn_about->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Scene* fixBugScene = AboutScene::createScene();
            TransitionFade* transitionFixBug = TransitionFade::create(1, fixBugScene);
            Director::getInstance()->replaceScene(transitionFixBug);
            break;

        }
        });
    this->addChild(btn_about);

    ui::Button* btn_quit = ui::Button::create();
    btn_quit->setTitleColor(Color3B::WHITE);
    btn_quit->setTitleText("QUIT");
    btn_quit->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 160));
    btn_quit->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Scene* fixBugScene = AboutScene::createScene();
            TransitionFade* transitionFixBug = TransitionFade::create(1, fixBugScene);
            Director::getInstance()->replaceScene(transitionFixBug);
            break;

        }
        });
    this->addChild(btn_quit);
   
    return true;
}

