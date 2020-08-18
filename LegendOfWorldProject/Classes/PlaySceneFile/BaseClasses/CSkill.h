#pragma once
#include "cocos2d.h"
class Skill: public cocos2d::Node {
private:
    cocos2d::Sprite* _skillSprite;
    std::string _skillName;
    std::string _skillDescription;
    int _manaCost;
    int _cooldown;
    float _castRange;
    int _skillLevel;
    int _maxSkillLevel;
public:
    void createSkill();
    void addPointToSkill();
    void useSkill();
};

