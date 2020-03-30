/*
 * Bomb.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef BOMB_H_
#define BOMB_H_
#include"MoveableObject.h"
class Bomb:public MoveableObject{
	bool isFire;
public:
	Bomb();
	virtual void move();
	virtual void draw();
	virtual int getObjectPositionX();
	virtual int getObjectPositionY();
//	virtual void hit();
	bool isLaserGood();
	void setPosition(int i,int j);
	int getPositionY();
	int getPositionX();
	virtual ~Bomb();
	bool isIsFire() const;
	void setIsFire(bool isFire);
};

#endif /* BOMB_H_ */
