/*
 * Position.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "Position.h"

Position::Position():obj_X(0),obj_Y(0){}

Position::~Position() {
	// TODO Auto-generated destructor stub
}

void Position::generateRandomPosition(){
	this->obj_X=rand()%102;
	this->obj_Y=rand()%84;
}

int Position::getObjX() const {
	return obj_X;
}

void Position::setObjX(int objX) {
	obj_X = objX;
}

int Position::getObjY() const {
	return obj_Y;
}

void Position::setObjY(int objY) {
	obj_Y = objY;
}
