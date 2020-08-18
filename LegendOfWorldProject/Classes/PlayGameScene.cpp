#include "PlayGameScene.h"
#include <Box2D/include/Box2D/Common/b2Math.h>
#include <external\Box2D\include\Box2D\Collision\Shapes\b2EdgeShape.h>

#include "MainMenuScene.h"
#include "ResourceManager.h"
#include "SimpleAudioEngine.h"
#include "PlaySceneFile/Monsters/CMonsterManager.h"
#include "PlaySceneFile/Champions/CChampionManager.h"

USING_NS_CC;

Scene* PlayGameScene::createScene() {
    Scene* scene = Scene::create();
    Layer* hudLayer = Layer::create();
    Layer* hubLayer_02 = Layer::create();
    scene->addChild(hudLayer, 2);
    PlayGameScene* layer = PlayGameScene::createWithHUDAndTiledMap(hudLayer);
    scene->addChild(layer, 1);
    return scene;
}

PlayGameScene* PlayGameScene::createWithHUDAndTiledMap(Layer* hudLayer) {
    PlayGameScene* object = new PlayGameScene();
    object->setHUDLayer(hudLayer);
    if (object && object->init()) {
        object->autorelease();
        return object;
    }
}

bool PlayGameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
   
	return false;
}

bool PlayGameScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {
    return false;
}

bool PlayGameScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {
    return false;
}



/// <summary>
/// ///Prototype function for test game
/// </summary>


std::vector<DynamicObject*> PlayGameScene::getAllDynamicObj() {
    return _allDynamicObjectAdded;
}

void PlayGameScene::addAllHeroToScene(){
    ChampionManager::GetInstance()->ReadData("Champions.txt"); 
    cocos2d::log("Number of champion at resourceManager is: %d", ResourceManager::getInstance()->_allChampion.size());
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    e_golem_01 = static_cast<Champion_Golem_1*>(ResourceManager::getInstance()->_allChampion.at(0));
    e_golem_01->changeDirection(2);
    e_golem_01->_objectSprite->setScale(0.3);
    controlChamp = e_golem_01;
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    knight_01 = static_cast<Champion_Knight_1*>(ResourceManager::getInstance()->_allChampion.at(0));
    fairy_01 = static_cast<Champion_ElfFairy_1*>(ResourceManager::getInstance()->_allChampion.at(3));
    archer_01 = static_cast<Champion_ElfArcher_1*>(ResourceManager::getInstance()->_allChampion.at(4));
	e_knight_02 = static_cast<Champion_Knight_2*>(ResourceManager::getInstance()->_allChampion.at(1));
    e_knight_03 = static_cast<Champion_Knight_3*>(ResourceManager::getInstance()->_allChampion.at(2));
    e_golem_01 = static_cast<Champion_Golem_1*>(ResourceManager::getInstance()->_allChampion.at(5));

	e_knight_02->changeDirection(1);
    e_knight_03->changeDirection(1);
    e_golem_01->changeDirection(1);

    knight_01->_isControl = true;
    controlChamp = knight_01;

    _allDynamicObjectAdded.push_back(knight_01);
    _allDynamicObjectAdded.push_back(fairy_01);
    _allDynamicObjectAdded.push_back(archer_01);
    _allDynamicObjectAdded.push_back(e_knight_02);
    _allDynamicObjectAdded.push_back(e_knight_03);
    _allDynamicObjectAdded.push_back(e_golem_01);

    _canAttackObject.push_back(e_golem_01);
    _canAttackObject.push_back(e_knight_02);
    _canAttackObject.push_back(e_knight_03);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character

}

