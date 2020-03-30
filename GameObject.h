/*
 * GameObject.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
#include<cmath>
#include"Position.h"
//#include"ScoreBoard.h"
//#include"Mushroom.h"
#include"util.h"
using namespace std;
class GameObject{
protected:
	Position objectPosition;
	int hitMushroom;
public:
	GameObject();
	virtual void draw()=0;
	virtual int getObjectPositionX()=0;
	virtual int getObjectPositionY()=0;
	int getHits(){return hitMushroom;}
	void mushroomHit(){hitMushroom--;}
//	virtual void hit()=0;
	virtual ~GameObject();
};

#endif /* GAMEOBJECT_H_ */
