/*
 * MoveableObject.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "MoveableObject.h"

MoveableObject::MoveableObject():direction('a'){}

void MoveableObject::setDirection(char c){
	this->direction=c;
}
char MoveableObject::getDirection(){
	return this->direction;
}
MoveableObject::~MoveableObject() {
}

