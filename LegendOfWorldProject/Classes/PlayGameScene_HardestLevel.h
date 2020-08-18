#pragma once
#include "PlayGameScene.h"

#include "CScene.h"


USING_NS_CC;
using namespace cocos2d::ui;

class PlayGameScene_HardestLevel : public CScene {
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(PlayGameScene_HardestLevel);

public:

    virtual void update(float fps);
    Champion* controlChamp;
    DynamicObject* currentEnemy;
    std::vector<DynamicObject* > currentEnemyList;

    Sprite* potion;
    Sprite* key;
    Champion_Golem_1* e_golem_01;

    Monster* tiny_golem_01;
    Monster* tiny_golem_02;
    Monster* tiny_golem_03;
    Monster* tiny_golem_04;
    Monster* tiny_golem_05;
    Monster* tiny_golem_06;
    Monster* tiny_golem_07;
    Monster* tiny_golem_08;
    Monster* tiny_golem_09;

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

    std::vector<Sprite*> _allSpriteAdded;
    std::vector<DynamicObject* > _canAttackObject;
    std::vector<DynamicObject*> _allDynamicObjectAdded;
    std::vector<Monster* > _allJungleMonsters;
    std::vector<Monster*> _enemyCreeps;
    std::vector<Monster*> _myCreeps;

    std::vector<DynamicObject*> getAllDynamicObj();
    void addAllHeroToScene();
    void addAllMonsterToScene();
    void heroAttackAnEnemy(Champion* hero, DynamicObject* enemy);
    int attack = 3;

    //Game logic
    float timeAddACreep = 3;
    float timeSpawnCreep = 30;
    float timeSpawnMonster = 30;
    void spawnCreepsPerMinutes(float dt);
    void spawnMonsterAfterDied(float dt);


    void setHUDLayer(Layer* layer);
    //    void setTiledMap(TileMa);

    ContactListener* contactListener;
    b2World* world;

    static PlayGameScene_HardestLevel* createWithHUDAndTiledMap(Layer* hudLayer);
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
