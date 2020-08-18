#include "CChampion.h"
#include <PlaySceneFile/Champions/CChampionManager.h>
#include "Definitons.h"
#include <external\Box2D\include\Box2D\Common\b2Math.h>
#include "PlayGameScene.h"
#include <typeinfo>


USING_NS_CC;

Champion::Champion() = default;

Champion::~Champion() = default;

void Champion::setState(PlayerState* state){
    _state = state;
    cocos2d::log("Change state completed !");
    cocos2d::log("Current state is: %s", getStateName());
}

PlayerState* Champion::getState() {
    return _state;
}

const char* Champion::getStateName() {
    cocos2d::log("Enter get state name !");
    return typeid(*_state).name();
}


void Champion::input(Input input) {
    _state->handleInput(this, input);
}

void Champion::update(float dt){
    _state->handleUpdate(this, dt);
}

void Champion::createChamp(std::vector<std::string> data){
	  for(int i = 0; i < data.size();i++){
          data[i].erase(remove_if(data[i].begin(), data[i].end(), isspace), data[i].end());
          tokenData.push_back(data[i]);
   	  }
      cocos2d::log("Enter create champion at champ cpp");

      _direction = 1;
	 _currentLevel = 1;
	 _maxLevel = 100;
     _isControl = false;

     _objectName = data.at(0); //Line 1 in txt file 
     _objectDescription = data.at(1);
	
    
     plistFile = data.at(2);
     imgFile = data.at(3);
     int first = std::stoi(data.at(10)); //Create idle default animation
     int last = std::stoi(data.at(11)); //11 is line of idle default animation
     auto frames = getAnimation(data.at(9).c_str(), first, last,plistFile,imgFile);
     _objectSprite = Sprite::createWithSpriteFrame(frames.front());
     auto animation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
     _objectSprite->runAction(RepeatForever::create(Animate::create(animation)));
	
     int __x_Pos = std::stoi(data.at(4));
     int __y_Pos = std::stoi(data.at(5));
     _objectSprite->setPosition(__x_Pos, __y_Pos);
     _objectSprite->setScale(0.2);
     _objectSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
     

     _champIcon = Sprite::create(data.at(6));
     _champIcon->setScale(0.1);
     int _x_Pos = std::stoi(data.at(7));
     int _y_Pos = std::stoi(data.at(8));
     _champIcon->setPosition(_x_Pos, _y_Pos);
  
	 _skill_01 = new Skill;
	 _skill_02 = new Skill;
	 _skill_03 = new Skill;
	 _skill_04 = new Skill;

	  _HP = new CPoint;
	  _MP = new CPoint;
	  _armor = new CPoint;
	  _magicalRes = new CPoint;
	  _physicDame = new CPoint;
	  _magicalDame = new CPoint;
	  _criticalDame = new CPoint;
	  _attackSpeed = new CPoint;
	  _attackRange = new CPoint;
	  _movementSpeed = new CPoint;
	 
     _HP->currentPoint = stoi(data.at(39));
     _MP->currentPoint =stoi(data.at(40));
     _armor->currentPoint = stoi(data.at(41));
     _magicalRes->currentPoint = stoi(data.at(42));
     _physicDame->currentPoint = stoi(data.at(43));
     _magicalDame->currentPoint = stoi(data.at(44));
     _criticalDame->currentPoint = stoi(data.at(45));
     _attackRange->currentPoint = stoi(data.at(46));  
     _movementSpeed->currentPoint =  stoi(data.at(47));
     _attackSpeed->currentPoint = 20.5;

     _HP->maxPoint = stoi(data.at(39));
     _MP->maxPoint = stoi(data.at(40));
     _armor->maxPoint = stoi(data.at(41));
     _magicalRes->maxPoint = stoi(data.at(42));
     _physicDame->maxPoint = stoi(data.at(43));
     _magicalDame->maxPoint = stoi(data.at(44));
     _criticalDame->maxPoint = stoi(data.at(45));
     _attackRange->maxPoint = stoi(data.at(46));
     _movementSpeed->maxPoint = stoi(data.at(47));
     _attackSpeed->maxPoint = 20.5;
	
     _HP->totalPoint = stoi(data.at(39));
     _MP->totalPoint = stoi(data.at(40));
     _armor->totalPoint = stoi(data.at(41));
     _magicalRes->totalPoint = stoi(data.at(42));
     _physicDame->totalPoint = stoi(data.at(43));
     _magicalDame->totalPoint = stoi(data.at(44));
     _criticalDame->totalPoint = stoi(data.at(45));
     _attackRange->totalPoint = stoi(data.at(46));
     _movementSpeed->totalPoint = stoi(data.at(47));
     _attackSpeed->totalPoint = 20.5;

     _HPBar = new MyProgressingBar;
     _MPBar = new MyProgressingBar;
     _HPBar->create("hpBar.png");
     _MPBar->create("mpBar.png");
	
     _HPBar->progressTimer->setPosition(Vec2(_objectSprite->getPosition().x, _objectSprite->getPosition().y + 27));
     _MPBar->progressTimer->setPosition(Vec2(_objectSprite->getPosition().x, _objectSprite->getPosition().y + 20));
   	 changeDirection(_direction);   
}



