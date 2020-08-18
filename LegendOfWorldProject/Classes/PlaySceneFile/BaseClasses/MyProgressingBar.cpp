#include "MyProgressingBar.h"

MyProgressingBar::MyProgressingBar(){
	
}

MyProgressingBar::~MyProgressingBar(){
	
}


void MyProgressingBar::create(std::string fileSource){
	cocos2d::Sprite *healthBar = cocos2d::Sprite::create(fileSource);
	progressTimer = cocos2d::ProgressTimer::create(healthBar);
	progressTimer->setType(cocos2d::ProgressTimer::Type::BAR);
	progressTimer->setScaleX(0.2);
	progressTimer->setScaleY(0.3);
	progressTimer->setBarChangeRate(cocos2d::Vec2(1, 0));
	progressTimer->setMidpoint(cocos2d::Vec2(0, 0.5));
	progressTimer->setPercentage(100);
}
