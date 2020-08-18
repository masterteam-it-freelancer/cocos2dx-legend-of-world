#include "PlayGameScene_HardestLevel.h"
#include <Box2D/include/Box2D/Common/b2Math.h>
#include <external\Box2D\include\Box2D\Collision\Shapes\b2EdgeShape.h>
#include "ResourceManager.h"
#include "PlaySceneFile/Monsters/CMonsterManager.h"
#include "PlaySceneFile/Champions/CChampionManager.h"

USING_NS_CC;

Scene* PlayGameScene_HardestLevel::createScene() {
    Scene* scene = Scene::create();
    Layer* hudLayer = Layer::create();
    Layer* hubLayer_02 = Layer::create();
    scene->addChild(hudLayer, 2);
    PlayGameScene_HardestLevel* layer = PlayGameScene_HardestLevel::createWithHUDAndTiledMap(hudLayer);
    scene->addChild(layer, 1);
    return scene;
}

PlayGameScene_HardestLevel* PlayGameScene_HardestLevel::createWithHUDAndTiledMap(Layer* hudLayer) {
    PlayGameScene_HardestLevel* object = new PlayGameScene_HardestLevel();
    object->setHUDLayer(hudLayer);
    if (object && object->init()) {
        object->autorelease();
        return object;
    }
}

bool PlayGameScene_HardestLevel::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {

    return false;
}

bool PlayGameScene_HardestLevel::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
    return false;
}

bool PlayGameScene_HardestLevel::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {
    return false;
}



/// <summary>
/// ///Prototype function for test game
/// </summary>


std::vector<DynamicObject*> PlayGameScene_HardestLevel::getAllDynamicObj() {
    return _allDynamicObjectAdded;
}

void PlayGameScene_HardestLevel::addAllHeroToScene() {
    ChampionManager::GetInstance()->ReadData("Champions.txt");
    cocos2d::log("Number of champion at resourceManager is: %d", ResourceManager::getInstance()->_allChampion.size());
    e_golem_01 = static_cast<Champion_Golem_1*>(ResourceManager::getInstance()->_allChampion.at(0));
    e_golem_01->changeDirection(1);
    e_golem_01->_objectSprite->setScale(0.3);
    controlChamp = e_golem_01;

}

void PlayGameScene_HardestLevel::addAllMonsterToScene() {
    MonsterManager::GetInstance()->ReadData("Monsters.txt");
    tiny_golem_01 = ResourceManager::getInstance()->getAllMonsterAdded().at(0);
    tiny_golem_02 = ResourceManager::getInstance()->getAllMonsterAdded().at(1);
    tiny_golem_03 = ResourceManager::getInstance()->getAllMonsterAdded().at(2);
    tiny_golem_04 = ResourceManager::getInstance()->getAllMonsterAdded().at(3);
    tiny_golem_05 = ResourceManager::getInstance()->getAllMonsterAdded().at(4);
    tiny_golem_06 = ResourceManager::getInstance()->getAllMonsterAdded().at(5);
    tiny_golem_07 = ResourceManager::getInstance()->getAllMonsterAdded().at(6);
    tiny_golem_08 = ResourceManager::getInstance()->getAllMonsterAdded().at(7);
    tiny_golem_09 = ResourceManager::getInstance()->getAllMonsterAdded().at(8);

    tiny_golem_01->_objectSprite->setScale(0.4);
    tiny_golem_02->_objectSprite->setScale(0.4);
    tiny_golem_03->_objectSprite->setScale(0.4);
    tiny_golem_04->_objectSprite->setScale(0.4);
    tiny_golem_05->_objectSprite->setScale(0.4);
    tiny_golem_06->_objectSprite->setScale(0.4);
    tiny_golem_07->_objectSprite->setScale(0.4);
    tiny_golem_08->_objectSprite->setScale(0.4);
    tiny_golem_09->_objectSprite->setScale(0.4);

    _canAttackObject.push_back(tiny_golem_01);
    _canAttackObject.push_back(tiny_golem_02);
    _canAttackObject.push_back(tiny_golem_03);
    _canAttackObject.push_back(tiny_golem_04);
    _canAttackObject.push_back(tiny_golem_05);
    _canAttackObject.push_back(tiny_golem_06);
    _canAttackObject.push_back(tiny_golem_07);
    _canAttackObject.push_back(tiny_golem_08);
    _canAttackObject.push_back(tiny_golem_09);

}

void PlayGameScene_HardestLevel::heroAttackAnEnemy(Champion* hero, DynamicObject* enemy) {
    Vec2 enemy_Pos = enemy->_prototype->getPosition();
    hero->_prototype->setPosition(enemy_Pos);
}


void PlayGameScene_HardestLevel::spawnCreepsPerMinutes(float dt) {

}

void PlayGameScene_HardestLevel::spawnMonsterAfterDied(float dt) {
    //reborn
    for (int i = 0; i < _allJungleMonsters.size(); i++) {
        if (_allJungleMonsters.at(i)->getState() == &MonsterState::dying) {
            timeSpawnCreep -= dt;
            if (timeSpawnCreep < 0) {
                //Reborn it
                _allJungleMonsters.at(i)->setState(&MonsterState::reborning);
                addChild(_allJungleMonsters.at(i)->_objectSprite);
                timeSpawnCreep = 30;
            }
        }
    }


}

void PlayGameScene_HardestLevel::setHUDLayer(Layer* layer) {
    hudLayer = layer;
}

