/*
 * Mushroom.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "Mushroom.h"

Mushroom::Mushroom():GameObject(){
	srand(time(NULL));
	this->objectPosition.setObjX(GetRandInRange(0,50));
	this->objectPosition.setObjY(GetRandInRange(1,39));
//	this->board.board_array[objectPosition.setObjY][objectPosition.getObjY()]=5;
}
Mushroom::Mushroom(int i, int j):GameObject(){
	this->objectPosition.setObjX(i);
	this->objectPosition.setObjY(j);
}


int Mushroom::getObjectPositionX(){
	return objectPosition.getObjX();
}
int Mushroom::getObjectPositionY(){
	return objectPosition.getObjY();
}
int Mushroom::getPositionX(){
	return this->objectPosition.getObjX();
}
int Mushroom::getPositionY(){
	return this->objectPosition.getObjY();
}

void Mushroom::draw(){
	int i=this->objectPosition.getObjX(), j=this->objectPosition.getObjY();
	DrawTriangle( i*20-1 , j*20-15 , i*20+18 , j*20-15 , i*20+8 , j*20-1 , colors[INDIGO] );
	DrawLine( i*20+8 , j*20-15 , i*20+8 , j*20-20 , 4 , colors[PURPLE] );
}

Mushroom::~Mushroom() {
	// TODO Auto-generated destructor stub
}

