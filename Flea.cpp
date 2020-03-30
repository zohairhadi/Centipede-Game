/*
 * Flea.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "Flea.h"

int Flea::count=0;
Flea::Flea():fleaCrossed(false),randTime(GetRandInRange(1,3000)){
	srand(time(NULL));
	size=GetRandInRange(0,10);
	trail=new int[size];
	for(int i=0;i<size;i++)
		trail[i]=GetRandInRange(6,35);
	this->direction='d';
	this->objectPosition.setObjY(39);
	this->objectPosition.setObjX(GetRandInRange(1,51));
}

void Flea::draw(){
	count++;
	cout<<randTime<<endl;
	if(count>=randTime){
		if(objectPosition.getObjY()>1){
			DrawCircle(this->objectPosition.getObjX()*20,this->objectPosition.getObjY()*20,10,colors[YELLOW]);
			DrawCircle(this->objectPosition.getObjX()*20+10,this->objectPosition.getObjY()*20,5,colors[GetRandInRange(10,15)]);
			move();
		}
		else
			fleaCrossed=true;
	}
}

int* Flea::getTrail(){
	return trail;
}
int Flea::getSize(){
	return size;
}
//bool Flea::shouldLeaveTrail(){
//	if(leaveTrail==0 && numOfTrail>0){
//		return 1;
//	}
//	return 0;
//}

void Flea::move(){
	this->objectPosition.setObjY(this->objectPosition.getObjY()-1);
}

int Flea::getObjectPositionX(){
	return this->objectPosition.getObjX();
}
int Flea::getObjectPositionY(){
	return this->objectPosition.getObjY();
}
Flea::~Flea() {
	// TODO Auto-generated destructor stub
}

