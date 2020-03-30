/*
 * ScoreBoard.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#include "ScoreBoard.h"

ScoreBoard::ScoreBoard() :numOfLives(0),score(0){
	this->objectPosition.setObjX(50);
	this->objectPosition.setObjY(800);
}

void ScoreBoard::draw(){
	string scr="Score = "+to_string(score);
	DrawString( objectPosition.getObjX(), objectPosition.getObjY(), scr, colors[MISTY_ROSE]);
	DrawString( objectPosition.getObjX()+850, objectPosition.getObjY(), "Lives = ", colors[MISTY_ROSE]);
}

void ScoreBoard::increaseScore(int temp){
	score+=temp;
}

int ScoreBoard::getObjectPositionX(){
	return this->objectPosition.getObjX();
}
int ScoreBoard::getObjectPositionY(){
	return this->objectPosition.getObjY();
}

ScoreBoard::~ScoreBoard() {
	// TODO Auto-generated destructor stub
}