void Champion::updateVelocity(cocos2d::Point velocity){
    move(velocity);
    _MPBar->progressTimer->setPercentage(this->_MP->currentPoint * 0.1);
    _HPBar->progressTimer->setPercentage(this->_HP->currentPoint * 0.1);
    _champIcon->setPosition(Vec2(_objectSprite->getPosition().x - 15, _objectSprite->getPosition().y + 22.5));
    _HPBar->progressTimer->setPosition(Vec2(_objectSprite->getPosition().x + 8, _objectSprite->getPosition().y + 27));
    _MPBar->progressTimer->setPosition(Vec2(_objectSprite->getPosition().x + 8, _objectSprite->getPosition().y + 20));

}

void Champion::move(cocos2d::Point velocity){
    float x_Move = velocity.x;
    float y_Move = velocity.y;
    if(x_Move != 0 || y_Move != 0){
        if (x_Move > 0 && (abs(x_Move) > 0.5 || abs(y_Move) > 0.5)) {
            //Move right with direction = 2
            this->changeDirection(2);
            this->input(Input::RUN_RIGHT_PRESS);
        }
        else if (x_Move < 0 && (abs(x_Move) > 0.5 || abs(y_Move) > 0.5)) {
            //Move left with direction = 1
            this->changeDirection(1);
            this->input(Input::RUN_LEFT_PRESS);
        }

        else if (x_Move > 0 && (abs(x_Move) < 0.5 && abs(y_Move) < 0.5)) {
            //Move right with direction = 2
            this->changeDirection(2);
            this->input(Input::RUN_RIGHT_PRESS);

        }
        else if (x_Move < 0 && (abs(x_Move) < 0.5 && abs(y_Move) < 0.5)) {
            //Move left with direction = 1
            this->changeDirection(1);
            this->input(Input::RUN_LEFT_PRESS);
        }
        this->_objectSprite->setPosition(_objectSprite->getPosition().x + x_Move, _objectSprite->getPosition().y + y_Move);
    }
    else {
        // not moving
    	if(this->_state != &PlayerState::attacking){
            this->input(Input::GET_IDLE);
		}
        this->_objectSprite->setPosition(_objectSprite->getPosition().x, _objectSprite->getPosition().y);

       }
}

void Champion::stopMoving(){
 
}

void Champion::actionButtonPressed(int button){
    if (button == 1) {
        _objectB2PhysicBody->ApplyLinearImpulse(b2Vec2(0, _objectB2PhysicBody->GetMass() * 3), _objectB2PhysicBody->GetWorldCenter(), true);
    }
}