void PlayGameScene_HardestLevel::updatePhysics(float dt) {
    world->Step(dt, 10, 10);

}

void PlayGameScene_HardestLevel::createPhysics() {
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

void PlayGameScene_HardestLevel::addAttackBtn(int x_Pos, int y_Pos) {
    attackBtn = Button::create("attack.png", "attack.png", "attack.png");
    attackBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("Click at attack btn");
            controlChamp->attack(&_canAttackObject);
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

void PlayGameScene_HardestLevel::addSkill01Btn(int xPos, int yPos) {
    skill_01Btn = Button::create("skill_01.png", "skill_01.png", "skill_01.png");
    skill_01Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("using skill 01");
            controlChamp->usingSkill_01(&_canAttackObject);
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

void PlayGameScene_HardestLevel::addSkill02Btn(int xPos, int yPos) {
    skill_02Btn = Button::create("skill_02.png", "skill_02.png", "skill_02.png");
    skill_02Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("using skill 02");
            controlChamp->usingSkill_02(&_canAttackObject);
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

void PlayGameScene_HardestLevel::addSkill03Btn(int xPos, int yPos) {
    skill_03Btn = Button::create("skill_03.png", "skill_03.png", "skill_03.png");
    skill_03Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("using skill 03");
            controlChamp->usingSkill_03(&_canAttackObject);
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

void PlayGameScene_HardestLevel::addSkill04Btn(int xPos, int yPos) {
    skill_04Btn = Button::create("skill_04.png", "skill_04.png", "skill_04.png");
    skill_04Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("using skill 04");
            controlChamp->usingSkill_04(&_canAttackObject);
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




void PlayGameScene_HardestLevel::addJoystick() {
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

void PlayGameScene_HardestLevel::addAllToHUDLayer() {
    auto const visibleSize = Director::getInstance()->getVisibleSize();
    _debugLabel = Label::create("current_knight_Debug", "Arial", 10);
    _debugLabel->setColor(Color3B::RED);
    _debugLabel->setPosition(Vec2(320, 50));
    hudLayer->addChild(_debugLabel);
    cocos2d::log("Create debug label completed");

    //Add enemy
    hudLayer->addChild(e_golem_01->_objectSprite);
    hudLayer->addChild(e_golem_01->_champIcon);

    hudLayer->addChild(e_golem_01->_HPBar->progressTimer);
    hudLayer->addChild(e_golem_01->_MPBar->progressTimer);

    //Add  monster & creeps
    hudLayer->addChild(tiny_golem_01->_objectSprite);
    hudLayer->addChild(tiny_golem_02->_objectSprite);
    hudLayer->addChild(tiny_golem_03->_objectSprite);
    hudLayer->addChild(tiny_golem_04->_objectSprite);
    hudLayer->addChild(tiny_golem_05->_objectSprite);
    hudLayer->addChild(tiny_golem_06->_objectSprite);
    hudLayer->addChild(tiny_golem_07->_objectSprite);
    hudLayer->addChild(tiny_golem_08->_objectSprite);
    hudLayer->addChild(tiny_golem_09->_objectSprite);

    hudLayer->addChild(tiny_golem_01->_HPBar->progressTimer);
    hudLayer->addChild(tiny_golem_02->_HPBar->progressTimer);
    hudLayer->addChild(tiny_golem_03->_HPBar->progressTimer);
    hudLayer->addChild(tiny_golem_04->_HPBar->progressTimer);
    hudLayer->addChild(tiny_golem_05->_HPBar->progressTimer);
    hudLayer->addChild(tiny_golem_06->_HPBar->progressTimer);
    hudLayer->addChild(tiny_golem_07->_HPBar->progressTimer);
    hudLayer->addChild(tiny_golem_08->_HPBar->progressTimer);
    hudLayer->addChild(tiny_golem_09->_HPBar->progressTimer);

    // camera follow the player
   //  runAction(Follow::create(controlChamp->_objectSprite, Rect(0, 0, 1920 * 3, 1080 * 3)));

    //joystick listener
    leftJoystick->onVelocityChanged = [=](SneakyJoystick* eventJoystick, Point oldValue, Point newValue) {
        cocos2d::log("Velocity x: %f y: %f", newValue.x, newValue.y);
    };

    //Set state for all champion

    e_golem_01->setState(&PlayerState::attacking);
    cocos2d::log("Set state for champion completed");

    //Set state for monster
    tiny_golem_01->setState(&MonsterState::attacking);
    tiny_golem_02->setState(&MonsterState::attacking);
    tiny_golem_03->setState(&MonsterState::attacking);
    tiny_golem_04->setState(&MonsterState::attacking);
    tiny_golem_05->setState(&MonsterState::attacking);
    tiny_golem_06->setState(&MonsterState::attacking);
    tiny_golem_07->setState(&MonsterState::attacking);
    tiny_golem_08->setState(&MonsterState::attacking);
    tiny_golem_09->setState(&MonsterState::attacking);
}

void PlayGameScene_HardestLevel::randomDropItem(float x_Pos, float y_Pos) {
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

bool PlayGameScene_HardestLevel::init() {
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


void PlayGameScene_HardestLevel::update(float fps) {
    //Update animation here
    if (controlChamp) {
        controlChamp->updateVelocity(leftJoystick->getVelocity());
        controlChamp->update(fps);

    }

    for (int i = 0; i < _canAttackObject.size(); i++) {
        if (_canAttackObject.at(i)) {
            if (Monster* enemy = dynamic_cast<Monster*> (_canAttackObject.at(i))) {
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

