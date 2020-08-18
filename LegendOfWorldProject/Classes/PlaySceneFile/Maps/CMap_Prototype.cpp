#include "CMap_Prototype.h"

void CMap_PRaotoype::init(){
	cocos2d::TMXTiledMap* sprite;
	sprite = TMXTiledMap::create("LOW_Map.tmx");
	this->addChild(sprite, 0);

	this->loadPhysic("Blocked_Tiles", TAG_GROUND);

}

void CMap_Prototype::loadPhysic(const char* layerName, int tagName) {
	//ground physic
	auto physicNode = Node::create();
	this->addChild(physicNode);
	auto group = sprite->getObjectGroup(layerName);
	auto& objects = group->getObjects();
	for (auto& obj : objects) {
		ValueMap& dict = obj.asValueMap();

		float x = dict["x"].asFloat();
		float y = dict["y"].asFloat();
		float width = dict["width"].asFloat();
		float height = dict["height"].asFloat();
		if (physicNode->getPhysicsBody() == nullptr) {
			auto body = PhysicsBody::create();
			body->setDynamic(false);
			body->setRotationEnable(false);

			physicNode->addComponent(body);
		}
		auto body = physicNode->getPhysicsBody();
		auto offset = Vec2(x + width / 2.0f, y + height / 2.0f);
		auto material = PHYSICSBODY_MATERIAL_DEFAULT;
		material.friction = 0.0f;
		auto sharp = body->addShape(PhysicsShapeBox::create(Size(width, height), material, offset));
		//allow physic world detect contact
		body->setContactTestBitmask(0xFFFFFFFF);
		body->setTag(tagName);
	}
}