void Champion::attack(std::vector<DynamicObject*> *enemyList){
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    this->_objectSprite->stopAllActions();
    this->_objectSprite->runAction(this->attackAnimate());
=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    cocos2d::log("Attack an object");
    cocos2d::log("Number of added object in play game scene: %d", enemyList->size());
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character

    _currentEnemy = nullptr;
	for(int i = 0; i < enemyList->size(); i++){
		//Check if have any enemy in attack range
        if (this->_objectSprite->getBoundingBox().containsPoint(enemyList->at(i)->_objectSprite->getPosition())){
	        //If have any enemy in attack range, set it is current enemy
				_currentEnemy = enemyList->at(i);
        }
	}
    cocos2d::log("No have any enemy in attack range");

    if (_currentEnemy != nullptr) {
        cocos2d::log("Current enemy is %s", _currentEnemy->_objectName.c_str());
    	//Change direction
        if (_currentEnemy->_objectSprite->getPositionX() > this->_objectSprite->getPositionX()) {
            //If enemy at the left of my character
            //Check direction
            if (this->_direction == 1)
                this->changeDirection(2);			       
        }
        if (_currentEnemy->_objectSprite->getPositionX() < this->_objectSprite->getPositionX()) {
            //If enemy at the left of my character
            //Check direction
        	if (this->_direction == 2)
                this->changeDirection(1);

        }

    	//Calculate HP and MP
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        if (auto *enemy = dynamic_cast<Monster*> (_currentEnemy)) {
            cocos2d::log("Attack a monster");        	
        			if(enemy != nullptr){             
	                    if (this->_direction == 2)
	                        enemy->changeDirection(1);
	                    else
	                        enemy->changeDirection(2);
	                }
        		if(enemy->_HP->currentPoint != 1){
                    enemy->_HP->consumingPoint(this->_physicDame->currentPoint - enemy->_armor->currentPoint);
                    enemy->_HPBar->progressTimer->setPercentage(enemy->_HP->currentPoint * 0.1);
                    enemy->_objectSprite->stopAllActions();
                    enemy->_objectSprite->runAction(enemy->hurtAnimate());
                    enemy->setState(&MonsterState::hurting);

        		}
                  
                
               
                if(enemy->hurtAnimate()->isDone()){
                	//call attack enemy here
                    cocos2d::log("Being hungry, attack champion - gruuuu");
                }
        	
                if (enemy->_HP->isZero) {
                    enemy->_objectSprite->stopAllActions();
                    enemy->_objectSprite->runAction(enemy->dieAnimate());
                    enemy->setState(&MonsterState::dying);
                    enemy->isDying = true;
                	
                }
        }
        	
            

        
      
        cocos2d::log("Attack a monster a hit --------------------------");

=======
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
        _currentEnemy->_HP->consumingPoint(this->_physicDame->currentPoint / 2);
        cocos2d::log("Consuming HP completed");

        if (_currentEnemy->_HP->isZero) {
           
        	if(Champion* enemy = dynamic_cast<Champion*> (_currentEnemy)){
                enemy->setState(&PlayerState::dying);
                cocos2d::log("Find a champion");
                //Do something when died here
        	}

            if (Monster* enemy = dynamic_cast<Monster*> (_currentEnemy)) {
                enemy->setState(&MonsterState::dying);
                cocos2d::log("Find a monster");
                //Do something when died here

            }
        }
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
=======
>>>>>>> parent of 5470f7c... [Quynh] Update animation code for character
    }
    if(_currentEnemy == nullptr){
        this->_objectSprite->runAction(this->attackAnimate());
        cocos2d::log("No have any enemy in attack range at else condition");
    }
    cocos2d::log("Quit attack function");

}

void Champion::usingSkill_01(std::vector<DynamicObject*>* enemyList){
	if(this->_MP->currentPoint > 100){
        this->_objectSprite->stopAllActions();
        this->_objectSprite->runAction(this->useSkill_01_Animate());
        this->_MP->consumingPoint(100);
        this->_HP->consumingPoint(0);


        _currentEnemy = nullptr;
        for (int i = 0; i < enemyList->size(); i++) {
            //Check if have any enemy in attack range
            if (this->_objectSprite->getBoundingBox().containsPoint(enemyList->at(i)->_objectSprite->getPosition())) {
                //If have any enemy in attack range, set it is current enemy
                _currentEnemy = enemyList->at(i);
            }
        }

        if (_currentEnemy != nullptr) {
            cocos2d::log("Current enemy is %s", _currentEnemy->_objectName.c_str());
            //Change direction
            if (_currentEnemy->_objectSprite->getPositionX() > this->_objectSprite->getPositionX()) {
                //If enemy at the left of my character
                //Check direction
                if (this->_direction == 1)
                    this->changeDirection(2);
            }
            if (_currentEnemy->_objectSprite->getPositionX() < this->_objectSprite->getPositionX()) {
                //If enemy at the left of my character
                //Check direction
                if (this->_direction == 2)
                    this->changeDirection(1);

            }

            //Calculate HP and MP
            if (auto* enemy = dynamic_cast<Monster*> (_currentEnemy)) {
                cocos2d::log("Attack a monster");
                if (enemy != nullptr) {
                    if (this->_direction == 2)
                        enemy->changeDirection(1);
                    else
                        enemy->changeDirection(2);
                }
                if (enemy->_HP->currentPoint != 1) {
                    enemy->_HP->consumingPoint(this->_physicDame->currentPoint * 1.5);
                    enemy->_HPBar->progressTimer->setPercentage(enemy->_HP->currentPoint * 0.1);
                    enemy->_objectSprite->stopAllActions();
                    enemy->_objectSprite->runAction(enemy->hurtAnimate());
                    enemy->setState(&MonsterState::hurting);

                }



                if (enemy->hurtAnimate()->isDone()) {
                    //call attack enemy here
                    cocos2d::log("Being hungry, attack champion - gruuuu");
                }

                if (enemy->_HP->isZero) {
                    enemy->_objectSprite->stopAllActions();
                    enemy->_objectSprite->runAction(enemy->dieAnimate());
                    enemy->setState(&MonsterState::dying);
                    enemy->isDying = true;

                }
            }
        }
        if (_currentEnemy == nullptr) {
            this->_objectSprite->runAction(this->useSkill_01_Animate());
            cocos2d::log("No have any enemy in attack range at else condition");
        }
	}
    else{
        this->_objectSprite->runAction(this->walkAnimate());

    }
}

