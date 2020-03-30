/*
 * Segment.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_
#include"MoveableObject.h"
class Segment :public MoveableObject{
protected:
	bool inPlayerArea;
public:
	char verticalDirection;
	Segment();
	virtual void draw()=0;
	virtual void move()=0;
	virtual int getObjectPositionX()=0;
	virtual int getObjectPositionY()=0;
	virtual void changeDirection();
	void changeVerticle(){
		if(verticalDirection=='d'){
			this->objectPosition.setObjY(objectPosition.getObjY()-1);
		}
		else{
			this->objectPosition.setObjY(objectPosition.getObjY()+1);
		}
	}
	void setVDrirection(char c){verticalDirection=c;}
	virtual ~Segment();
};

#endif /* SEGMENT_H_ */
