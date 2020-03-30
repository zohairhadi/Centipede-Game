/*
 * Segment.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "Segment.h"

Segment::Segment():MoveableObject(),verticalDirection('d'),inPlayerArea(false){
}

void Segment::changeDirection(){
	if(objectPosition.getObjX()==0 || objectPosition.getObjX()==50){
		if(objectPosition.getObjX()==0){
			this->direction='r';
		}
		else if(objectPosition.getObjX()==50){
			this->direction='l';
		}
		this->changeVerticle();
	}
	if(this->objectPosition.getObjY()<=5)
		inPlayerArea=true;

	if(objectPosition.getObjY()==1)
		verticalDirection='u';
	else{
		if(inPlayerArea==false){
			if(objectPosition.getObjY()==39)
				verticalDirection='d';
		}
		else{
			if(objectPosition.getObjY()==5)
				verticalDirection='d';
		}
	}
}
Segment::~Segment() {
	// TODO Auto-generated destructor stub
}