void Champion::usingSkill_02(std::vector<DynamicObject*>* enemyList){
    //Healing skill
    this->_objectSprite->stopAllActions();
    this->_objectSprite->runAction(this->useSkill_02_Animate());	
    this->_MP->restorePoint(200);
    this->_HP->restorePoint(100);
   
}

void Champion::usingSkill_03(std::vector<DynamicObject*>* enemyList){
	if(this->_HP->currentPoint > 300){
        this->_objectSprite->stopAllActions();
        this->_objectSprite->runAction(this->useSkill_03_Animate());
        this->_MP->consumingPoint(0);
        this->_HP->consumingPoint(300);


        _currentEnemy = nullptr;
        for (int i = 0; i < enemyList->size(); i++) {
            if (this->_objectSprite->getBoundingBox().containsPoint(enemyList->at(i)->_objectSprite->getPosition())) {
                _currentEnemy = enemyList->at(i);
            }
        }

        if (_currentEnemy != nullptr) {
            cocos2d::log("Current enemy is %s", _currentEnemy->_objectName.c_str());
            if (_currentEnemy->_objectSprite->getPositionX() > this->_objectSprite->getPositionX()) {

                if (this->_direction == 1)
                    this->changeDirection(2);
            }
            if (_currentEnemy->_objectSprite->getPositionX() < this->_objectSprite->getPositionX()) {

                if (this->_direction == 2)
                    this->changeDirection(1);

            }

            //Calculate HP and MP
            if (auto* enemy = dynamic_cast<Monster*> (_currentEnemy)) {
                cocos2d::log("Attack a monster");
                if (enemy != nullptr) {
                    if (this->_direction == 2)
                        enemy->changeDirection(1);
                    else
                        enemy->changeDirection(2);
                }
                if (enemy->_HP->currentPoint != 1) {
                    enemy->_HP->consumingPoint(500);
                    enemy->_HPBar->progressTimer->setPercentage(enemy->_HP->currentPoint * 0.1);
                    enemy->_objectSprite->stopAllActions();
                    enemy->_objectSprite->runAction(enemy->hurtAnimate());
                    enemy->setState(&MonsterState::hurting);
                }



                if (enemy->hurtAnimate()->isDone()) {
                    //call attack enemy here
                    cocos2d::log("Being hungry, attack champion - gruuuu");
                }

                if (enemy->_HP->isZero) {
                    enemy->_objectSprite->stopAllActions();
                    enemy->_objectSprite->runAction(enemy->dieAnimate());
                    enemy->setState(&MonsterState::dying);
                    enemy->isDying = true;

                }
            }





            cocos2d::log("Attack a monster a hit --------------------------");

        }
        if (_currentEnemy == nullptr) {
            this->_objectSprite->runAction(this->useSkill_03_Animate());
        }
	}
    else{
        this->_objectSprite->runAction(this->walkAnimate());

    }
}

