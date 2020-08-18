#include "SplashScene.h"
#include "Definitons.h"
#include "MainMenuScene.h"
#include "PlayGameScene.h"

USING_NS_CC;

Scene* SplashScene::createScene(){
    Scene* scene = Scene::create();
    auto* const layer = SplashScene::create();
    scene->addChild(layer);
    return scene;
}
void SplashScene::NavigateToMainMenuScene(float timeDelay) {
    Scene* scene = MainMenuScene::createScene();
    TransitionFade* transition = TransitionFade::create(SSPLASH_TRANSITION_TIME, scene);
    Director::getInstance()->replaceScene(transition);
}

bool SplashScene::init(){
    if( !Scene::init()){
        return false;
    }

    auto const visibleSize = Director::getInstance()->getVisibleSize();
    auto demoTxt = Label::createWithTTF("Legend OF World","fonts/Marker Felt.ttf",FONT_SIZE_DEFAULT * 3);
    demoTxt->setColor(Color3B::WHITE);
    demoTxt->setPosition(Vec2(visibleSize.width/ 2, visibleSize.height - 100));
    this->addChild(demoTxt);

    scheduleOnce(schedule_selector(SplashScene::NavigateToMainMenuScene), 2);
    return true;
}