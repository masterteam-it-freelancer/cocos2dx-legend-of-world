#include "SettingGameScene.h"
USING_NS_CC;

Scene* SettingGameScene::createScene() {
    Scene* scene = Scene::create();
    auto* const layer = SettingGameScene::create();
    scene->addChild(layer);
    return scene;
}

bool SettingGameScene::init() {
    if (!Scene::init()) {
        return false;
    }

    auto const visibleSize = Director::getInstance()->getVisibleSize();
    auto demoTxt = Label::create("This is setting game scene", "Arial", 30);
    demoTxt->setColor(Color3B::RED);
    demoTxt->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(demoTxt);

    return true;
}

