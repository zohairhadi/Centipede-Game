/*
 * LazySeg.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "LazySeg.h"

LazySeg::LazySeg():Segment(){
	direction='l';
	this->objectPosition.setObjX(50);
	this->objectPosition.setObjY(39);
}
LazySeg::LazySeg(int i, int j):Segment(){
	direction='l';
	this->setVDrirection('d');
	this->objectPosition.setObjX(i);
	this->objectPosition.setObjY(j);
}

void LazySeg::draw(){
	DrawLine( objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20-9 , objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20+9 , 4 , colors[WHITE] );
	DrawLine( objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20-9 , objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20-25 , 4 , colors[WHITE] );
	DrawCircle(objectPosition.getObjX()*20+8,objectPosition.getObjY()*20-9,9,colors[LIME]);
	move();
}

void LazySeg::move(){
	changeDirection();
	if(direction=='l'){
			this->objectPosition.setObjX(objectPosition.getObjX()-1);
	}
	else if(direction=='r'){
		this->objectPosition.setObjX(objectPosition.getObjX()+1);
	}
}

int LazySeg::getObjectPositionX(){
	return this->objectPosition.getObjX();
}
int LazySeg::getObjectPositionY(){
	return this->objectPosition.getObjY();
}


LazySeg::~LazySeg() {
	// TODO Auto-generated destructor stub
}

