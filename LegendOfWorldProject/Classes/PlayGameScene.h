#pragma once
#include <Box2D/include/Box2D/Common/b2Math.h>
#include "cocos2d.h"
#include "PlaySceneFile/BaseClasses/CChampion.h"
#include "PlaySceneFile/BaseClasses/CMonster.h"
#include "Definitons.h"
#include "ui/UIButton.h"
#include <PlaySceneFile\UI\JoyStick\SneakyInput\SneakyButton.h>
#include <PlaySceneFile\UI\JoyStick\SneakyInput\SneakyButtonSkinnedBase.h>
#include <PlaySceneFile\UI\JoyStick\SneakyInput\SneakyJoystick.h>
#include <PlaySceneFile\UI\JoyStick\SneakyInput\SneakyJoystickSkinnedBase.h>
#include <PlaySceneFile\UI\JoyStick\Extras\ContactListener.h>
#include <PlaySceneFile\Champions\CChampion_Golem_1.h>

#include "CScene.h"


USING_NS_CC;
using namespace cocos2d::ui;

class PlayGameScene : public CScene {
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(PlayGameScene);

public:
   
    virtual void update(float fps);
    Champion* controlChamp;
    DynamicObject* currentEnemy;
    std::vector<DynamicObject* > currentEnemyList;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

    Sprite* potion;
    Sprite* key;
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    Champion_Knight_1* knight_01;
    Champion_ElfArcher_1* archer_01;
    Champion_ElfFairy_1* fairy_01;

    Champion_Knight_2* e_knight_02;
    Champion_Knight_3* e_knight_03;
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    Champion_Golem_1* e_golem_01;
	
    Monster* tiny_golem_01;
    Monster* tiny_golem_02;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    Monster* tiny_golem_03;
    Monster* tiny_golem_04;
    Monster* tiny_golem_05;
    Monster* tiny_golem_06;
    Monster* tiny_golem_07;
    Monster* tiny_golem_08;
    Monster* tiny_golem_09;
    
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character

    Monster* bigBoss;
    Monster* knight_boss;
    Monster* knight_creeps_01;
    Monster* knight_creeps_02;
    Monster* monk_boss;
    Monster* monk_creeps_01;
    Monster* monk_creeps_02;

    Monster* human_melee_creep_01;
    Monster* human_melee_creep_02;
    Monster* human_melee_creep_03;
    Monster* orc_melee_creep_01;
    Monster* orc_melee_creep_02;
    Monster* orc_melee_creep_03;

    Monster* human_range_creep_01;
    Monster* human_range_creep_02;
    Monster* orc_range_creep_01;
    Monster* orc_range_creep_02;

	
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    //Button
    Button* attackBtn;
    Button* skill_01Btn;
    Button* skill_02Btn;
    Button* skill_03Btn;
    Button* skill_04Btn;
    Button* quitGameBtn;
    Button* lostGame;
    Button* playAgain;
    Button* winGame;
    void rebornGame();
    void addAttackBtn(int x_Pos, int y_Pos);
    void addSkill01Btn(int xPos, int yPos);
    void addSkill02Btn(int xPos, int yPos);
    void addSkill03Btn(int xPos, int yPos);
    void addSkill04Btn(int xPos, int yPos);
    void addQuitGameBtn(int xPos, int yPos);
    void addLostGameBtn(int xPos, int yPos);
    void addplayAgainBtn(int xPos, int yPos);
    void addWinGameBtn(int xPos, int yPos);

    void backtoMainMenu();

	
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    bool onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    /*Temp code here*/
    int gameState = 0;

    cocos2d::Label* _debugLabel;

    std::vector<Sprite*> _allSpriteAdded;
    std::vector<DynamicObject* > _canAttackObject;
    std::vector<DynamicObject*> _allDynamicObjectAdded;
    std::vector<Monster* > _allJungleMonsters;
    std::vector<Monster*> _enemyCreeps;
    std::vector<Monster*> _myCreeps;
	
    std::vector<DynamicObject*> getAllDynamicObj();
    void addAllHeroToScene();
    void addAllMonsterToScene();
    void heroAttackAnEnemy(Champion *hero, DynamicObject *enemy);
    int attack = 3;

	//Game logic
    float timeAddACreep = 3;
    float timeSpawnCreep = 30;
    float timeSpawnMonster = 30;
    void spawnCreepsPerMinutes(float dt);
    void spawnMonsterAfterDied(float dt);

    bool heroDied = false;
    int monsterIdle = 5;
    float timeAttack = 5;
    float timeSpawnAnyAnimation = 10;
    float timeSpawnAnyAnimation_02 = 3;
    float timeSpawnAnyAnimation_03 = 10;

    void setHUDLayer(Layer* layer);
//    void setTiledMap(TileMa);

    ContactListener* contactListener;
    b2World* world;

    static PlayGameScene* createWithHUDAndTiledMap(Layer* hudLayer);
    SneakyJoystick* leftJoystick;
    cocos2d::Layer* hudLayer;
    cocos2d::Size worldSize;

    void updatePhysics(float dt);
    void createPhysics();

	//Some func to optimize code size
    void addJoystick();
    void addAllToHUDLayer();

    int numberPotion = 2;
    int numberKey = 0;
    void randomDropItem(float x_Pos, float y_Pos);
};
