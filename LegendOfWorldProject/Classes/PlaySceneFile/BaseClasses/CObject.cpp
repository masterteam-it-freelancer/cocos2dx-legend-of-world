#include "CObject.h"

CObject::CObject(): _objectSprite(nullptr), _objectPhysicBody(nullptr){
} ;

CObject::CObject(cocos2d::Sprite* objSprite, std::string objName, std::string objDescription){
	_objectName = objName;
	_objectSprite = objSprite;
	_objectDescription = objDescription;
	_objectPhysicBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(_objectSprite->getContentSize()));
}

CObject::~CObject() = default;

cocos2d::Sprite* CObject::getSprite() {
	return _objectSprite;
}


int CObject::getTag() {
	return 0;
}

