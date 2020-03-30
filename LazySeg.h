/*
 * LazySeg.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef LAZYSEG_H_
#define LAZYSEG_H_
#include"Segment.h"
class LazySeg :public Segment{
public:
	LazySeg();
	LazySeg(int i, int j);
	virtual void draw();
	virtual void move();
	virtual int getObjectPositionX();
	virtual int getObjectPositionY();

	virtual ~LazySeg();
};

#endif /* LAZYSEG_H_ */
