#pragma once
#include "cocos2d.h"
#include <external\Box2D\include\Box2D\Dynamics\b2Body.h>
#include <external\Box2D\include\Box2D\Dynamics\b2World.h>
#include <external\Box2D\include\Box2D\Collision\Shapes\b2PolygonShape.h>
#include <external/Box2D/include/Box2D/Dynamics/b2Fixture.h>
#define PTM_RATIO 32.0

class CObject{
//This class is super for all class in this scene
private:
public:

	
	 CObject();
     virtual ~CObject();
     cocos2d::Sprite* _objectSprite;
     cocos2d::Sprite* _prototype;
     std::string _objectName;
     std::string _objectDescription;
     cocos2d::PhysicsBody* _objectPhysicBody;
     b2Body* _objectB2PhysicBody;
     b2World* _objectB2PhysicWorld;

     cocos2d::Sprite* getSprite();
     virtual int getTag();
	
     CObject(cocos2d::Sprite* objSprite, std::string objName, std::string objDescription);
public:
   // virtual CObject* CreateObject();
};
