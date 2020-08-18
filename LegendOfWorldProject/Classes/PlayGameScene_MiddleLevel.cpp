#include "PlayGameScene_MiddleLevel.h"
#include <Box2D/include/Box2D/Common/b2Math.h>
#include <external\Box2D\include\Box2D\Collision\Shapes\b2EdgeShape.h>
#include "ResourceManager.h"
#include "PlaySceneFile/Monsters/CMonsterManager.h"
#include "PlaySceneFile/Champions/CChampionManager.h"

USING_NS_CC;

Scene* PlayGameScene_MiddleLevel::createScene() {
    Scene* scene = Scene::create();
    Layer* hudLayer = Layer::create();
    Layer* hubLayer_02 = Layer::create();
    scene->addChild(hudLayer, 2);
    PlayGameScene_MiddleLevel* layer = PlayGameScene_MiddleLevel::createWithHUDAndTiledMap(hudLayer);
    scene->addChild(layer, 1);
    return scene;
}

PlayGameScene_MiddleLevel* PlayGameScene_MiddleLevel::createWithHUDAndTiledMap(Layer* hudLayer) {
    PlayGameScene_MiddleLevel* object = new PlayGameScene_MiddleLevel();
    object->setHUDLayer(hudLayer);
    if (object && object->init()) {
        object->autorelease();
        return object;
    }
}

bool PlayGameScene_MiddleLevel::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {

    return false;
}

bool PlayGameScene_MiddleLevel::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
    return false;
}

bool PlayGameScene_MiddleLevel::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {
    return false;
}



/// <summary>
/// ///Prototype function for test game
/// </summary>


std::vector<DynamicObject*> PlayGameScene_MiddleLevel::getAllDynamicObj() {
    return _allDynamicObjectAdded;
}

void PlayGameScene_MiddleLevel::addAllHeroToScene() {
    ChampionManager::GetInstance()->ReadData("Champions.txt");
    cocos2d::log("Number of champion at resourceManager is: %d", ResourceManager::getInstance()->_allChampion.size());
    playerGolem = static_cast<Champion_Golem_1*>(ResourceManager::getInstance()->_allChampion.at(0));
    playerGolem->changeDirection(1);
    playerGolem->_objectSprite->setScale(0.3);
    controlChamp = playerGolem;

}

void PlayGameScene_MiddleLevel::addAllMonsterToScene() {
    MonsterManager::GetInstance()->ReadData("Monsters_02.txt");
    monster_01 = ResourceManager::getInstance()->getAllMonsterAdded().at(0);
    monster_02 = ResourceManager::getInstance()->getAllMonsterAdded().at(1);
    monster_03 = ResourceManager::getInstance()->getAllMonsterAdded().at(2);
    monster_04 = ResourceManager::getInstance()->getAllMonsterAdded().at(3);
    monster_05 = ResourceManager::getInstance()->getAllMonsterAdded().at(4);
    monster_06 = ResourceManager::getInstance()->getAllMonsterAdded().at(5);
    monster_07 = ResourceManager::getInstance()->getAllMonsterAdded().at(6);
    monster_08 = ResourceManager::getInstance()->getAllMonsterAdded().at(7);
    monster_09 = ResourceManager::getInstance()->getAllMonsterAdded().at(8);

    monster_01->_objectSprite->setScale(0.4);
    monster_02->_objectSprite->setScale(0.4);
    monster_03->_objectSprite->setScale(0.4);
    monster_04->_objectSprite->setScale(0.4);
    monster_05->_objectSprite->setScale(0.4);
    monster_06->_objectSprite->setScale(0.4);
    monster_07->_objectSprite->setScale(0.4);
    monster_08->_objectSprite->setScale(0.4);
    monster_09->_objectSprite->setScale(0.4);

    _canAttackObject_02.push_back(monster_01);
    _canAttackObject_02.push_back(monster_02);
    _canAttackObject_02.push_back(monster_03);
    _canAttackObject_02.push_back(monster_04);
    _canAttackObject_02.push_back(monster_05);
    _canAttackObject_02.push_back(monster_06);
    _canAttackObject_02.push_back(monster_07);
    _canAttackObject_02.push_back(monster_08);
    _canAttackObject_02.push_back(monster_09);

}

