/*
 * MagicSeg.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef MAGICSEG_H_
#define MAGICSEG_H_
#include"Segment.h"
class MagicSeg :public Segment{
	int randBlink;
	static int counter;
public:
	MagicSeg();
	MagicSeg(int X, int Y);
	virtual void draw();
	virtual void move();
	virtual int getObjectPositionX();
	virtual int getObjectPositionY();
	virtual ~MagicSeg();
};

#endif /* MAGICSEG_H_ */
