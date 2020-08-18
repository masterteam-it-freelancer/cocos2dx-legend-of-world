
#include "SceneManager.h"
#include "SplashScene.h"
#include "MainMenuScene.h"
#include "PlayGameScene.h"

USING_NS_CC;

SceneManager* SceneManager::_instance = nullptr;

SceneManager* SceneManager::getInstance() {
	if (_instance != nullptr)
		return _instance;

	_instance = new SceneManager();
	return _instance;
}

SceneManager::SceneManager()
	:_score(0)
	, _scoreLabel(nullptr) {

}

CScene* SceneManager::createScene(int screenId) {
	// switch (screenId) {
	// case EScene::SPLASH_SCENE:
	// 	return SplashScene::createScene();
	//
	// case EScene::MAIN_MENU_SCENE:
	// 	return MainMenuScene::createScene();
	//
	// case EScene::PLAY_GAME_SCENE:
	// 	return PlayGameScene::createScene();
	//
	// }
	return nullptr;
}

CScene* SceneManager::createStartScene() {
	return createScene(EScene::SPLASH_SCENE);
}

void SceneManager::replaceScene(int sceneId) {
	Director::getInstance()->replaceScene(TransitionFade::create(2, createScene(sceneId)));
}

void SceneManager::pushScene(int sceneId) {
	Director::getInstance()->pushScene(TransitionFade::create(2, createScene(sceneId)));
}

void SceneManager::popLastScene() {
	Director::getInstance()->popScene();
}

CScene* SceneManager::getCurrentScene() {
	return dynamic_cast<CScene*>(Director::getInstance()->getRunningScene());
}

void SceneManager::increaseScore() {

}

void SceneManager::reset() {
	_score = 0;
}
