#pragma once
#include "cocos2d.h"

class MyProgressingBar{
public:
	MyProgressingBar();
	~MyProgressingBar();

	int life; //or Mana...
	cocos2d::ProgressTimer *progressTimer;

public:
	void create(std::string fileSource);
};