void PlayGameScene_MiddleLevel::heroAttackAnEnemy(Champion* hero, DynamicObject* enemy) {
    Vec2 enemy_Pos = enemy->_prototype->getPosition();
    hero->_prototype->setPosition(enemy_Pos);
}


void PlayGameScene_MiddleLevel::setHUDLayer(Layer* layer) {
    hudLayer = layer;
}

void PlayGameScene_MiddleLevel::updatePhysics(float dt) {
    world->Step(dt, 10, 10);

}

void PlayGameScene_MiddleLevel::createPhysics() {
    // world
    b2Vec2 gravity = b2Vec2(0.0f, 0.0f);
    world = new b2World(gravity);
    // contact listener
    contactListener = new ContactListener();
    world->SetContactListener(contactListener);

    // create collision wall and ground
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, (20 / PTM_RATIO));
    b2Body* _groundBody;
    _groundBody = world->CreateBody(&groundBodyDef);

    b2EdgeShape groundBox;
    b2FixtureDef groundBoxDef;
    groundBoxDef.shape = &groundBox;

    b2Fixture* _bottomFixture;

    groundBox.Set(b2Vec2(0, 0), b2Vec2(worldSize.width / PTM_RATIO, 0));
    _bottomFixture = _groundBody->CreateFixture(&groundBoxDef);

    groundBox.Set(b2Vec2(0, 0), b2Vec2(0, worldSize.height / PTM_RATIO));
    _groundBody->CreateFixture(&groundBoxDef);

    groundBox.Set(b2Vec2(0, worldSize.height / PTM_RATIO), b2Vec2(worldSize.width / PTM_RATIO,
        worldSize.height / PTM_RATIO));
    _groundBody->CreateFixture(&groundBoxDef);

    groundBox.Set(b2Vec2(worldSize.width / PTM_RATIO, worldSize.height / PTM_RATIO),
        b2Vec2(worldSize.width / PTM_RATIO, 0));
    _groundBody->CreateFixture(&groundBoxDef);
}

void PlayGameScene_MiddleLevel::addAttackBtn(int x_Pos, int y_Pos) {
    attackBtn = Button::create("attack.png", "attack.png", "attack.png");
    attackBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("Click at attack btn");
            controlChamp->attack(&_canAttackObject_02);
            controlChamp->input(Input::ATTACK_PRESS);
            break;
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });
    attackBtn->setPosition(Vec2(x_Pos, y_Pos));
    attackBtn->setScale(1.5);
    hudLayer->addChild(attackBtn);
}

void PlayGameScene_MiddleLevel::addSkill01Btn(int xPos, int yPos) {
    skill_01Btn = Button::create("skill_01.png", "skill_01.png", "skill_01.png");
    skill_01Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("using skill 01");
            controlChamp->usingSkill_01(&_canAttackObject_02);
            controlChamp->input(Input::USE_SKILL_01_PRESS);
            break;
        case ui::Widget::TouchEventType::ENDED:

            break;
        default:
            break;
        }
        });
    skill_01Btn->setPosition(Vec2(xPos, yPos));
    skill_01Btn->setScale(0.8);
    hudLayer->addChild(skill_01Btn);
}

void PlayGameScene_MiddleLevel::addSkill02Btn(int xPos, int yPos) {
    skill_02Btn = Button::create("skill_02.png", "skill_02.png", "skill_02.png");
    skill_02Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("using skill 02");
            controlChamp->usingSkill_02(&_canAttackObject_02);
            controlChamp->input(Input::USE_SKILL_02_PRESS);
            break;
        case ui::Widget::TouchEventType::ENDED:

            break;
        default:
            break;
        }
        });
    skill_02Btn->setPosition(Vec2(xPos, yPos));
    skill_02Btn->setScale(0.8);
    hudLayer->addChild(skill_02Btn);
}

