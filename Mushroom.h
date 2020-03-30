/*
 * Mushroom.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef MUSHROOM_H_
#define MUSHROOM_H_
#include"GameObject.h"
class Mushroom:public GameObject{

public:
	Mushroom();
	Mushroom(int i,int j);
	virtual void draw();
	virtual int getObjectPositionX();
	virtual int getObjectPositionY();
//	virtual void hit();
	int getPositionX();
	int getPositionY();
//	void hit();
//	int getHits();
	void setPosition(int i, int j){
		this->objectPosition.setObjX(i);
		this->objectPosition.setObjY(j);
	}
	virtual ~Mushroom();
};

#endif /* MUSHROOM_H_ */
