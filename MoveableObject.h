/*
 * MoveableObject.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef MOVEABLEOBJECT_H_
#define MOVEABLEOBJECT_H_
#include"GameObject.h"
class MoveableObject:public GameObject{
protected:
	char direction;
public:
	MoveableObject();
	virtual void move()=0;
	virtual void draw()=0;
	virtual int getObjectPositionX()=0;
	virtual int getObjectPositionY()=0;
	void setDirection(char i);
	char getDirection();
	virtual ~MoveableObject();
};

#endif /* MOVEABLEOBJECT_H_ */