void PlayGameScene_MiddleLevel::addSkill03Btn(int xPos, int yPos) {
    skill_03Btn = Button::create("skill_03.png", "skill_03.png", "skill_03.png");
    skill_03Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("using skill 03");
            controlChamp->usingSkill_03(&_canAttackObject_02);
            controlChamp->input(Input::USE_SKILL_03_PRESS);
            break;
        case ui::Widget::TouchEventType::ENDED:

            break;
        default:
            break;
        }
        });
    skill_03Btn->setPosition(Vec2(xPos, yPos));
    skill_03Btn->setScale(0.8);
    hudLayer->addChild(skill_03Btn);
}

void PlayGameScene_MiddleLevel::addSkill04Btn(int xPos, int yPos) {
    skill_04Btn = Button::create("skill_04.png", "skill_04.png", "skill_04.png");
    skill_04Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("using skill 04");
            controlChamp->usingSkill_04(&_canAttackObject_02);
            controlChamp->input(Input::USE_SKILL_04_PRESS);
            break;
        case ui::Widget::TouchEventType::ENDED:

            break;
        default:
            break;
        }
        });
    skill_04Btn->setPosition(Vec2(xPos, yPos));
    skill_04Btn->setScale(0.8);
    hudLayer->addChild(skill_04Btn);
}




void PlayGameScene_MiddleLevel::addJoystick() {
    auto const visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    worldSize = Size(1920 * 2, 1080 * 2);
    // add joystick
    int joystickOffset = 30;
    Rect joystickBaseDimensions = Rect(0, 0, 64.0f, 64.0f);
    Point joystickBasePosition = Point(origin.x + (joystickBaseDimensions.size.width / 2) + joystickOffset, origin.y + (joystickBaseDimensions.size.height / 2) + joystickOffset);

    Rect accelButtonDimensions = Rect(0, 0, 64.0f, 64.0f);
    Point accelButtonPosition = Point(origin.x + visibleSize.width - (joystickBaseDimensions.size.width / 2) - joystickOffset, origin.y + (joystickBaseDimensions.size.height / 2) + joystickOffset);
    Point accelButtonPosition_2 = Point(origin.x + visibleSize.width - (joystickBaseDimensions.size.width / 2) - joystickOffset * 2, origin.y + (joystickBaseDimensions.size.height / 2) + joystickOffset * 2);

    // add joystick base
    SneakyJoystickSkinnedBase* joystickBase = SneakyJoystickSkinnedBase::create();
    SneakyJoystick* joystick = new SneakyJoystick();
    joystick->initWithRect(joystickBaseDimensions);
    joystickBase->setBackgroundSprite(cocos2d::Sprite::create("UI/joystick/dpadDown.png"));
    joystickBase->setThumbSprite(cocos2d::Sprite::create("UI/joystick/joystickDown.png"));
    joystickBase->setJoystick(joystick);
    joystickBase->setPosition(joystickBasePosition);
    leftJoystick = joystickBase->getJoystick();
    joystickBase->setScale(4.0);
    hudLayer->addChild(joystickBase);
    cocos2d::log("Create joystick completed");

}

