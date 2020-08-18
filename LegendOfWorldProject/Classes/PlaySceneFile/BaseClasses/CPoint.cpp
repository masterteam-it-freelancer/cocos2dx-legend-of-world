#include "CPoint.h"
#include "cocos2d.h"
CPoint::CPoint() = default;

CPoint::~CPoint() = default;


void CPoint::restorePoint(float point){
	if(currentPoint > 0 && currentPoint < maxPoint){
		if ((currentPoint + point) > maxPoint) {
			currentPoint = maxPoint;
			isMax = true;
			isZero = false;
		}
		
		else currentPoint = currentPoint + point;
	}
	//update  progressing bar animation here
}

void CPoint::consumingPoint(float point) {

	if (currentPoint - point > 0)
		currentPoint = currentPoint - point;
		//update  progressing bar animation here
	else {
		currentPoint = 0;
		isZero = true;
		isMax = false;
		//set progressing bar is blank here
	}
	
}

void CPoint::increaseMaxPoint(float point){
	maxPoint += point;
	//update  progressing bar animation here

}

