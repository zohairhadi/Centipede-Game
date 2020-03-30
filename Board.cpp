/*
 * Board.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */

#include "Board.h"
#include <cstdio>
//int Board::count=0;
// Asteroids board

// Note that all these enum constants from NILL onwards
// have been given numbers in increasing order
// e.g. NILL=0, and so on
// and these numbers are represented in the board array...
enum BoardParts {
	NILL, S_BRICK, G_BRICK, R_BRICK, LASER, MUSHROOM, MENU, PLAYER, CENTIPEDE, FLEA
};
// defining some utility functions...

/* board_array[Board::BOARD_Y][Board::BOARD_X] = { { 0 } };*/

// Destructor
Board::~Board(void) {
}
void Board::InitalizeBoard(int w, int h) {
	cout << "Initialize board" << endl;
	width = w;
	height = h;
	for (int i = 0; i < BOARD_Y - 1; ++i) {
		for (int j = 0; j < BOARD_X; ++j) {
			// can use G_BRICK, R_BRICK, or S_BRICK here
			board_array[i][j] = NILL;
		}
	}
	InitializePolyArray();
}

void Board::InitializePolyArray(){
	srand(time(NULL));
//	snake.push_back(new Centipede);
	gameObj.push_back(p);
	gameObj.push_back(scoreBoard);
	gameObj.push_back(fle);
	for(int i=0;i<20;i++)
		gameObj.push_back(new Mushroom(GetRandInRange(1,50),GetRandInRange(5,39)));

}

//Constructor
Board::Board(int xsize, int ysize):endGame(false),menu(true),width(0),height(0),menuNo(0){
	srand(time(NULL));
	cout << "Constructor board" << endl;
	xcellsize = xsize;
	ycellsize = ysize;
	pcolor = CHOCOLATE;
	bcolor = ORANGE_RED;
	gcolor = PINK;
	for (int i = 0; i < BOARD_Y; ++i){
		for (int j = 0; j < BOARD_X; ++j){
			board_array[i][j] = 0;
		}
	}
//set up board
}

void Board::drawMenu(){
//	if(menu==true){
		DrawString(400,550,"***Centipede Game***",colors[GetRandInRange(0,100)]);
		for(int i=0;i<20;i++){
			if(i%2==0)
				DrawCircle(340+i*20,620,10,colors[GetRandInRange(0,100)]);
			else
				DrawCircle(340+i*20,616,10,colors[GetRandInRange(0,100)]);
		}

		DrawString(450,500,"1.	Start Game",colors[92]);
//		DrawString(240,450,"2.	Resume Game",colors[92]);
//		DrawString(240,400,"3.	Change Level",colors[92]);
		DrawString(450,450,"2.	High Score",colors[92]);
		DrawString(450,400,"3.	Exit",colors[92]);

		switch(menuNo){
		case(0):
				break;
		case(1):
		{
				menu=false;
				break;
		}

		case(2):
		{
//			for (int i = 0; i < BOARD_Y; ++i){
//				for (int j = 0; j < BOARD_X; ++j){
//					DrawSquare( BOARD_Y*20 , BOARD_X*20 ,20,colors[BLACK]);
//				}
//			}
			int c=0,temp;
			ifstream file;
			file.open("highScore.txt");
			DrawString(200,500,"HIGH SCORES",colors[WHITE]);
			while(!file.eof())
			{
				file>>highs[c];
				c++;
			}
			for(int i=0;i<c;i++)
			{
				for(int j=i+1;j<c;j++)
				{
					if(highs[j]>highs[i])
					{
						temp=highs[i];
						highs[i]=highs[j];
						highs[j]=temp;
					}
				}
			}
			string kk;
			for(int i=0;i<5;i++)
			{
				stringstream ss;
				ss<<highs[i]<<endl;
				string sstr=ss.str();
				kk=to_string(i+1);
				DrawString(260,400-i*30,kk,colors[WHITE]);DrawString(270,400-i*30,".	",colors[WHITE]);
				DrawString(280,400-i*30,sstr,colors[WHITE]);
			}
			break;
		}

		case(3):
		{
				menu=false;
				exit(1);
				break;
		}


		}
//	}
}

void Board::gameOver(){
	for (int i = 0; i < BOARD_Y; ++i){
		for (int j = 0; j < BOARD_X; ++j){
			board_array[i][j] = 0;
		}
	}
	DrawString(400,550,"GAME OVER",colors[GetRandInRange(0,100)]);
}


void Board::win(){
	for (int i = 0; i < BOARD_Y; ++i){
		for (int j = 0; j < BOARD_X; ++j){
			board_array[i][j] = 0;
		}
	}
	DrawString(400,550,"YOU WINNNN",colors[GetRandInRange(0,100)]);

}

