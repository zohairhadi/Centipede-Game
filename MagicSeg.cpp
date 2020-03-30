/*
 * MagicSeg.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "MagicSeg.h"
int MagicSeg::counter=0;

MagicSeg::MagicSeg():Segment(),randBlink(GetRandInRange(10,100)){
	direction='l';
	this->objectPosition.setObjX(50);
	this->objectPosition.setObjY(39);
}
MagicSeg::MagicSeg(int X, int Y):Segment(),randBlink(GetRandInRange(10,100)){
	direction='l';
	this->objectPosition.setObjX(X);
	this->objectPosition.setObjY(Y);
}

void MagicSeg::draw(){
	counter++;
	if(counter<randBlink){
		DrawLine( objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20-9 , objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20+9 , 4 , colors[WHITE] );
		DrawLine( objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20-9 , objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20-25 , 4 , colors[WHITE] );
		DrawCircle(objectPosition.getObjX()*20+8,objectPosition.getObjY()*20-9,9,colors[LIME]);
	}
	else if(counter<randBlink+200){
		if(counter%20==0){
			DrawLine( objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20-9 , objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20+9 , 4 , colors[WHITE] );
			DrawLine( objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20-9 , objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20-25 , 4 , colors[WHITE] );
			DrawCircle(objectPosition.getObjX()*20+8,objectPosition.getObjY()*20-9,9,colors[LIME]);
		}
	}
	else
		counter=0;
	move();
}

void MagicSeg::move(){
	changeDirection();
	if(direction=='l'){
			this->objectPosition.setObjX(objectPosition.getObjX()-1);
	}
	else if(direction=='r'){
		this->objectPosition.setObjX(objectPosition.getObjX()+1);
	}
}

int MagicSeg::getObjectPositionX(){
	return this->objectPosition.getObjX();
}
int MagicSeg::getObjectPositionY(){
	return this->objectPosition.getObjY();
}

MagicSeg::~MagicSeg() {
	// TODO Auto-generated destructor stub
}

