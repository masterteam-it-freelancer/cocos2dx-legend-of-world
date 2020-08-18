#pragma once

#include "cocos2d.h"
#include "CChampion.h"
#include "InputEnum.h"


class Champion;
class NoAction;
class Idle;
class WalkLeft;
class WalkRight;
class RunLeft;
class RunRight;
class Attack;
class Die;
class Reborn;
class UseSkill_01;
class UseSkill_02;
class UseSkill_03;
class UseSkill_04;

class PlayerState
{
public:
	static NoAction notdoingsth;
	static Idle idling;
	static WalkLeft goingLeft;
	static WalkRight goingRight;
	static RunLeft runningLeft;
	static RunRight runningRight;
	static Attack attacking;
	static Die dying;
	static Reborn reborning;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	static UseSkill_01 usingSkill_01;
	static UseSkill_02 usingSkill_02;
	static UseSkill_03 usingSkill_03;
	static UseSkill_04 usingSkill_04;

	float stillIdling = 5;
	float stillWalking = 3;
	float stillRunning = 3;
	float stillAttacking = 1;
	float stillAttacking_1 = 1;
	float stillAttacking_2 = 1;
	float stillAttacking_3 = 1;
	float stillAttacking_4 = 1;

	
	bool isIdling = false;
=======
	static UseSkill usingSkill;
	bool isIdling = true;
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	bool isRunning = false;
	bool isAttacking = false;
<<<<<<< HEAD
	bool isUsingSkill = false;
	
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
	static UseSkill usingSkill;
	bool isIdling = true;
	bool isRunning = false;
	bool isAttacking = false;
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
	static UseSkill usingSkill;
	bool isIdling = true;
	bool isRunning = false;
	bool isAttacking = false;
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	float attackSpeedAnimation = 1;
	float timeToReborn = 10;
	virtual void handleInput(Champion* player, Input input) = 0;
	virtual void handleUpdate(Champion* player, float dt) = 0;
};

class NoAction : public PlayerState {
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class Idle : public PlayerState
{
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class WalkLeft : public PlayerState
{
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class WalkRight : public PlayerState
{
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class RunLeft : public PlayerState {
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class RunRight : public PlayerState {
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};
class Attack : public PlayerState
{
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class Die : public PlayerState
{
<<<<<<< HEAD
<<<<<<< HEAD
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class Reborn : public PlayerState {
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class UseSkill_01 : public PlayerState {
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class UseSkill_02 : public PlayerState {
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class UseSkill_03 : public PlayerState {
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};

class UseSkill_04 : public PlayerState {
public:

	void handleInput(Champion* player, Input input);
	void handleUpdate(Champion* player, float dt);
};
