#pragma once

class CPoint {
public:
	CPoint();
	~CPoint();

	float originalPoint;
	float addedPointFromItem;
	float addedPointFromEffect;
	float totalPoint;

	float currentPoint;
	float maxPoint;
	bool isZero = false;
	bool isMax = true;
	
	void restorePoint(float point);
	void consumingPoint(float point);
	void increaseMaxPoint(float point);
	
};