#include "MonsterStates.h"

#include "PlayGameScene.h"

USING_NS_CC;

MNoAction MonsterState::notdoingsth;
MIdle MonsterState::idling;
MWalkLeft MonsterState::goingLeft;
MWalkRight MonsterState::goingRight;
MRunLeft MonsterState::runningLeft;
MRunRight MonsterState::runningRight;
MAttack MonsterState::attacking;
MDie MonsterState::dying;
MReborn MonsterState::reborning;
MUseSkill MonsterState::usingSkill;

/// <summary>
/// Must read first
/// </summary>
/// Handle input:
/// If state Idle in action, get another input will change to ... 
/// <param name="input"></param>

void MNoAction::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when no action");
		Monster->setState(&MonsterState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when no action");
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from no action");
		Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when no action");
		break;
	case GET_DIE:
		cocos2d::log("Get die when no action");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when no action");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when no action");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from no action");
		break;
	case RUN_RIGHT_PRESS:
		Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from no action");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from no action");
		break;
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from no action");
		Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from no action");
		break;
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from no action");
		Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from no action");
		break;
	
	default:
		cocos2d::log("Enter default case from no action");
		break;
	}
}

void MNoAction::handleUpdate(Monster* Monster, float dt) {
	cocos2d::log("Enter update no action");
}


void MIdle::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when idle");
		isAttacking = true;
		Monster->setState(&MonsterState::attacking);
		break;
	case ATTACK_RELEASE:
		isIdling = true;
		Monster->setState(&MonsterState::idling);
		cocos2d::log("Release attack when idle");
		break;
	case RUN_LEFT_PRESS:
		isRunning = true;
		cocos2d::log("Run left pressed from idle");
		Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when idle");
		break;
	case GET_DIE:
		cocos2d::log("Get die when idle");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when idle");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when idle");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from idle");
		break;
	case RUN_RIGHT_PRESS:
		isRunning = true;
		Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from idle");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from idle");
		break;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when idle");
		isAttacking = true;
		Monster->setState(&MonsterState::attacking);
		break;
	case ATTACK_RELEASE:
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
	case WALK_LEFT_PRESS:
		isRunning = true;
		cocos2d::log("Walk left pressed from idle");
		Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from idle");
		break;
	case WALK_RIGHT_PRESS:
		isRunning = true;
		cocos2d::log("Walk right pressed from idle");
		Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from idle");
		break;
	case USE_SKILL_PRESS:
		isAttacking = true;
		cocos2d::log("Use skill pressed from idle");
		Monster->setState(&MonsterState::usingSkill);
		break;
	case USE_SKILL_RELEASE:
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
		isIdling = true;
		Monster->setState(&MonsterState::idling);
		cocos2d::log("Use skill release from idle");
		break;
	default:
		cocos2d::log("Enter default case from idle");
		break;
	}
}

void MIdle::handleUpdate(Monster* Monster, float dt) {
	 if(isIdling == true){
	 	cocos2d::log("Enter update idle");
	 	Monster->_objectSprite->runAction(RepeatForever::create(Monster->idleAnimate()));
	 	isIdling = false;
	 }
	if (isIdling == false) {
		cocos2d::log("Enter update idle false case");
		Monster->_objectSprite->runAction(RepeatForever::create(Monster->idleAnimate()));
		isIdling = true;
	}
}

void MWalkLeft::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when walking");
		isAttacking = true;
		Monster->setState(&MonsterState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when walking");
		Monster->setState(&MonsterState::notdoingsth);
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from walking");
		// Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_IDLE:
		cocos2d::log("Idle pressed from attacking");
		isIdling = true;
		Monster->setState(&MonsterState::idling);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when walking");
		break;
	case GET_DIE:
		cocos2d::log("Get die when walking");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when walking");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when walking");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from walking");
		break;
	case RUN_RIGHT_PRESS:
		// Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from walking");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from walking");
		break;
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from walking");
		// Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from walking");
		break;
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from walking");
		// Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from walking");
		break;
	
	default:
		cocos2d::log("Enter default case from walking");
		break;
	}
}

void MWalkLeft::handleUpdate(Monster* Monster, float dt) {
	cocos2d::log("Enter update walk left");
	if (isRunning == true) {
		Monster->_objectSprite->runAction(RepeatForever::create(Monster->walkAnimate()));
		isRunning = false;
	}
}

