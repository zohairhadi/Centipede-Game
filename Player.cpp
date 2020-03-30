/*
 * Player.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "Player.h"

Player::Player(){
	this->objectPosition.setObjX(25);
	this->objectPosition.setObjY(0);
	this->direction='a';
}

void Player::move(){
	if(direction=='l'){
		if(objectPosition.getObjX()-1>=0)
			this->objectPosition.setObjX(objectPosition.getObjX()-1);
		else
			direction='a';
	}
	else if(direction=='r'){
		if(objectPosition.getObjX()+1<51)
			this->objectPosition.setObjX(objectPosition.getObjX()+1);
		else
			direction='a';
	}
	else if(direction=='u'){
		if(objectPosition.getObjY()+1<5)
			this->objectPosition.setObjY(objectPosition.getObjY()+1);
		else
			direction='a';
	}
	else if(direction=='d'){
		if(objectPosition.getObjY()-1>=0)
			this->objectPosition.setObjY(objectPosition.getObjY()-1);
		else
			direction='a';
	}
	else{}
	direction='a';
	if(bomb.isIsFire()){
		this->bomb.move();
	}
}

char Player::getDirection() const {
	return direction;
}

//void Player::hit(){}

int Player::getObjectPositionX(){
	return bomb.getObjectPositionX();
}
int Player::getObjectPositionY(){
	return bomb.getObjectPositionY();
}

void Player::callBomb(){
	if(!bomb.isIsFire())
		this->bomb.setPosition(objectPosition.getObjX(),objectPosition.getObjY());
	this->bomb.setIsFire(true);
}

void Player::stopBomb(){
	this->bomb.setIsFire(false);
//	bomb.setPosition(25,1);
}

void Player::setDirection(char direction) {
	this->direction = direction;
}

void Player::draw(){
	move();
	DrawSquare(objectPosition.getObjX()*20+2,objectPosition.getObjY()*20+5,15,colors[PINK]);
	DrawLine( objectPosition.getObjX()*20+4 , objectPosition.getObjY()*20+5 , objectPosition.getObjX()*20+4 , objectPosition.getObjY()*20-1 , 4 , colors[KHAKI] );
	DrawLine( objectPosition.getObjX()*20+14 , objectPosition.getObjY()*20+5 , objectPosition.getObjX()*20+14 , objectPosition.getObjY()*20-1 , 4 , colors[KHAKI] );
}


Player::~Player() {
	// TODO Auto-generated destructor stub
}
