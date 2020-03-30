/*
 * Centipede.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "Centipede.h"

Centipede::Centipede() {
	segments.push_back(new MagicSeg(40,39));
	for(int i=0;i<9;i++){
		segments.push_back(new LazySeg(41+i,39));
		if(i==0){
			headX=segments[i]->getObjectPositionX();
			headY=segments[i]->getObjectPositionY();
		}
	}
}

Centipede::Centipede(int X,int Y, int size){
	segments.push_back(new MagicSeg(X,Y));
	for(int i=1;i<10;i++){
		segments.push_back(new LazySeg(X+i,Y));
		segments[i]->changeVerticle();
		if(i==0){
			headX=segments[i]->getObjectPositionX();
			headY=segments[i]->getObjectPositionY();
		}
	}
}

//void Centipede::Move(){
//	for(int i=0;i<segments.size();i++)
//		segments[i]->move();
//}

void Centipede::Draw(){
	for(int i=0;i<segments.size();i++)
		segments[i]->draw();
}

int Centipede::getHeadX(){
	return headX;
}
int Centipede::getHeadY(){
	return headY;
}
int Centipede::getPosX(int index){
	return this->segments[index]->getObjectPositionX();
//	return headX;
}
int Centipede::getPosY(int index){
	return this->segments[index]->getObjectPositionY();
//	return headY;
}
bool Centipede::removeSegment(int i){
//	segments.erase(segments.begin()+i-1);
//	segments[i]->~Segment();
	for(int j=i;j<segments.size();j++){
		segments.pop_back();
//		segments[j]=segments[j+1];
	}
	if(segments.size()==0)
		return 0;
	else
		return 1;
}

void Centipede::changePath(int i){
	segments[i]->changeVerticle();
//	for(int i=0;i<segments.size();i++){
		if(segments[i]->getDirection()=='r')
			this->segments[i]->setDirection('l');
		else if(segments[i]->getDirection()=='l')
			this->segments[i]->setDirection('r');
//	}
}

Centipede::~Centipede() {
	// TODO Auto-generated destructor stub
}