void PlayGameScene::addAllMonsterToScene(){
    MonsterManager::GetInstance()->ReadData("Monsters.txt");
    tiny_golem_01 = ResourceManager::getInstance()->getAllMonsterAdded().at(0);
    tiny_golem_02 = ResourceManager::getInstance()->getAllMonsterAdded().at(1);
<<<<<<< HEAD
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
=======
    bigBoss = ResourceManager::getInstance()->getAllMonsterAdded().at(2);
    knight_boss = ResourceManager::getInstance()->getAllMonsterAdded().at(3);
    monk_boss = ResourceManager::getInstance()->getAllMonsterAdded().at(4);
    human_melee_creep_01 = ResourceManager::getInstance()->getAllMonsterAdded().at(5);
    human_melee_creep_02 = ResourceManager::getInstance()->getAllMonsterAdded().at(6);
    human_melee_creep_03 = ResourceManager::getInstance()->getAllMonsterAdded().at(7);
    orc_melee_creep_01 = ResourceManager::getInstance()->getAllMonsterAdded().at(8);
    orc_melee_creep_02 = ResourceManager::getInstance()->getAllMonsterAdded().at(9);
    orc_melee_creep_03 = ResourceManager::getInstance()->getAllMonsterAdded().at(10);
    knight_creeps_01 = ResourceManager::getInstance()->getAllMonsterAdded().at(11);
    knight_creeps_02 = ResourceManager::getInstance()->getAllMonsterAdded().at(12);
    monk_creeps_01 = ResourceManager::getInstance()->getAllMonsterAdded().at(13);
    monk_creeps_02 = ResourceManager::getInstance()->getAllMonsterAdded().at(14);
    orc_range_creep_01 = ResourceManager::getInstance()->getAllMonsterAdded().at(15);
    orc_range_creep_02 = ResourceManager::getInstance()->getAllMonsterAdded().at(16);
    human_range_creep_01 = ResourceManager::getInstance()->getAllMonsterAdded().at(17);
    human_range_creep_02 = ResourceManager::getInstance()->getAllMonsterAdded().at(18);

    tiny_golem_01->_objectSprite->setScale(0.2);
    tiny_golem_02->_objectSprite->setScale(0.2);
    tiny_golem_02->changeDirection(1);
	bigBoss->_objectSprite->setScale(0.8);
    orc_melee_creep_01->changeDirection(1);
	
    orc_melee_creep_02->_objectSprite->setPositionX(395);
    orc_melee_creep_02->changeDirection(1);

    orc_melee_creep_03->_objectSprite->setPositionX(385);
    orc_melee_creep_03->changeDirection(1);

    orc_range_creep_02->_objectSprite->setPositionX(420);
    orc_range_creep_01->changeDirection(1);
    orc_range_creep_02->changeDirection(1);
	
    human_melee_creep_02->_objectSprite->setPositionX(70);
    human_melee_creep_03->_objectSprite->setPositionX(80);
    human_range_creep_02->_objectSprite->setPositionX(40);

    knight_creeps_02->_objectSprite->setPositionX(210);
    monk_creeps_02->_objectSprite->setPositionX(260);

    _canAttackObject.push_back(tiny_golem_01);
    _canAttackObject.push_back(tiny_golem_02);
    _canAttackObject.push_back(bigBoss);
    _canAttackObject.push_back(knight_boss);
    _canAttackObject.push_back(monk_boss);
    _canAttackObject.push_back(knight_creeps_01);
    _canAttackObject.push_back(knight_creeps_02);
    _canAttackObject.push_back(monk_creeps_01);
    _canAttackObject.push_back(monk_creeps_02);
    _canAttackObject.push_back(orc_melee_creep_01);
    _canAttackObject.push_back(orc_melee_creep_02);
    _canAttackObject.push_back(orc_melee_creep_03);
    _canAttackObject.push_back(orc_range_creep_01);
    _canAttackObject.push_back(orc_range_creep_02);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character

}

void PlayGameScene::heroAttackAnEnemy(Champion *hero, DynamicObject *enemy){
    Vec2 enemy_Pos = enemy->_prototype->getPosition();
    hero->_prototype->setPosition(enemy_Pos);
}


void PlayGameScene::spawnCreepsPerMinutes(float dt){
	
}

void PlayGameScene::spawnMonsterAfterDied(float dt){
	//reborn
	for(int i =0; i < _allJungleMonsters.size(); i ++){
		if(_allJungleMonsters.at(i)->getState() == &MonsterState::dying){
            timeSpawnCreep -= dt;
			if(timeSpawnCreep < 0){
				//Reborn it
                _allJungleMonsters.at(i)->setState(&MonsterState::reborning);
                addChild(_allJungleMonsters.at(i)->_objectSprite);
				timeSpawnCreep = 30;	
			}
		}
	}

	
}

void PlayGameScene::setHUDLayer(Layer* layer){
     hudLayer = layer;
}

void PlayGameScene::updatePhysics(float dt){
    world->Step(dt, 10, 10);

}

