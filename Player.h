/*
 * Player.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include"MoveableObject.h"
#include"Bomb.h"
class Player:public MoveableObject{
	Bomb bomb;
public:
	Player();
	virtual void draw();
	virtual void move();
	int returnPlayerPositionX(){return this->objectPosition.getObjX();}
	int returnPlayerPositionY(){return this->objectPosition.getObjY();}
	virtual int getObjectPositionX();
	virtual int getObjectPositionY();
	void hit();
	virtual ~Player();
	char getDirection() const;
	void setDirection(char direction);
	void callBomb();
	void stopBomb();
};

#endif /* PLAYER_H_ */
