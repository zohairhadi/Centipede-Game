/*
 * Centipede.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef CENTIPEDE_H_
#define CENTIPEDE_H_
#include"Segment.h"
#include"LazySeg.h"
#include"MagicSeg.h"
class Centipede {
	int headX,headY;
	vector<Segment*>segments;
public:
	Centipede();
	Centipede(int X,int Y, int size);
	void Draw();
	int getHeadX();
	int getHeadY();
	int getPosX(int index);
	int getPosY(int index);
	bool removeSegment(int i);
	void changePath(int i);
	virtual ~Centipede();
};

#endif /* CENTIPEDE_H_ */
