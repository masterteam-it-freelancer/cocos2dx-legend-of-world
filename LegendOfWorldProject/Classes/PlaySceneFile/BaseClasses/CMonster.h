#pragma once
#include "CDynamicObject.h"
#include "CSkill.h"
#include "CPoint.h"
#include "cocos2d.h"
#include "MonsterStates.h"
#include "InputEnum.h"
#include "MyProgressingBar.h"
#include "Box2D/include/Box2D/Box2D.h"
class Champion;
class MonsterState;

class Monster : public DynamicObject {
	friend class MonsterState;
	friend class Idle;
	friend class WalkLeft;
	friend class WalkRight;
	friend class RunLeft;
	friend class RunRight;
	friend class Attack;
	friend class Die;
	friend class Reborn;
	friend class UseSkill;

public:
	//State
	void setState(MonsterState* state);
	MonsterState* _state;
	MonsterState* getState();
	const char* getStateName();
	void update(float dt);
	void input(Input input);

public:
	Monster();
	~Monster();
	bool isDying;
	float timeReborn;
	int _direction;
	int _currentLevel;
	int _maxLevel;
	float x_positionOrigin;
	float y_positionOrigin;

	int _upgradeSkillPoints;
	bool _isControl;
	DynamicObject* _currentEnemy;
	Monster* _currentMonsterEnemy;

	Skill* _skill_01;
	Skill* _skill_02;
	Skill* _skill_03;
	Skill* _skill_04;
	cocos2d::Sprite* _MonsterIcon;
	
	CPoint* _HP;
	CPoint* _MP;
	CPoint* _armor;
	CPoint* _magicalRes;
	CPoint* _physicDame;
	CPoint* _magicalDame;
	CPoint* _criticalDame;
	CPoint* _attackSpeed;
	CPoint* _attackRange;
	CPoint* _movementSpeed;
	MyProgressingBar* _HPBar;
	
	cocos2d::Animate* _currentAnimate;
	cocos2d::Animation* _idleAnimation;
	cocos2d::Animation* _walkAnimation;
	cocos2d::Animation* _runAnimation;
	cocos2d::Animation* _attackAnimation;
	cocos2d::Animation* _hurtAnimation;
	cocos2d::Animation* _stunAnimation;
	cocos2d::Animation* _dieAnimation;
	cocos2d::Animation* _rebornAnimation;
	cocos2d::Animation* _useSkill_01_Animation;
	cocos2d::Animation* _useSkill_02_Animation;
	cocos2d::Animation* _useSkill_03_Animation;
	cocos2d::Animation* _useSkill_04_Animation;


	void changeAnimation();
	cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation(const char* format, int firstIndex, int count,
		std::string plistFile, std::string imgFile);
	cocos2d::Animate* idleAnimate();
	cocos2d::Animate* walkAnimate();
	cocos2d::Animate* runAnimate();
	cocos2d::Animate* attackAnimate();
	cocos2d::Animate* hurtAnimate();
	cocos2d::Animate* stunAnimate();
	cocos2d::Animate* dieAnimate();
	cocos2d::Animate* rebornAnimate();
	cocos2d::Animate* useSkill_01_Animate();
	cocos2d::Animate* useSkill_02_Animate();
	cocos2d::Animate* useSkill_03_Animate();
	cocos2d::Animate* useSkill_04_Animate();
	
	void createMonster(std::vector<std::string> data);


	std::string imgFile;
	std::string plistFile;
	std::vector<std::string> tokenData{};

	cocos2d::Label* MonsterHP{};
	cocos2d::Label* MonsterMP{};
	float animationDelay = 2;

	void stopMoving();
	void actionButtonPressed(int button);
	
	void attack(Champion* currentChamp);
	void followChamp(Champion* currentChamp);
	void changeDirection(int direction);
	int getTag();

	void updateVelocity(cocos2d::Point velocity);
	void move(cocos2d::Point velocity);



};

