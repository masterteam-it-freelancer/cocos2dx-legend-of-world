#include "CMonster.h"
#include <PlaySceneFile/Monsters/CMonsterManager.h>
#include "Definitons.h"
#include <external\Box2D\include\Box2D\Common\b2Math.h>
#include "PlayGameScene.h"
#include <typeinfo>

USING_NS_CC;

Monster::Monster() = default;

Monster::~Monster() = default;

void Monster::setState(MonsterState * state) {
    _state = state;
    cocos2d::log("Change state completed !");
    cocos2d::log("Current state is: %s", getStateName());
}

MonsterState* Monster::getState() {
    return _state;
}

const char* Monster::getStateName() {
    return typeid(*_state).name();
}


void Monster::input(Input input) {
    _state->handleInput(this, input);
}

void Monster::update(float dt) {
    _state->handleUpdate(this, dt);
	
}

void Monster::createMonster(std::vector<std::string> data) {
    for (int i = 0; i < data.size(); i++) {
        data[i].erase(remove_if(data[i].begin(), data[i].end(), isspace), data[i].end());
        tokenData.push_back(data[i]);
    }
    cocos2d::log("Enter create monster at monster cpp");

    _direction = 1;
    _currentLevel = 1;
    _maxLevel = 100;
    _isControl = false;
    timeReborn = 100;
    isDying = false;
    _objectName = data.at(0); //Line 1 in txt file 
    _objectDescription = data.at(1);


    plistFile = data.at(2);
    imgFile = data.at(3);
    int first = std::stoi(data.at(10)); //Create idle default animation
    int last = std::stoi(data.at(11)); //11 is line of idle default animation
    auto frames = getAnimation(data.at(9).c_str(), first, last, plistFile, imgFile);
    _objectSprite = Sprite::createWithSpriteFrame(frames.front());
    auto animation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    _objectSprite->runAction(RepeatForever::create(Animate::create(animation)));

    int __x_Pos = std::stoi(data.at(4));
    int __y_Pos = std::stoi(data.at(5));
    _objectSprite->setPosition(__x_Pos, __y_Pos);
    _objectSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    x_positionOrigin = __x_Pos;
    y_positionOrigin = __y_Pos;

    _MonsterIcon = Sprite::create(data.at(6));
    _MonsterIcon->setScale(0.3);
    int _x_Pos = std::stoi(data.at(7));
    int _y_Pos = std::stoi(data.at(8));
    _MonsterIcon->setPosition(_x_Pos, _y_Pos);

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
    _MP->currentPoint = stoi(data.at(40));
    _armor->currentPoint = stoi(data.at(41));
    _magicalRes->currentPoint = stoi(data.at(42));
    _physicDame->currentPoint = stoi(data.at(43));
    _magicalDame->currentPoint = stoi(data.at(44));
    _criticalDame->currentPoint = stoi(data.at(45));
    _attackRange->currentPoint = stoi(data.at(46));
    _movementSpeed->currentPoint = stoi(data.at(47));
    _attackSpeed->currentPoint = 20.5;

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
    _HPBar->create("hpBar.png");
    _HPBar->progressTimer->setPosition(Vec2(_objectSprite->getPosition().x, _objectSprite->getPosition().y + 20));
    changeDirection(_direction);
    cocos2d::log("Create completed a Monster from CMonster.cpp");
}


void Monster::updateVelocity(cocos2d::Point velocity) {
    move(velocity);
    _HPBar->progressTimer->setPosition(Vec2(_objectSprite->getPosition().x, _objectSprite->getPosition().y + 20));

}

void Monster::move(cocos2d::Point velocity) {
    float x_Move = velocity.x;
    float y_Move = velocity.y;
    if (x_Move != 0 || y_Move != 0) {
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
        if (this->_state != &MonsterState::attacking) {
            this->input(Input::GET_IDLE);
        }
        this->_objectSprite->setPosition(_objectSprite->getPosition().x, _objectSprite->getPosition().y);

    }
}

void Monster::stopMoving() {

}

void Monster::actionButtonPressed(int button) {
    if (button == 1) {
        _objectB2PhysicBody->ApplyLinearImpulse(b2Vec2(0, _objectB2PhysicBody->GetMass() * 3), _objectB2PhysicBody->GetWorldCenter(), true);
    }
}

void Monster::followChamp(Champion* currentChamp){
	if(currentChamp){
		//Check origin monster location, not current monster location
        float x_Champ_Location = currentChamp->_objectSprite->getPositionX();
        float y_Champ_Location = currentChamp->_objectSprite->getPositionY();
        float inRangeAttack = sqrt((x_Champ_Location - x_positionOrigin) * (x_Champ_Location - x_positionOrigin) + 
									  (y_Champ_Location - y_positionOrigin) * (y_Champ_Location - y_positionOrigin));
        if(inRangeAttack < 50){
	        
        }
		if(inRangeAttack > 50){
			
		}
	}
}