void PlayGameScene::createPhysics(){
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

void PlayGameScene::addAttackBtn(int x_Pos, int y_Pos){
    attackBtn = Button::create("attack.png", "attack.png", "attack.png");
    attackBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("Attack a monster");       
            break;
        case ui::Widget::TouchEventType::ENDED:
            _debugLabel->setString(" ");
            controlChamp->attack(&_canAttackObject);
            controlChamp->input(Input::ATTACK_PRESS);
            break;
        default:
            break;
        }
        });
    attackBtn->setPosition(Vec2(x_Pos, y_Pos));
    attackBtn->setScale(1.5);
    hudLayer->addChild(attackBtn);
}

void PlayGameScene::addSkill01Btn(int xPos, int yPos){
    skill_01Btn = Button::create("skill_01.png", "skill_01.png", "skill_01.png");
    skill_01Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("Attack monster with critical damage");        
        	break;
        case ui::Widget::TouchEventType::ENDED:
            _debugLabel->setString(" ");
            controlChamp->usingSkill_01(&_canAttackObject);
            controlChamp->input(Input::USE_SKILL_01_PRESS);
            break;
        default:
            break;
        }
        });
    skill_01Btn->setPosition(Vec2(xPos, yPos));
    skill_01Btn->setScale(0.8);
    hudLayer->addChild(skill_01Btn);
}

void PlayGameScene::addSkill02Btn(int xPos, int yPos){
    skill_02Btn = Button::create("skill_02.png", "skill_02.png", "skill_02.png");
    skill_02Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("Restore HP and MP for you");       
            break;
        case ui::Widget::TouchEventType::ENDED:
            _debugLabel->setString(" ");
            controlChamp->usingSkill_02(&_canAttackObject);
            controlChamp->input(Input::USE_SKILL_02_PRESS);
            break;
        default:
            break;
        }
        });
    skill_02Btn->setPosition(Vec2(xPos, yPos));
    skill_02Btn->setScale(0.8);
    hudLayer->addChild(skill_02Btn);
}

void PlayGameScene::addSkill03Btn(int xPos, int yPos){
    skill_03Btn = Button::create("skill_03.png", "skill_03.png", "skill_03.png");
    skill_03Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("Kill a monster but you will lose HP");
            break;
        case ui::Widget::TouchEventType::ENDED:
            _debugLabel->setString(" ");
            controlChamp->usingSkill_03(&_canAttackObject);
            controlChamp->input(Input::USE_SKILL_03_PRESS);
            break;
        default:
            break;
        }
        });
    skill_03Btn->setPosition(Vec2(xPos, yPos));
    skill_03Btn->setScale(0.8);
    hudLayer->addChild(skill_03Btn);
}

void PlayGameScene::addSkill04Btn(int xPos, int yPos){
    skill_04Btn = Button::create("skill_04.png", "skill_04.png", "skill_04.png");
    skill_04Btn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            _debugLabel->setString("Attack a monster will restore your HP");
            break;
        case ui::Widget::TouchEventType::ENDED:
            _debugLabel->setString(" ");
            controlChamp->usingSkill_04(&_canAttackObject);
            controlChamp->input(Input::USE_SKILL_04_PRESS);
            break;
        default:
            break;
        }
        });
    skill_04Btn->setPosition(Vec2(xPos, yPos));
    skill_04Btn->setScale(0.8);
    hudLayer->addChild(skill_04Btn);
}

void PlayGameScene::addQuitGameBtn(int xPos, int yPos) {
    quitGameBtn = Button::create("backbtn.png", "backbtn.png", "backbtn.png");
    quitGameBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
           
            break;
        case ui::Widget::TouchEventType::ENDED:
            backtoMainMenu();
            break;
        default:
            break;
        }
        });
    quitGameBtn->setPosition(Vec2(xPos, yPos));
    quitGameBtn->setScale(0.4);
    hudLayer->addChild(quitGameBtn);
}

