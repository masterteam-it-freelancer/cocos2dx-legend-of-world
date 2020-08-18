#pragma once
#include "CBaseMap.h"
class Map_Prototype: public Map{
	Map_Prototype();
	~Map_Prototype();
	override void init();
	void loadPhysic();
};