void Board::Draw() {
	glColor3f(0, 0, 1);
	glPushMatrix();
	if(menu==true)
		drawMenu();
	else if(endGame==true)
		gameOver();
	else if(youWin==true)
		win();
	else{
		for (int i = BOARD_Y - 2, y = 0; i >= 0; --i, y += xcellsize) {
			for (int j = 0, x = 0; j < BOARD_X; j++, x += ycellsize) {
				switch (board_array[i][j]) {
				case NILL:
					// Empty space
					break;
				case S_BRICK:
					DrawRectangle(x, y, ycellsize-1, xcellsize-1,colors[SLATE_GRAY]);
//					DrawLine(x - 10, y, x - 10 + ycellsize, y, 4, colors[BLACK]);
					break;
				case G_BRICK:
//					DrawRectangle(x , y, ycellsize, xcellsize,colors[LIGHT_GREEN]);
					break;
				case R_BRICK:
//					DrawRectangle(x - 10, y, ycellsize, xcellsize, colors[RED]);
					break;
				}
			}
		}

		for (int i = 0; i < BOARD_Y; ++i){// clear whole array
			for (int j = 0; j < BOARD_X; ++j){
				board_array[i][j] = 0;
			}
		}


		for(int i=0;i<gameObj.size();i++){//assign new values
			if(i==0){
				board_array[gameObj[i]->getObjectPositionX()][gameObj[i]->getObjectPositionY()]=LASER;
				board_array[p->returnPlayerPositionX()][p->returnPlayerPositionY()]=PLAYER;
//				collisionWithCentipede(i);
			}
			if(i==2){
//				if(board_array[gameObj[i]->getObjectPositionX()][gameObj[i]->getObjectPositionY()]==0)
				if(board_array[gameObj[i]->getObjectPositionX()][gameObj[i]->getObjectPositionY()]== LASER){
					if(fle->isFleaCrossed()==false){
						p->stopBomb();
						this->collisionWithFlea(gameObj[i]->getObjectPositionX());
					}
				}
//				else
//					board_array[gameObj[i]->getObjectPositionX()][gameObj[i]->getObjectPositionY()]=FLEA;
			}
			else if(i>2){
				if(board_array[gameObj[i]->getObjectPositionX()][gameObj[i]->getObjectPositionY()] == 0)
					board_array[gameObj[i]->getObjectPositionX()][gameObj[i]->getObjectPositionY()]=MUSHROOM;
				else if(board_array[gameObj[i]->getObjectPositionX()][gameObj[i]->getObjectPositionY()]==LASER){
					collisionWithMushroom(i);
					board_array[gameObj[i]->getObjectPositionX()][gameObj[i]->getObjectPositionY()]=0;
				}
			}

			if(fle->isFleaCrossed() && make==true){
				for(int i=0;i<s;i++){
//					if(gameObj[2]->getObjectPositionY()==arr[i]){
					gameObj.push_back(new Mushroom(gameObj[2]->getObjectPositionX(),arr[i]));
					board_array[fle->getObjectPositionX()][arr[i]]=MUSHROOM;
//					}
				}
//				for(int j=39;j<0;j--){
//					if(board_array[fle->getObjectPositionX()][j]!=MUSHROOM)
//						board_array[fle->getObjectPositionX()][j]=0;
//				}
				make=false;

			}
			gameObj[i]->draw();
		}
//		for(int i=0;i<snake.size();i++){
		for(int j=0;j<10;j++){
			if(board_array[snake.getPosX(j)][snake.getPosY(j)]==LASER){
				collisionWithCentipede(j);
				board_array[snake.getPosX(j)][snake.getPosY(j)]=MUSHROOM;
			}
			else if(board_array[snake.getPosX(j)][snake.getPosY(j)]==MUSHROOM){
				changeDirectionCentipede(j);
			}
			else if(board_array[snake.getPosX(j)][snake.getPosY(j)]==PLAYER){
				system("canberra-gtk-play -f gameover.wav");
				endGame=true;
				ofstream ofile;
				ofile.open("highScore.txt",ios::app);
				ofile<<scoreBoard->getScore()<<"\n";
				ofile.close();
				break;
			}
		}
		snake.Draw();
//		}
	}
	glPopMatrix();
}

bool Board::centipedeEatPlayer(){

	return 1;
}

bool Board::collisionWithFlea(int i){
	fle->setFleaCrossed(true);
	scoreBoard->increaseScore(200);cout<<"FLEA DESTROYED"<<endl;
	return 1;
}

bool Board::collisionWithCentipede(int i){
	p->stopBomb();
//	int s=snake.size()-i;
	youWin=snake.removeSegment(i);
	if(youWin==false){
		if(snake.getPosY(i)>5)
			gameObj.push_back(new Mushroom(snake.getPosX(i),snake.getPosY(i)));
	//	snake.push_back(new Centipede(snake.getPosX(i),snake.getPosY(i),s));
	}
	return 1;
}

bool Board::collisionWithMushroom(int i){
	gameObj[i]->mushroomHit();
	this->p->stopBomb();
	if(this->gameObj[i]->getHits()==0){
		for(int j=i;j<gameObj.size()-1;j++){
			gameObj[j]=gameObj[j+1];
		}
		gameObj.pop_back();
		scoreBoard->increaseScore(1);
	}
	return 1;
}

bool Board::changeDirectionCentipede(int i){
	int x1,x2,y1,y2;
	x1=snake.getPosX(i);
	y1=snake.getPosY(i);
	for(int j=3;j<21;j++){
		x2=gameObj[j]->getObjectPositionX();
		y2=gameObj[j]->getObjectPositionY();
		if(x1==x2 && y1==y2){
			this->snake.changePath(i);
//			return 1;
		}
	}
	return 0;
}

void Board::GetInitTextPosition(int &x, int &y) {
	x = xcellsize;
	y = (BOARD_Y - 1) * ycellsize + ycellsize / 2;
}
