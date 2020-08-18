#pragma once
#include "CObject.h"
#include "CPoint.h"

class DynamicObject: public CObject{
//This class for dynamic object like champion, monster, creeps,...
public:
    DynamicObject();
    ~DynamicObject();

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
	
private:
};