void Champion::usingSkill_04(std::vector<DynamicObject*>* enemyList){
	if(this->_MP->currentPoint > 200){
        this->_objectSprite->stopAllActions();
        this->_objectSprite->runAction(this->useSkill_04_Animate());
        this->_MP->consumingPoint(200);

        _currentEnemy = nullptr;
        for (int i = 0; i < enemyList->size(); i++) {
            if (this->_objectSprite->getBoundingBox().containsPoint(enemyList->at(i)->_objectSprite->getPosition())) {
                _currentEnemy = enemyList->at(i);
            }
        }

        if (_currentEnemy != nullptr) {
            cocos2d::log("Current enemy is %s", _currentEnemy->_objectName.c_str());
            if (_currentEnemy->_objectSprite->getPositionX() > this->_objectSprite->getPositionX()) {
                if (this->_direction == 1)
                    this->changeDirection(2);
            }
            if (_currentEnemy->_objectSprite->getPositionX() < this->_objectSprite->getPositionX()) {
                if (this->_direction == 2)
                    this->changeDirection(1);

            }

            //Calculate HP and MP
            if (auto* enemy = dynamic_cast<Monster*> (_currentEnemy)) {
                cocos2d::log("Attack a monster");
                if (enemy != nullptr) {
                    if (this->_direction == 2)
                        enemy->changeDirection(1);
                    else
                        enemy->changeDirection(2);
                }
                if (enemy->_HP->currentPoint != 1) {
                    this->_HP->restorePoint(100);
                    enemy->_HP->consumingPoint(200);
                    enemy->_HPBar->progressTimer->setPercentage(enemy->_HP->currentPoint * 0.1);
                    enemy->_objectSprite->stopAllActions();
                    enemy->_objectSprite->runAction(enemy->hurtAnimate());
                    enemy->setState(&MonsterState::hurting);

                }

                if (enemy->hurtAnimate()->isDone()) {
                    //call attack enemy here
                    cocos2d::log("Being hungry, attack champion - gruuuu");
                }

                if (enemy->_HP->isZero) {
                    enemy->_objectSprite->stopAllActions();
                    enemy->_objectSprite->runAction(enemy->dieAnimate());
                    enemy->setState(&MonsterState::dying);
                    enemy->isDying = true;

                }
            }





            cocos2d::log("Attack a monster a hit --------------------------");

        }
        if (_currentEnemy == nullptr) {
            this->_objectSprite->runAction(this->useSkill_04_Animate());
        }
	}
    else{
        this->_objectSprite->runAction(this->walkAnimate());
    }
}

void Champion::changeDirection(int direction){
    if (this->_direction != direction && direction == 1) {
        _objectSprite->setFlippedX(true);
        this->_direction = direction;

        if (this->getState() == &PlayerState::idling) {
            stopMoving();
        }
    }
    else if (this->_direction != direction && direction == 2) {
        _objectSprite->setFlippedX(false);
        this->_direction = direction;

        if (this->getState() == &PlayerState::idling) {
            stopMoving();
        }
    }
}

int Champion::getTag() {
    return 0;
}


void Champion::changeAnimation(){  
   _objectSprite->stopAllActions();
    // switch () {
    // case Input::NO_ACTION_PRESS:
    // 	//No action - no animation
    //     break;
    // case Input::GET_IDLE:
    //     _currentAnimate = idleAnimate();
    //     _objectSprite->runAction(RepeatForever::create(_currentAnimate));
    //     break;
    // case Input::WALK_LEFT_PRESS:
    //     _currentAnimate = walkAnimate();
    //     _objectSprite->runAction(RepeatForever::create(_currentAnimate));
    //     break;
    // case Input::WALK_RIGHT_PRESS:
    //     _currentAnimate = walkAnimate();
    //     _objectSprite->runAction(RepeatForever::create(_currentAnimate));
    //     break;
    // case Input::RUN_LEFT_PRESS:
    //     _currentAnimate = runAnimate();
    //     _objectSprite->runAction(RepeatForever::create(_currentAnimate));
    //     break;
    // case Input::RUN_RIGHT_PRESS:
    //     _currentAnimate = runAnimate();
    //     _objectSprite->runAction(RepeatForever::create(_currentAnimate));
    //     break;
    // case Input::ATTACK_PRESS:
    //     _currentAnimate = attackAnimate();
    //     _objectSprite->runAction(_currentAnimate);
    //     break;
    // case Input::GET_HURT:
    //     _currentAnimate = hurtAnimate();
    //     _objectSprite->runAction(_currentAnimate);
    //     break;
    // case Input::GET_STUN:
    //     _currentAnimate = stunAnimate();
    //     _objectSprite->runAction(_currentAnimate);
    //     break;
    // case Input::GET_DIE:
    //     _currentAnimate = dieAnimate();
    //     _objectSprite->runAction(_currentAnimate);
    //     break;
    // case Input::GET_REBORN:
    //     _currentAnimate = rebornAnimate();
    //     _objectSprite->runAction(_currentAnimate);
    //     break;
    // case Input::USE_SKILL_PRESS:
    //     _currentAnimate = useSkill_Animate();
    //     _objectSprite->runAction(_currentAnimate);
    //     break;
    // default:
    //     cocos2d::log("Enter default animation case");
    //     break;
    //
    // }
    _currentAnimate = idleAnimate();
    _objectSprite->runAction(RepeatForever::create(_currentAnimate));
   
}