void PlayGameScene_MiddleLevel::addAllToHUDLayer() {
    auto const visibleSize = Director::getInstance()->getVisibleSize();
    _debugLabel = Label::create("current_knight_Debug", "Arial", 10);
    _debugLabel->setColor(Color3B::RED);
    _debugLabel->setPosition(Vec2(320, 50));
    hudLayer->addChild(_debugLabel);
    cocos2d::log("Create debug label completed");

    //Add enemy
    hudLayer->addChild(playerGolem->_objectSprite);
    hudLayer->addChild(playerGolem->_champIcon);

    hudLayer->addChild(playerGolem->_HPBar->progressTimer);
    hudLayer->addChild(playerGolem->_MPBar->progressTimer);

    //Add  monster & creeps
    hudLayer->addChild(monster_01->_objectSprite);
    hudLayer->addChild(monster_02->_objectSprite);
    hudLayer->addChild(monster_03->_objectSprite);
    hudLayer->addChild(monster_04->_objectSprite);
    hudLayer->addChild(monster_05->_objectSprite);
    hudLayer->addChild(monster_06->_objectSprite);
    hudLayer->addChild(monster_07->_objectSprite);
    hudLayer->addChild(monster_08->_objectSprite);
    hudLayer->addChild(monster_09->_objectSprite);

    hudLayer->addChild(monster_01->_HPBar->progressTimer);
    hudLayer->addChild(monster_02->_HPBar->progressTimer);
    hudLayer->addChild(monster_03->_HPBar->progressTimer);
    hudLayer->addChild(monster_04->_HPBar->progressTimer);
    hudLayer->addChild(monster_05->_HPBar->progressTimer);
    hudLayer->addChild(monster_06->_HPBar->progressTimer);
    hudLayer->addChild(monster_07->_HPBar->progressTimer);
    hudLayer->addChild(monster_08->_HPBar->progressTimer);
    hudLayer->addChild(monster_09->_HPBar->progressTimer);

    // camera follow the player
   //  runAction(Follow::create(controlChamp->_objectSprite, Rect(0, 0, 1920 * 3, 1080 * 3)));

    //joystick listener
    leftJoystick->onVelocityChanged = [=](SneakyJoystick* eventJoystick, Point oldValue, Point newValue) {
        cocos2d::log("Velocity x: %f y: %f", newValue.x, newValue.y);
    };

    //Set state for all champion

    playerGolem->setState(&PlayerState::attacking);
    cocos2d::log("Set state for champion completed");

    //Set state for monster
    monster_01->setState(&MonsterState::attacking);
    monster_02->setState(&MonsterState::attacking);
    monster_03->setState(&MonsterState::attacking);
    monster_04->setState(&MonsterState::attacking);
    monster_05->setState(&MonsterState::attacking);
    monster_06->setState(&MonsterState::attacking);
    monster_07->setState(&MonsterState::attacking);
    monster_08->setState(&MonsterState::attacking);
    monster_09->setState(&MonsterState::attacking);
}

void PlayGameScene_MiddleLevel::randomDropItem(float x_Pos, float y_Pos) {
    cocos2d::log("Enter random drop item");
    cocos2d::log("------------ Potion: %d", numberPotion);
    cocos2d::log("------------ Key: %d", numberKey);

    potion = Sprite::create("potion.png");
    potion->setScale(0.07);
    potion->setPosition(x_Pos, y_Pos);

    key = Sprite::create("key.png");
    key->setScale(0.07);
    key->setPosition(x_Pos, y_Pos);

    numberPotion += 1;
    if (numberPotion % 2 == true) {
        hudLayer->addChild(potion);
    }
    if (numberPotion % 3 == true && numberKey == 0) {
        numberKey = 1;
        hudLayer->addChild(key);
    }

}


//End --------------------

bool PlayGameScene_MiddleLevel::init() {
    if (!Scene::init()) {
        return false;
    }

    //    * For test here 

    auto* map = TMXTiledMap::create("MapofQuynh.tmx");
    map->setScaleX(1.3);
    map->setScaleY(1.2);
    hudLayer->addChild(map);

    addAllMonsterToScene();
    addAllHeroToScene();

    addJoystick();
    addAttackBtn(430, 70);
    addSkill01Btn(360, 65);
    addSkill02Btn(315, 65);
    addSkill03Btn(270, 65);
    addSkill04Btn(225, 65);

    addAllToHUDLayer(); // This must be last called function

    scheduleUpdate();
    return true;
}


void PlayGameScene_MiddleLevel::update(float fps) {
    //Update animation here
    if (controlChamp) {
        controlChamp->updateVelocity(leftJoystick->getVelocity());
        controlChamp->update(fps);

    }

    for (int i = 0; i < _canAttackObject_02.size(); i++) {
        if (_canAttackObject_02.at(i)) {
            if (Monster* enemy = dynamic_cast<Monster*> (_canAttackObject_02.at(i))) {
                enemy->update(fps);


                if (enemy->isDying == true) {
                    //remove when die
                    enemy->_HP->currentPoint = 1;
                    cocos2d::FadeTo* fade = FadeTo::create(1, 0);
                    enemy->_objectSprite->runAction(fade);
                    enemy->isDying = false;
                    randomDropItem(enemy->_objectSprite->getPositionX(), enemy->_objectSprite->getPositionY());

                }
            }
        }
    }


}

