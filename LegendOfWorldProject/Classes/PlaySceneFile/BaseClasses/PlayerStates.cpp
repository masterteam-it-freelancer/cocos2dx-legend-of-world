#include "PlayerStates.h"

#include "PlayGameScene.h"

USING_NS_CC;

NoAction PlayerState::notdoingsth;
Idle PlayerState::idling;
WalkLeft PlayerState::goingLeft;
WalkRight PlayerState::goingRight;
RunLeft PlayerState::runningLeft;
RunRight PlayerState::runningRight;
Attack PlayerState::attacking;
Die PlayerState::dying;
Reborn PlayerState::reborning;
UseSkill_01 PlayerState::usingSkill_01;
UseSkill_02 PlayerState::usingSkill_02;
UseSkill_03 PlayerState::usingSkill_03;
UseSkill_04 PlayerState::usingSkill_04;

/// <summary>
/// Must read first
/// </summary>
/// Handle input:
/// If state Idle in action, get another input will change to ... 
/// <param name="input"></param>

void NoAction::handleInput(Champion* player, Input input) {
	switch (input) {
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;
		
	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;
		
	case RUN_RIGHT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningRight);
		break;
	case RUN_RIGHT_RELEASE:
		break;

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
		
	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
		
	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
		
	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
		
	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
		
	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from no action");
		break;
	}

}

void NoAction::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter update no action");
}


void Idle::handleInput(Champion* player, Input input) {
	switch (input) {
<<<<<<< HEAD
	case GET_IDLE:
		// isIdling = true;
		// player->setState(&PlayerState::idling);
		break;	
	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
=======
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when idle");
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		cocos2d::log("Release attack when idle");
		break;
	case RUN_LEFT_PRESS:
		isRunning = true;
		cocos2d::log("Run left pressed from idle");
		player->setState(&PlayerState::runningLeft);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when idle");
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case WALK_LEFT_RELEASE:
		break;
	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	case RUN_LEFT_RELEASE:
		break;
	case RUN_RIGHT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningRight);
		break;
	case RUN_RIGHT_RELEASE:
		break;
<<<<<<< HEAD
		
	case ATTACK_PRESS:
		player->setState(&PlayerState::attacking);
=======
	case WALK_LEFT_PRESS:
		isRunning = true;
		cocos2d::log("Walk left pressed from idle");
		player->setState(&PlayerState::goingLeft);
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
<<<<<<< HEAD
	case USE_SKILL_01_PRESS:
		player->setState(&PlayerState::usingSkill_01);
=======
	case WALK_RIGHT_PRESS:
		isRunning = true;
		cocos2d::log("Walk right pressed from idle");
		player->setState(&PlayerState::goingRight);
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
	case USE_SKILL_02_PRESS:
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
	case USE_SKILL_03_PRESS:
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
	case USE_SKILL_04_PRESS:
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	

	
	default:
		cocos2d::log("Enter default case from idling");
		break;
	}

}

void Idle::handleUpdate(Champion* player, float dt) {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	if (isIdling == true) {
		player->_objectSprite->stopAllActions();
		player->_objectSprite->runAction(player->idleAnimate());
		isIdling = false;
	}
	stillIdling -= 0.1;
	if(stillIdling < 0 ){
		cocos2d::log("Enter update idle");
		player->_objectSprite->stopAllActions();
		player->_objectSprite->runAction(player->idleAnimate());
		stillIdling = 7;
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	// if(isIdling == true){
	// 	cocos2d::log("Enter update idle");
	// 	player->_objectSprite->runAction(RepeatForever::create(player->idleAnimate()));
	// 	isIdling = false;
	// }
	if (isIdling == false) {
		cocos2d::log("Enter update idle false case");
		player->_objectSprite->runAction(RepeatForever::create(player->idleAnimate()));
		isIdling = true;
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	}
}

void WalkLeft::handleInput(Champion* player, Input input) {
	switch (input) {
<<<<<<< HEAD
=======
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when walking");
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when walking");
		player->setState(&PlayerState::notdoingsth);
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from walking");
		// player->setState(&PlayerState::runningLeft);
		break;
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		// isWalking = true;
		// player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
		isRunning = true;
		player->setState(&PlayerState::runningRight);
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		// player->setState(&PlayerState::runningRight);
		cocos2d::log("Run right pressed from walking");
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case RUN_RIGHT_RELEASE:
		break;
<<<<<<< HEAD

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
=======
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from walking");
		// player->setState(&PlayerState::goingLeft);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
<<<<<<< HEAD

	case USE_SKILL_01_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
=======
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from walking");
		// player->setState(&PlayerState::goingRight);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_02_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_03_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_04_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from walk left");
		break;
	}
}

void WalkLeft::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter update walk left");
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	if (isWalking == true) {
		player->_objectSprite->stopAllActions();
		player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));
		isWalking = false;
=======
	if (isRunning == true) {
		player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));
		isRunning = false;
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
	if (isRunning == true) {
		player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));
		isRunning = false;
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
	if (isRunning == true) {
		player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));
		isRunning = false;
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	}
}