void Monster::attack(Champion* championNeedAttack) {
    cocos2d::log("Attack again a champion");
     if (this->_objectSprite->getBoundingBox().containsPoint(championNeedAttack->_objectSprite->getPosition())){
	        //If have any enemy in attack range, set it is current enemy
                cocos2d::log("Find an enemy in attack range %s", championNeedAttack->_objectName.c_str());
                this->_objectSprite->stopAllActions();
                this->_objectSprite->runAction(this->attackAnimate());
                //Attack current enemy
                if (championNeedAttack) {
                    championNeedAttack->_HP->consumingPoint(this->_physicDame->currentPoint / 2);
                }
     }
     else{
         followChamp(championNeedAttack);
     }
   

}

void Monster::changeDirection(int direction) {
    if (this->_direction != direction && direction == 1) {
        _objectSprite->setFlippedX(true);
        this->_direction = direction;

        if (this->getState() == &MonsterState::idling) {
            stopMoving();
        }
    }
    else if (this->_direction != direction && direction == 2) {
        _objectSprite->setFlippedX(false);
        this->_direction = direction;

        if (this->getState() == &MonsterState::idling) {
            stopMoving();
        }
    }
}

int Monster::getTag() {
    return 0;
}


void Monster::changeAnimation() {
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

cocos2d::Vector<SpriteFrame*> Monster::getAnimation(const char* format, int firstIndex, int count, std::string _plistFile = "TexturesPrototype.plist", std::string _imgFile = "TexturesPrototype.png") {
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

cocos2d::Animate* Monster::idleAnimate() {
    int first = std::stoi(tokenData.at(10));
    int last = std::stoi(tokenData.at(11));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(9).c_str(), first, last);
    _idleAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_idleAnimation);
    return animate;
}

cocos2d::Animate* Monster::walkAnimate() {
    int first = std::stoi(tokenData.at(13));
    int last = std::stoi(tokenData.at(14));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(12).c_str(), first, last);
    _walkAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_walkAnimation);
    return animate;
}

cocos2d::Animate* Monster::runAnimate() {
    int first = std::stoi(tokenData.at(16));
    int last = std::stoi(tokenData.at(17));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(15).c_str(), first, last);
    _runAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_runAnimation);
    return animate;
}

cocos2d::Animate* Monster::attackAnimate() {
    int first = std::stoi(tokenData.at(19));
    int last = std::stoi(tokenData.at(20));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(18).c_str(), first, last);
    _attackAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_attackAnimation);
    return animate;
}

cocos2d::Animate* Monster::useSkill_01_Animate() {
    int first = std::stoi(tokenData.at(22));
    int last = std::stoi(tokenData.at(23));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(21).c_str(), first, last);
    _useSkill_01_Animation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_useSkill_01_Animation);
    return animate;
}

cocos2d::Animate* Monster::useSkill_02_Animate() {
    int first = std::stoi(tokenData.at(26));
    int last = std::stoi(tokenData.at(25));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(24).c_str(), first, last);
    _useSkill_02_Animation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_useSkill_02_Animation);
    return animate;
}

cocos2d::Animate* Monster::useSkill_03_Animate() {
    int first = std::stoi(tokenData.at(29));
    int last = std::stoi(tokenData.at(28));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(27).c_str(), first, last);
    _useSkill_03_Animation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_useSkill_03_Animation);
    return animate;
}

cocos2d::Animate* Monster::useSkill_04_Animate() {
    int first = std::stoi(tokenData.at(31));
    int last = std::stoi(tokenData.at(32));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(30).c_str(), first, last);
    _useSkill_04_Animation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_useSkill_04_Animation);
    return animate;
}


cocos2d::Animate* Monster::hurtAnimate() {
    int first = std::stoi(tokenData.at(34));
    int last = std::stoi(tokenData.at(35));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(33).c_str(), first, last);
    _idleAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_idleAnimation);
    return animate;
}

cocos2d::Animate* Monster::stunAnimate() {
    int first = std::stoi(tokenData.at(34));
    int last = std::stoi(tokenData.at(35));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(33).c_str(), first, last);
    _stunAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_stunAnimation);
    return animate;
}

cocos2d::Animate* Monster::dieAnimate() {
    int first = std::stoi(tokenData.at(37));
    int last = std::stoi(tokenData.at(38));
    Vector<SpriteFrame*> frames = getAnimation(tokenData.at(36).c_str(), first, last);
    _dieAnimation = Animation::createWithSpriteFrames(frames, 1.0f / (last - first));
    auto animate = Animate::create(_dieAnimation);
    return animate;
}

cocos2d::Animate* Monster::rebornAnimate() {
    int first = std::stoi(tokenData.at(21));
    int last = std::stoi(tokenData.at(22));

    SpriteBatchNode* spriteNode = SpriteBatchNode::create(imgFile);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistFile);
    auto spritecache = SpriteFrameCache::getInstance();
    cocos2d::Vector<SpriteFrame*> _rebornFrame;
    char str[100];
    for (int i = last; i >= first; i--) {
        sprintf(str, tokenData.at(20).c_str(), i);
        _rebornFrame.pushBack(spritecache->getSpriteFrameByName(str));
    }
    _rebornAnimation = Animation::createWithSpriteFrames(_rebornFrame, 1.0f / (last - first));
    auto animate = Animate::create(_rebornAnimation);
    return animate;
}

