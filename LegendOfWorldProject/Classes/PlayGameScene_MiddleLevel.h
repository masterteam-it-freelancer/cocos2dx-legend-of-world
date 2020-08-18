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
#include "CScene.h"


USING_NS_CC;
using namespace cocos2d::ui;

class PlayGameScene_MiddleLevel : public CScene {
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(PlayGameScene_MiddleLevel);

public:

    virtual void update(float fps);
    Champion* controlChamp;
    DynamicObject* currentEnemy;
    std::vector<DynamicObject* > currentEnemyList;

    Sprite* potion;
    Sprite* key;
    Champion_Golem_1* playerGolem;

    Monster* monster_01;
    Monster* monster_02;
    Monster* monster_03;
    Monster* monster_04;
    Monster* monster_05;
    Monster* monster_06;
    Monster* monster_07;
    Monster* monster_08;
    Monster* monster_09;

    //Button
    Button* attackBtn;
    Button* skill_01Btn;
    Button* skill_02Btn;
    Button* skill_03Btn;
    Button* skill_04Btn;

    void addAttackBtn(int x_Pos, int y_Pos);
    void addSkill01Btn(int xPos, int yPos);
    void addSkill02Btn(int xPos, int yPos);
    void addSkill03Btn(int xPos, int yPos);
    void addSkill04Btn(int xPos, int yPos);

    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    bool onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    /*Temp code here*/
    int gameState = 0;

    cocos2d::Label* _debugLabel;

    std::vector<DynamicObject* > _canAttackObject_02;
    std::vector<DynamicObject*> _allDynamicObjectAdded;

    std::vector<DynamicObject*> getAllDynamicObj();
    void addAllHeroToScene();
    void addAllMonsterToScene();
    void heroAttackAnEnemy(Champion* hero, DynamicObject* enemy);
    int attack = 3;

   
   

    void setHUDLayer(Layer* layer);
    //    void setTiledMap(TileMa);

    ContactListener* contactListener;
    b2World* world;

    static PlayGameScene_MiddleLevel* createWithHUDAndTiledMap(Layer* hudLayer);
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