void PlayGameScene::addplayAgainBtn(int xPos, int yPos) {
    quitGameBtn = Button::create("reborn.png", "reborn.png", "reborn.png");
    quitGameBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:

            break;
        case ui::Widget::TouchEventType::ENDED:
<<<<<<< HEAD
            rebornGame();
         
=======
            _debugLabel->setString("Change hero");
                
                if (controlChamp == _allDynamicObjectAdded[0])
                    controlChamp = (Champion*)_allDynamicObjectAdded[1];
                else if (controlChamp == _allDynamicObjectAdded[1])
                    controlChamp = (Champion*)_allDynamicObjectAdded[2];
                else if (controlChamp == _allDynamicObjectAdded[2])
                    controlChamp = (Champion*)_allDynamicObjectAdded[0];
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
            break;
        default:
            break;
        }
        });
    quitGameBtn->setPosition(Vec2(xPos, yPos));
    quitGameBtn->setScale(0.8);
    hudLayer->addChild(quitGameBtn);
}

void PlayGameScene::addLostGameBtn(int xPos, int yPos) {
    lostGame = Button::create("quit.png", "quit.png", "quit.png");
    lostGame->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:

            break;
        case ui::Widget::TouchEventType::ENDED:
            backtoMainMenu();
        	
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
            break;
        default:
            break;
        }
        });
    lostGame->setPosition(Vec2(xPos, yPos));
    lostGame->setScale(0.8);
    hudLayer->addChild(lostGame);
}

void PlayGameScene::addWinGameBtn(int xPos, int yPos) {
    auto const visibleSize = Director::getInstance()->getVisibleSize();
    auto demoTxt = Label::createWithTTF("You have completed this quest...", "fonts/Marker Felt.ttf", FONT_SIZE_DEFAULT);
    demoTxt->setColor(Color3B::WHITE);
    demoTxt->setPosition(Vec2(visibleSize.width / 2, 250));
    winGame = Button::create("wingame.png", "wingame.png", "wingame.png");
    winGame->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            backtoMainMenu();

=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
            break;
        default:
            break;
        }
        });
    winGame->setPosition(Vec2(xPos, yPos));
    winGame->setScale(0.5);
    hudLayer->addChild(winGame);
    hudLayer->addChild(demoTxt);

}

void PlayGameScene::backtoMainMenu(){
    Scene* scene = MainMenuScene::createScene();
    TransitionFade* transition = TransitionFade::create(2, scene);
    Director::getInstance()->replaceScene(transition);
}

void PlayGameScene::rebornGame() {
    controlChamp->_HP->restorePoint(1000);
    controlChamp->_MP->restorePoint(500);
    controlChamp->setState(&PlayerState::attacking);
    controlChamp->_objectSprite->setPosition(450,140);
}