void WalkRight::handleInput(Champion* player, Input input) {
	switch (input) {
	case GET_IDLE:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
		cocos2d::log("Idle pressed from attacking");
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
		cocos2d::log("Idle pressed from attacking");
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
		cocos2d::log("Idle pressed from attacking");
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		// isWalking = true;
		// player->setState(&PlayerState::goingRight);
		 break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
		isRunning = true;
		player->setState(&PlayerState::runningRight);
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		// player->setState(&PlayerState::runningRight);
		cocos2d::log("Run right pressed from walking 2");
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case RUN_RIGHT_RELEASE:
		break;
<<<<<<< HEAD

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
=======
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from walking 2");
		// player->setState(&PlayerState::goingLeft);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
<<<<<<< HEAD

	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
=======
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from walking 2");
		player->setState(&PlayerState::goingRight);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
<<<<<<< HEAD

	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
=======
	case USE_SKILL_PRESS:
		cocos2d::log("Use skill pressed from walking 2");
		// player->setState(&PlayerState::usingSkill);
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

<<<<<<< HEAD
	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from walk right");
		break;
	}
}

void WalkRight::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter update walk right");
<<<<<<< HEAD
<<<<<<< HEAD
	if (isWalking == true) {
		player->_objectSprite->stopAllActions();
		player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));
		isWalking = false;
	}
	
=======
	player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));

>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
	player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));

>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
void WalkRight::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter update walk right");
	player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));

>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
}

void RunLeft::handleInput(Champion* player, Input input) {
	switch (input) {
<<<<<<< HEAD
=======
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when running");
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when running");
		player->setState(&PlayerState::notdoingsth);
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from running");
		// player->setState(&PlayerState::runningLeft);
		break;
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		// isRunning = true;
		// player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
		isRunning = true;
		player->setState(&PlayerState::runningRight);
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		 player->setState(&PlayerState::runningRight);
		cocos2d::log("Run right pressed from running");
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case RUN_RIGHT_RELEASE:
		break;
<<<<<<< HEAD

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
=======
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from running");
		player->setState(&PlayerState::goingLeft);
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
<<<<<<< HEAD

	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
=======
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from running");
		player->setState(&PlayerState::goingRight);
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
<<<<<<< HEAD
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
=======
	case USE_SKILL_PRESS:
		cocos2d::log("Use skill pressed from running");
		player->setState(&PlayerState::usingSkill);
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from run left");
		break;
	}
}

void RunLeft::handleUpdate(Champion* player, float dt) {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	cocos2d::log("Still running left");
	if (isRunning == true) {
		player->_objectSprite->stopAllActions();
		player->_objectSprite->runAction(RepeatForever::create(player->runAnimate()));
		isRunning = false;
	}
	
=======
	cocos2d::log("Enter update run left");
	player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
	cocos2d::log("Enter update run left");
	player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
	cocos2d::log("Enter update run left");
	player->_objectSprite->runAction(RepeatForever::create(player->walkAnimate()));
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character

}

void RunRight::handleInput(Champion* player, Input input) {
	switch (input) {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when running 2");
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when running 2");
		player->setState(&PlayerState::notdoingsth);
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from running 2");
		// player->setState(&PlayerState::runningLeft);
		break;
	case GET_IDLE:
		cocos2d::log("Idle pressed from run right");
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when running 2");
		break;
	case GET_DIE:
		cocos2d::log("Get die when running 2");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when running 2");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when running 2");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from running 2");
		break;
	case RUN_RIGHT_PRESS:
		 player->setState(&PlayerState::runningRight);
		cocos2d::log("Run right pressed from running 2");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from running 2");
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
		// isRunning = true;
		// player->setState(&PlayerState::runningRight);
		break;
	case RUN_RIGHT_RELEASE:
		break;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	default:
		cocos2d::log("Enter default case from run right");
		break;
	}
}

void RunRight::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter update run right");
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	if (isRunning == true) {
		player->_objectSprite->stopAllActions();
		player->_objectSprite->runAction(RepeatForever::create(player->runAnimate()));
		isRunning = false;
	}
	
=======
	player->_objectSprite->runAction(RepeatForever::create(player->runAnimate()));
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
	player->_objectSprite->runAction(RepeatForever::create(player->runAnimate()));
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
	player->_objectSprite->runAction(RepeatForever::create(player->runAnimate()));
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
}

void Attack::handleInput(Champion* player, Input input) {
	switch (input) {
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningRight);
		break;
	case RUN_RIGHT_RELEASE:
		break;

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

<<<<<<< HEAD
	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
=======
void Attack::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter attack");
	player->_objectSprite->runAction(player->attackAnimate());
	attackSpeedAnimation -= 0.08;
	if (attackSpeedAnimation < 0) {
		attackSpeedAnimation = 1;
<<<<<<< HEAD
		cocos2d::log("Attack speed is: %f", attackSpeedAnimation);
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from attack");
		break;
	}

}

