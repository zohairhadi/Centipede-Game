/*
 * Bomb.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "Bomb.h"

Bomb::Bomb():isFire(false){
	this->objectPosition.setObjX(25);
	this->objectPosition.setObjY(0);
}

void Bomb::move(){
	draw();
	if(isLaserGood()){
		this->objectPosition.setObjY(this->objectPosition.getObjY()+1);
//		this->board.board_array[objectPosition.setObjY][objectPosition.getObjY()]=4;
	}
	else{
		this->isFire=false;
		this->objectPosition.setObjX(25);
		this->objectPosition.setObjY(1);
	}
}

//void Bomb::hit(){}
bool Bomb::isLaserGood(){

	if(objectPosition.getObjY()+1<39){
		return 1;
	}
	return 0;
}

void Bomb::draw(){
	cout<<"BOMB SHOT"<<endl;
	if(isFire==true)
		DrawLine( objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20+5 ,  objectPosition.getObjX()*20+8 , objectPosition.getObjY()*20+25 , 10 , colors[LIGHT_CORAL] );
}

int Bomb::getPositionY(){
	return objectPosition.getObjY();
}
int Bomb::getPositionX(){
	return objectPosition.getObjX();
}
int Bomb::getObjectPositionX(){
	return objectPosition.getObjX();
}
int Bomb::getObjectPositionY(){
	return objectPosition.getObjY();
}

void Bomb::setPosition(int i, int j){
	this->objectPosition.setObjX(i);
	this->objectPosition.setObjY(j);
}

Bomb::~Bomb() {
	// TODO Auto-generated destructor stub
}

bool Bomb::isIsFire() const {
	return isFire;
}

void Bomb::setIsFire(bool isFire) {
	this->isFire = isFire;
}
