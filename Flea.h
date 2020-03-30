/*
 * Flea.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef FLEA_H_
#define FLEA_H_
#include"MoveableObject.h"
class Flea:public MoveableObject{
	int *trail;
	int size;
	bool fleaCrossed;
	int randTime;
	static int count;
public:
	Flea();
	virtual void move();
	virtual void draw();
	virtual int getObjectPositionX();
	virtual int getObjectPositionY();
	int* getTrail();
	int getSize();
	bool isFleaCrossed(){return fleaCrossed;}
	void setFleaCrossed(bool i){fleaCrossed=i;}
//	bool shouldLeaveTrail();
	virtual ~Flea();
};

#endif /* FLEA_H_ */
