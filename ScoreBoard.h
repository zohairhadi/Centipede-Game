/*
 * ScoreBoard.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zohair
 */

#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_
#include"GameObject.h"
class ScoreBoard:public GameObject{
	int score;
	int numOfLives;
public:
	ScoreBoard();
	virtual void draw();
	virtual int getObjectPositionX();
	virtual int getObjectPositionY();
	void increaseScore(int temp);
	int getScore(){return score;}
	virtual ~ScoreBoard();
};

#endif /* SCOREBOARD_H_ */