void Attack::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter attack");
<<<<<<< HEAD
	stillAttacking -= 0.05;
	if (stillAttacking < 0) {
		stillAttacking = 1;
=======
	player->_objectSprite->runAction(player->attackAnimate());
	attackSpeedAnimation -= 0.08;
	if (attackSpeedAnimation < 0) {
		attackSpeedAnimation = 1;
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		cocos2d::log("Attack speed is: %f", attackSpeedAnimation);
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		isIdling = true;
		player->setState(&PlayerState::idling);
	}
}


void UseSkill_01::handleInput(Champion* player, Input input) {
	switch (input) {
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningRight);
		break;
	case RUN_RIGHT_RELEASE:
		break;

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from attack");
		break;
	}
}

void UseSkill_01::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter sk1");
	stillAttacking_1 -= 0.05;
	if (stillAttacking_1 < 0) {
		stillAttacking_1 = 1;
		isIdling = true;
		player->setState(&PlayerState::idling);
	}
}

void UseSkill_02::handleInput(Champion* player, Input input) {
	switch (input) {
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningRight);
		break;
	case RUN_RIGHT_RELEASE:
		break;

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from attack");
		break;
	}
}

void UseSkill_02::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter use skill 2");
	stillAttacking_2 -= 0.05;
	if (stillAttacking_2 < 0) {
		stillAttacking_2 = 1;
		isIdling = true;
		player->setState(&PlayerState::idling);
	}
}

void UseSkill_03::handleInput(Champion* player, Input input) {
	switch (input) {
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningRight);
		break;
	case RUN_RIGHT_RELEASE:
		break;

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from attack");
		break;
	}
}

void UseSkill_03::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter use skill 3");
	stillAttacking_3 -= 0.05;
	if (stillAttacking_3 < 0) {
		stillAttacking_3 = 1;
		cocos2d::log("Attack speed is: %f", attackSpeedAnimation);
		isIdling = true;
		player->setState(&PlayerState::idling);
	}
}

void UseSkill_04::handleInput(Champion* player, Input input) {
	switch (input) {
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningRight);
		break;
	case RUN_RIGHT_RELEASE:
		break;

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from attack");
		break;
	}
}

void UseSkill_04::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter use skill 4");
	stillAttacking_4 -= 0.05;
	if (stillAttacking_4 < 0) {
		stillAttacking_4 = 1;
		cocos2d::log("Attack speed is: %f", attackSpeedAnimation);
		isIdling = true;
		player->setState(&PlayerState::idling);
	}
}

void Die::handleInput(Champion* player, Input input) {
	switch (input) {
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningRight);
		break;
	case RUN_RIGHT_RELEASE:
		break;

	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from die");
		break;
	}
}

void Die::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter update die");
	player->_objectSprite->runAction(player->dieAnimate());
	timeToReborn -= 0.08;
	if (timeToReborn < 0) {
		timeToReborn = 10;
		cocos2d::log("Waiting for reborn: %f", timeToReborn);
		isIdling = true;
		player->setState(&PlayerState::idling);
	}
}

void Reborn::handleInput(Champion* player, Input input) {
	switch (input) {
	case GET_IDLE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case WALK_LEFT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		break;

	case WALK_RIGHT_PRESS:
		isWalking = true;
		player->setState(&PlayerState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		break;

	case RUN_LEFT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningLeft);
		break;
	case RUN_LEFT_RELEASE:
		break;

	case RUN_RIGHT_PRESS:
		isRunning = true;
		player->setState(&PlayerState::runningRight);
		break;
	case RUN_RIGHT_RELEASE:
		break;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	case ATTACK_PRESS:
		isAttacking = true;
		player->setState(&PlayerState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_01_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_01);
		break;
	case USE_SKILL_01_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_02_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_02);
		break;
	case USE_SKILL_02_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_03_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_03);
		break;
	case USE_SKILL_03_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case USE_SKILL_04_PRESS:
		isUsingSkill = true;
		player->setState(&PlayerState::usingSkill_04);
		break;
	case USE_SKILL_04_RELEASE:
		isIdling = true;
		player->setState(&PlayerState::idling);
		break;

	case GET_HURT:
		break;
	case GET_STUN:
		break;
	case GET_DIE:
		break;
	case GET_REBORN:
		break;
	default:
		cocos2d::log("Enter default case from reborn");
		break;
	}
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
void UseSkill::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter update use skill");
	cocos2d::log("Current object is %s", player->_objectName.c_str());
	player->_objectSprite->runAction(player->attackAnimate());
	cocos2d::log("Run action completed");

	// attackSpeedAnimation -= 0.08;
	// if(attackSpeedAnimation < 0){
	// 	attackSpeedAnimation = 1;
	// 	cocos2d::log("Attack speed is: %f", attackSpeedAnimation);
	// 	isIdling = true;
	// 	player->setState(&PlayerState::idling);
	// }
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
}

void Reborn::handleUpdate(Champion* player, float dt) {
	cocos2d::log("Enter update reborn");
	player->_objectSprite->runAction(player->rebornAnimate());
	player->setState(&PlayerState::idling);
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
}