cocos2d::Vector<SpriteFrame*> Champion::getAnimation(const char* format, int firstIndex, int count, std::string _plistFile = "TexturesPrototype.plist", std::string _imgFile = "TexturesPrototype.png") {
    SpriteBatchNode* spriteNode = SpriteBatchNode::create(imgFile);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistFile);
    auto spritecache = SpriteFrameCache::getInstance();
    cocos2d::Vector<SpriteFrame*> animFrames;
    char str[100];
    for (int i = firstIndex; i <= count; i++) {
        sprintf(str, format, i);
        animFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    return animFrames;

}

cocos2d::Animate* Champion::idleAnimate() {
    int first = std::stoi(tokenData.at(10));
    int last = std::stoi(tokenData.at(11));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(9).c_str(), first, last);
    _idleAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_idleAnimation);
    return animate;
}

cocos2d::Animate* Champion::walkAnimate() {
    int first = std::stoi(tokenData.at(13));
    int last = std::stoi(tokenData.at(14));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(12).c_str(), first, last);
    _walkAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_walkAnimation);
    return animate;
}

cocos2d::Animate* Champion::runAnimate() {
   int first = std::stoi(tokenData.at(16));
    int last = std::stoi(tokenData.at(17));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(15).c_str(), first, last);
    _runAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_runAnimation);
    return animate;
}

cocos2d::Animate* Champion::attackAnimate() {
	int first = std::stoi(tokenData.at(19));
    int last = std::stoi(tokenData.at(20));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(18).c_str(), first, last);
    _attackAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_attackAnimation);
    return animate;
}

cocos2d::Animate* Champion::useSkill_01_Animate() {
    int first = std::stoi(tokenData.at(22));
    int last = std::stoi(tokenData.at(23));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(21).c_str(), first, last);
    _useSkill_01_Animation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_useSkill_01_Animation);
    return animate;
}

cocos2d::Animate* Champion::useSkill_02_Animate() {
    int first = std::stoi(tokenData.at(25));
    int last = std::stoi(tokenData.at(26));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(24).c_str(), first, last);
    _useSkill_02_Animation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_useSkill_02_Animation);
    return animate;
}

cocos2d::Animate* Champion::useSkill_03_Animate() {
    int first = std::stoi(tokenData.at(28));
    int last = std::stoi(tokenData.at(29));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(27).c_str(), first, last);
    _useSkill_03_Animation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_useSkill_03_Animation);
    return animate;
}

cocos2d::Animate* Champion::useSkill_04_Animate() {
    int first = std::stoi(tokenData.at(31));
    int last = std::stoi(tokenData.at(32));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(30).c_str(), first, last);
    _useSkill_04_Animation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_useSkill_04_Animation);
    return animate;
}


cocos2d::Animate* Champion::hurtAnimate() {
    int first = std::stoi(tokenData.at(34));
    int last = std::stoi(tokenData.at(35));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(33).c_str(), first, last);
    _idleAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_idleAnimation);
    return animate;
}

cocos2d::Animate* Champion::stunAnimate() {
    int first = std::stoi(tokenData.at(34));
    int last = std::stoi(tokenData.at(35));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(33).c_str(), first, last);
    _stunAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_stunAnimation);
    return animate;
}

cocos2d::Animate* Champion::dieAnimate() {
    int first = std::stoi(tokenData.at(37));
    int last = std::stoi(tokenData.at(38));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(36).c_str(), first, last);
    _dieAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_dieAnimation);
    return animate;
}

cocos2d::Animate* Champion::rebornAnimate() {
    int first = std::stoi(tokenData.at(37));
    int last = std::stoi(tokenData.at(38));

    SpriteBatchNode* spriteNode = SpriteBatchNode::create(imgFile);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistFile);
    auto spritecache = SpriteFrameCache::getInstance();
    cocos2d::Vector<SpriteFrame*> _rebornFrame;
    char str[100];
    for (int i = last; i >= first; i--) {
        sprintf(str, tokenData.at(36).c_str(), i);
        _rebornFrame.pushBack(spritecache->getSpriteFrameByName(str));
    }	
    _rebornAnimation = Animation::createWithSpriteFrames(_rebornFrame, 1.0f / (last - first));
    auto animate = Animate::create(_rebornAnimation);
    return animate;
}