void MWalkRight::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when walking 2");
		isAttacking = true;
		Monster->setState(&MonsterState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when walking 2");
		Monster->setState(&MonsterState::notdoingsth);
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from walking 2");
		// Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_IDLE:
		cocos2d::log("Idle pressed from attacking");
		isIdling = true;
		Monster->setState(&MonsterState::idling);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when walking 2");
		break;
	case GET_DIE:
		cocos2d::log("Get die when walking 2");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when walking 2");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when walking 2");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from walking 2");
		break;
	case RUN_RIGHT_PRESS:
		// Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from walking 2");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from walking 2");
		break;
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from walking 2");
		// Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from walking 2");
		break;
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from walking 2");
		Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from walking 2");
		break;
	
	default:
		cocos2d::log("Enter default case from walking 2");
		break;
	}
}

void MWalkRight::handleUpdate(Monster* Monster, float dt) {
	cocos2d::log("Enter update walk right");
	Monster->_objectSprite->runAction(RepeatForever::create(Monster->walkAnimate()));

}

void MRunLeft::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when running");
		isAttacking = true;
		Monster->setState(&MonsterState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when running");
		Monster->setState(&MonsterState::notdoingsth);
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from running");
		// Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_IDLE:
		cocos2d::log("Idle pressed from run left");
		isIdling = true;
		Monster->setState(&MonsterState::idling);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when running");
		break;
	case GET_DIE:
		cocos2d::log("Get die when running");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when running");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when running");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from running");
		break;
	case RUN_RIGHT_PRESS:
		Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from running");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from running");
		break;
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from running");
		Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from running");
		break;
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from running");
		Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from running");
		break;
	
	default:
		cocos2d::log("Enter default case from running");
		break;
	}
}

void MRunLeft::handleUpdate(Monster* Monster, float dt) {
	cocos2d::log("Enter update run left");
	Monster->_objectSprite->runAction(RepeatForever::create(Monster->walkAnimate()));

}

void MRunRight::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when running 2");
		isAttacking = true;
		Monster->setState(&MonsterState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when running 2");
		Monster->setState(&MonsterState::notdoingsth);
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from running 2");
		// Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_IDLE:
		cocos2d::log("Idle pressed from run right");
		isIdling = true;
		Monster->setState(&MonsterState::idling);
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
		Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from running 2");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from running 2");
		break;
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from running 2");
		Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from running 2");
		break;
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from running 2");
		Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from running 2");
		break;
	
	default:
		cocos2d::log("Enter default case from running 2");
		break;
	}
}

void MRunRight::handleUpdate(Monster* Monster, float dt) {
	cocos2d::log("Enter update run right");
	Monster->_objectSprite->runAction(RepeatForever::create(Monster->runAnimate()));
}

void MAttack::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		Monster->setState(&MonsterState::attacking);
		cocos2d::log("Pressed attack when attacking");
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when attacking");
		isIdling = true;
		Monster->setState(&MonsterState::idling);
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from attacking");
		isRunning = true;
		Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_IDLE:
		cocos2d::log("Idle pressed from attacking");
		// isIdling = true;
		// Monster->setState(&MonsterState::idling);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when attacking");
		break;
	case GET_DIE:
		cocos2d::log("Get die when attacking");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when attacking");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when attacking");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from attacking");
		break;
	case RUN_RIGHT_PRESS:
		isRunning = true;
		Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from attacking");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from attacking");
		break;
	case WALK_LEFT_PRESS:
		isRunning = true;
		cocos2d::log("Walk left pressed from attacking");
		Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from attacking");
		break;
	case WALK_RIGHT_PRESS:
		isRunning = true;
		cocos2d::log("Walk right pressed from attacking");
		Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from attacking");
		break;

	default:
		cocos2d::log("Enter default case from attacking");
		break;
	}

}

void MAttack::handleUpdate(Monster* Monster, float dt) {
	cocos2d::log("Enter attack");
	Monster->_objectSprite->runAction(Monster->attackAnimate());
	attackSpeedAnimation -= 0.08;
	if (attackSpeedAnimation < 0) {
		attackSpeedAnimation = 1;
		cocos2d::log("Attack speed is: %f", attackSpeedAnimation);
		isIdling = true;
		Monster->setState(&MonsterState::idling);
	}
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
void MHurt::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		isAttacking = true;
		Monster->setState(&MonsterState::attacking);
		cocos2d::log("Pressed attack when attacking");
		break;
	case ATTACK_RELEASE:
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from attacking");
		isRunning = true;
		Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_IDLE:
		cocos2d::log("Idle pressed from attacking");
		 isIdling = true;
		 Monster->setState(&MonsterState::idling);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when attacking");
		break;
	case GET_DIE:
		cocos2d::log("Get die when attacking");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when attacking");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when attacking");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from attacking");
		break;
	case RUN_RIGHT_PRESS:
		isRunning = true;
		Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from attacking");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from attacking");
		break;
	case WALK_LEFT_PRESS:
		isRunning = true;
		cocos2d::log("Walk left pressed from attacking");
		Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from attacking");
		break;
	case WALK_RIGHT_PRESS:
		isRunning = true;
		cocos2d::log("Walk right pressed from attacking");
		Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from attacking");
		break;
	
	default:
		cocos2d::log("Enter default case from attacking");
		break;
	}

}

