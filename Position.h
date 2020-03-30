/*
 * Position.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef POSITION_H_
#define POSITION_H_
#include<iostream>
using namespace std;
class Position {
protected:
	int obj_X,obj_Y;
public:
	Position();
	int getObjX() const;
	void setObjX(int objX);
	int getObjY() const;
	void setObjY(int objY);
	void generateRandomPosition();
	virtual ~Position();
};

#endif /* POSITION_H_ */
