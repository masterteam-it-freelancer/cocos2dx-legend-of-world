#pragma once

#include "cocos2d.h"
#include "CMonster.h"
#include "InputEnum.h"


class Monster;
class MNoAction;
class MIdle;
class MWalkLeft;
class MWalkRight;
class MRunLeft;
class MRunRight;
class MAttack;
class MDie;
class MReborn;
class MUseSkill;

class MonsterState {
public:
	static MNoAction notdoingsth;
	static MIdle idling;
	static MWalkLeft goingLeft;
	static MWalkRight goingRight;
	static MRunLeft runningLeft;
	static MRunRight runningRight;
	static MAttack attacking;
	static MDie dying;
	static MReborn reborning;
	static MUseSkill usingSkill;
	bool isIdling = true;
	bool isRunning = false;
	bool isAttacking = false;
	float attackSpeedAnimation = 1;
	float timeToReborn = 10;
	virtual void handleInput(Monster* Monster, Input input) = 0;
	virtual void handleUpdate(Monster* Monster, float dt) = 0;
};

class MNoAction : public MonsterState {
public:

	void handleInput(Monster* Monster, Input input);
	void handleUpdate(Monster* Monster, float dt);
};

class MIdle : public MonsterState {
public:

	void handleInput(Monster* Monster, Input input);
	void handleUpdate(Monster* Monster, float dt);
};

class MWalkLeft : public MonsterState {
public:

	void handleInput(Monster* Monster, Input input);
	void handleUpdate(Monster* Monster, float dt);
};

class MWalkRight : public MonsterState {
public:

	void handleInput(Monster* Monster, Input input);
	void handleUpdate(Monster* Monster, float dt);
};

class MRunLeft : public MonsterState {
public:

	void handleInput(Monster* Monster, Input input);
	void handleUpdate(Monster* Monster, float dt);
};

class MRunRight : public MonsterState {
public:

	void handleInput(Monster* Monster, Input input);
	void handleUpdate(Monster* Monster, float dt);
};
class MAttack : public MonsterState {
public:

	void handleInput(Monster* Monster, Input input);
	void handleUpdate(Monster* Monster, float dt);
};

class MDie : public MonsterState {
public:

	void handleInput(Monster* Monster, Input input);
	void handleUpdate(Monster* Monster, float dt);
};

class MReborn : public MonsterState {
public:

	void handleInput(Monster* Monster, Input input);
	void handleUpdate(Monster* Monster, float dt);
};

class MUseSkill : public MonsterState {
public:

	void handleInput(Monster* Monster, Input input);
	void handleUpdate(Monster* Monster, float dt);
};