void MHurt::handleUpdate(Monster* Monster, float dt) {
	cocos2d::log("Being attack - hurting");
	Monster->_objectSprite->runAction(Monster->hurtAnimate());
	attackSpeedAnimation -= 0.08;
	if (attackSpeedAnimation < 0) {
		attackSpeedAnimation = 1;
		cocos2d::log("Hurting speed: %f", attackSpeedAnimation);
		isIdling = true;
		Monster->setState(&MonsterState::idling);
	}
}

=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
void MDie::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when dying");
		Monster->setState(&MonsterState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when dying");
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from dying");
		Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when dying");
		break;
	case GET_DIE:
		cocos2d::log("Get die when dying");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when dying");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when dying");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from dying");
		break;
	case RUN_RIGHT_PRESS:
		Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from dying");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from dying");
		break;
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from dying");
		Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from dying");
		break;
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from dying");
		Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from dying");
		break;
	
	default:
		cocos2d::log("Enter default case from dying");
		break;
	}
}

void MDie::handleUpdate(Monster* Monster, float dt) {
	cocos2d::log("Enter update die");
	Monster->_objectSprite->runAction(Monster->dieAnimate());
	timeToReborn -= 0.08;
	if (timeToReborn < 0) {
		timeToReborn = 10;
		cocos2d::log("Time dying is: %f", timeToReborn);
		isIdling = true;
		Monster->setState(&MonsterState::idling);
	}
}

void MReborn::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when reborning");
		Monster->setState(&MonsterState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when reborning");
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from reborning");
		Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when reborning");
		break;
	case GET_DIE:
		cocos2d::log("Get die when reborning");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when reborning");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when reborning");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from reborning");
		break;
	case RUN_RIGHT_PRESS:
		Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from reborning");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from reborning");
		break;
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from reborning");
		Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from reborning");
		break;
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from reborning");
		Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from reborning");
		break;
	
	default:
		cocos2d::log("Enter default case from reborning");
		break;
	}
}

void MReborn::handleUpdate(Monster* Monster, float dt) {
	cocos2d::log("Enter update reborn");
	Monster->_objectSprite->runAction(Monster->rebornAnimate());
	Monster->setState(&MonsterState::idling);
}


void MUseSkill::handleInput(Monster* Monster, Input input) {
	switch (input) {
	case ATTACK_PRESS:
		cocos2d::log("Pressed attack when using skill");
		Monster->setState(&MonsterState::attacking);
		break;
	case ATTACK_RELEASE:
		cocos2d::log("Release attack when using skill");
		break;
	case RUN_LEFT_PRESS:
		cocos2d::log("Run left pressed from using skill");
		Monster->setState(&MonsterState::runningLeft);
		break;
	case GET_HURT:
		cocos2d::log("Get hurt when using skill");
		break;
	case GET_DIE:
		cocos2d::log("Get die when using skill");
		break;
	case GET_STUN:
		cocos2d::log("Get stun when using skill");
		break;
	case GET_REBORN:
		cocos2d::log("Get reborn when using skill");
		break;
	case RUN_LEFT_RELEASE:
		cocos2d::log("Run left release from using skill");
		break;
	case RUN_RIGHT_PRESS:
		Monster->setState(&MonsterState::runningRight);
		cocos2d::log("Run right pressed from using skill");
		break;
	case RUN_RIGHT_RELEASE:
		cocos2d::log("Run right release from using skill");
		break;
	case WALK_LEFT_PRESS:
		cocos2d::log("Walk left pressed from using skill");
		Monster->setState(&MonsterState::goingLeft);
		break;
	case WALK_LEFT_RELEASE:
		cocos2d::log("Walk left release from using skill");
		break;
	case WALK_RIGHT_PRESS:
		cocos2d::log("Walk right pressed from using skill");
		Monster->setState(&MonsterState::goingRight);
		break;
	case WALK_RIGHT_RELEASE:
		cocos2d::log("Walk right release from using skill");
		break;
	
	default:
		cocos2d::log("Enter default case from using skill");
		break;
	}
}

void MUseSkill::handleUpdate(Monster* Monster, float dt) {
	cocos2d::log("Enter update use skill");
	Monster->_objectSprite->runAction(Monster->useSkill_01_Animate());

	attackSpeedAnimation -= 0.08;
	if (attackSpeedAnimation < 0) {
		attackSpeedAnimation = 1;
		cocos2d::log("Attack speed is: %f", attackSpeedAnimation);
		isIdling = true;

		Monster->setState(&MonsterState::idling);
	}
}