void PlayGameScene::addJoystick(){
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

void PlayGameScene::addAllToHUDLayer(){
    auto const visibleSize = Director::getInstance()->getVisibleSize();
    _debugLabel = Label::create("Click at any skill to get infomation", "Arial", 10);
    _debugLabel->setColor(Color3B::RED);
    _debugLabel->setPosition(Vec2(300,90));
    hudLayer->addChild(_debugLabel);
    cocos2d::log("Create debug label completed");

    //Add hero to scene
    hudLayer->addChild(knight_01->_objectSprite);
    hudLayer->addChild(fairy_01->_objectSprite);
    hudLayer->addChild(archer_01->_objectSprite);
    hudLayer->addChild(knight_01->champHP);
    hudLayer->addChild(fairy_01->champHP);
    hudLayer->addChild(archer_01->champHP);
    hudLayer->addChild(knight_01->champMP);
    hudLayer->addChild(fairy_01->champMP);
    hudLayer->addChild(archer_01->champMP);

    //Add enemy
    hudLayer->addChild(e_golem_01->_objectSprite);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    hudLayer->addChild(e_golem_01->_champIcon);

    hudLayer->addChild(e_golem_01->_HPBar->progressTimer);
    hudLayer->addChild(e_golem_01->_MPBar->progressTimer);
   
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    hudLayer->addChild(e_knight_02->_objectSprite);
    hudLayer->addChild(e_knight_03->_objectSprite);
    hudLayer->addChild(e_golem_01->champHP);
    hudLayer->addChild(e_knight_02->champHP);
    hudLayer->addChild(e_knight_03->champHP);
    hudLayer->addChild(e_golem_01->champMP);
    hudLayer->addChild(e_knight_02->champMP);
    hudLayer->addChild(e_knight_03->champMP);

<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    //Add  monster & creeps
    hudLayer->addChild(tiny_golem_01->_objectSprite);
    hudLayer->addChild(tiny_golem_02->_objectSprite);
<<<<<<< HEAD
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
   
=======
    hudLayer->addChild(tiny_golem_02->MonsterHP);
    hudLayer->addChild(bigBoss->_objectSprite);
    hudLayer->addChild(bigBoss->MonsterHP);
    hudLayer->addChild(knight_boss->_objectSprite);
    hudLayer->addChild(monk_boss->_objectSprite);
    hudLayer->addChild(knight_creeps_01->_objectSprite);
    hudLayer->addChild(knight_creeps_02->_objectSprite);
    hudLayer->addChild(monk_creeps_01->_objectSprite);
    hudLayer->addChild(monk_creeps_02->_objectSprite);
    hudLayer->addChild(orc_melee_creep_01->_objectSprite);
    hudLayer->addChild(orc_melee_creep_02->_objectSprite);
    hudLayer->addChild(orc_melee_creep_03->_objectSprite);
    hudLayer->addChild(orc_range_creep_01->_objectSprite);
    hudLayer->addChild(orc_range_creep_02->_objectSprite);
    hudLayer->addChild(human_melee_creep_01->_objectSprite);
    hudLayer->addChild(human_melee_creep_02->_objectSprite);
    hudLayer->addChild(human_melee_creep_03->_objectSprite);
    hudLayer->addChild(human_range_creep_01->_objectSprite);
    hudLayer->addChild(human_range_creep_02->_objectSprite);

<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    // camera follow the player
   //  runAction(Follow::create(controlChamp->_objectSprite, Rect(0, 0, 1920 * 3, 1080 * 3)));

    //joystick listener
    leftJoystick->onVelocityChanged = [=](SneakyJoystick* eventJoystick, Point oldValue, Point newValue) {
        cocos2d::log("Velocity x: %f y: %f", newValue.x, newValue.y);
    };

    //Set state for all champion
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  
    e_golem_01->setState(&PlayerState::attacking);
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    knight_01->setState(&PlayerState::usingSkill);
    e_knight_02->setState(&PlayerState::usingSkill);
    fairy_01->setState(&PlayerState::usingSkill);
    archer_01->setState(&PlayerState::usingSkill);
    e_golem_01->setState(&PlayerState::usingSkill);
    e_knight_02->setState(&PlayerState::usingSkill);
    e_knight_03->setState(&PlayerState::usingSkill);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    cocos2d::log("Set state for champion completed");

    //Set state for monster
    tiny_golem_01->setState(&MonsterState::attacking);
    tiny_golem_02->setState(&MonsterState::attacking);
<<<<<<< HEAD
    tiny_golem_03->setState(&MonsterState::attacking);
    tiny_golem_04->setState(&MonsterState::attacking);
    tiny_golem_05->setState(&MonsterState::attacking);
    tiny_golem_06->setState(&MonsterState::attacking);
    tiny_golem_07->setState(&MonsterState::attacking);
    tiny_golem_08->setState(&MonsterState::attacking);
    tiny_golem_09->setState(&MonsterState::attacking);
}

void PlayGameScene::randomDropItem(float x_Pos, float y_Pos){
   
    potion = Sprite::create("potion.png");
    potion->setScale(0.07);	
    potion->setPosition(x_Pos, y_Pos);
	
    key = Sprite::create("key.png");
    key->setScale(0.07);
    key->setPosition(x_Pos, y_Pos);

    numberPotion += 1;
	if(numberPotion % 2 == true){
        hudLayer->addChild(potion);
        controlChamp->_HP->restorePoint(300);
        controlChamp->_MP->restorePoint(300);
        _debugLabel->setString("Used a potion - restore a little HP and MP");
        cocos2d::FadeTo* fade = FadeTo::create(3, 0);
        potion->runAction(fade);
=======
    knight_boss->setState(&MonsterState::attacking);
    monk_boss->setState(&MonsterState::attacking);
    knight_creeps_01->setState(&MonsterState::attacking);
    knight_creeps_02->setState(&MonsterState::attacking);
    monk_creeps_01->setState(&MonsterState::attacking);
    monk_creeps_02->setState(&MonsterState::attacking);
    orc_melee_creep_01->setState(&MonsterState::attacking);
    orc_melee_creep_02->setState(&MonsterState::attacking);
    orc_melee_creep_03->setState(&MonsterState::attacking);
    orc_range_creep_01->setState(&MonsterState::attacking);
    orc_range_creep_02->setState(&MonsterState::attacking);
    human_melee_creep_01->setState(&MonsterState::attacking);
    human_melee_creep_02->setState(&MonsterState::attacking);
    human_melee_creep_03->setState(&MonsterState::attacking);
    human_range_creep_01->setState(&MonsterState::attacking);
    human_range_creep_02->setState(&MonsterState::attacking);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character

	}
    if(numberPotion % 5 == true && numberKey == 0){
        numberKey = 1;
        hudLayer->addChild(key);
        controlChamp->_objectSprite->stopAllActions();
        controlChamp->_objectSprite->runAction(RepeatForever::create(controlChamp->runAnimate()));
        cocos2d::FadeTo* fade = FadeTo::create(3, 0);
        key->runAction(fade);
	      auto const visibleSize = Director::getInstance()->getVisibleSize();
	      addWinGameBtn(visibleSize.width / 2, 200);
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character

    }
	
}


//End --------------------

bool PlayGameScene::init() {
      if (!Scene::init()) {
          return false;
      }
	
	//    * For test here 


      // auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
      // audio->playBackgroundMusic("backgrMusic.mp3", true);

	
     auto* map = TMXTiledMap::create("MapDevil.tmx");
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
     addQuitGameBtn(20, 280);
     addAllToHUDLayer(); // This must be last called function

    scheduleUpdate();
     return true;
}


void PlayGameScene::update(float fps) {
	//Update animation here
    cocos2d::log("Enter update");
    if (controlChamp) {
        controlChamp->updateVelocity(leftJoystick->getVelocity());
        controlChamp->update(fps);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    	
		if(controlChamp->_HP->isZero){
            heroDied = true;
            controlChamp->_MP->consumingPoint(1000);
            controlChamp->_HP->currentPoint = 1;
		}
    	if(heroDied == true){
            controlChamp->_objectSprite->runAction(controlChamp->rebornAnimate());
            addplayAgainBtn(230,170);
            addLostGameBtn(290, 170);
            heroDied = false;
    	}
    }
	   
    for(int i=0; i < _canAttackObject.size(); i ++){
	    if(_canAttackObject.at(i)){
            if (Monster* enemy = dynamic_cast<Monster*> (_canAttackObject.at(i))) {
            	enemy->update(fps);
                monsterIdle -= 0.1;
            	
                    if (monsterIdle < 0) {
                        enemy->_objectSprite->stopAllActions();
                        enemy->_objectSprite->runAction(enemy->idleAnimate());
                    	if(enemy->_HP->currentPoint > 100)
							enemy->_HP->restorePoint(10);
                        enemy->setState(&MonsterState::idling);
                        monsterIdle = 5;
                    }
            	
            	
                if (enemy->_objectSprite->getBoundingBox().containsPoint(controlChamp->_objectSprite->getPosition()) && enemy->_HP->currentPoint < 900 
                    && controlChamp->_HP->currentPoint > 2 && enemy->_HP->currentPoint > 50) {
					//Enemy attack hero
                    timeAttack -= 0.1;
                	if(timeAttack < 0){
                        enemy->_objectSprite->stopAllActions();
                        enemy->_objectSprite->runAction(enemy->attackAnimate());
                        enemy->_HP->restorePoint(100);
                        enemy->setState(&MonsterState::attacking);
                        controlChamp->_HP->consumingPoint(100);
                        controlChamp->_objectSprite->stopAllActions();
                        controlChamp->_objectSprite->runAction(controlChamp->hurtAnimate());
                        timeAttack = 5;
                	}
                }
               
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
=======
        cocos2d::log("Update completed");

    }
	   
=======
        cocos2d::log("Update completed");

    }
	   
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
        cocos2d::log("Update completed");

    }
	   
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    // for(int i=0; i < _allDynamicObjectAdded.size(); i ++){
	   //  if(_allDynamicObjectAdded.at(i)){
    //         if (Monster* enemy = dynamic_cast<Monster*> (_allDynamicObjectAdded.at(i))) {
    //             enemy->update(fps);
    //         }
    //
    //         if (Champion* enemy = dynamic_cast<Champion*> (_allDynamicObjectAdded.at(i))) {
    //             enemy->update(fps);
    //         }
	   //  }
    // }
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    
  
}

