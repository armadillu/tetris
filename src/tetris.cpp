/*
 *  tetris.cpp
 *  openFrameworks
 *
 *  Created by Oriol Ferrer Mesià on 03/02/10.
 *  Copyright 2010 uri.cat. All rights reserved.
 *
 */

#include "tetris.h"

Tetris::Tetris(){

	clearBoard();
	resetCompleteMap();	
	shape = new Shape(this);
}


void Tetris::clearBoard(){

	clearedLines = 0;
	
	for (int i=0; i<CANVAS_WIDTH; i++){
		for (int j=0; j<CANVAS_HEIGHT; j++){
			board[i][j]=0;
		}
	}
}

void Tetris::deleteFullLines(){

	checkForLines();
	for (int j=0; j<CANVAS_HEIGHT; j++)
		if (completeLineMap[j] == true)
			dropDown(j);
	
}

void Tetris::dropDown(int line){

	clearedLines++;
	for (int j = line; j >= 1; j--){
		for (int i = 0; i<CANVAS_WIDTH; i++){
			board[i][j] = board[i][j-1];			
		}
	}

	for (int i = 0; i<CANVAS_WIDTH; i++)
		board[i][0] = 0;

}


void Tetris::resetCompleteMap(){
	
	for (int j=0; j<CANVAS_HEIGHT; j++)
		completeLineMap[j] = false;
}


void Tetris::checkForLines(){
	
	resetCompleteMap();
	
	for (int j=0; j<CANVAS_HEIGHT; j++){
		bool complete = true;
		for (int i=0; i<CANVAS_WIDTH; i++){
			if ( board[i][j] == 0 )
				complete = false;
		}
		completeLineMap[j] = complete;
	}
}


void Tetris::draw(){

	int s = 20;
	glColor3ub(60,60,60);
	ofNoFill();
	ofRect( 0, 0, s * CANVAS_WIDTH, s * CANVAS_HEIGHT );
	
	ofFill();
	
	for (int i=0; i<CANVAS_WIDTH; i++){
		for (int j=0; j<CANVAS_HEIGHT; j++){

			setColorForTile( board[i][j] );
			if ( board[i][j] != 0){
				ofRect( i * s, j * s, s, s);
			}
		}
	}
	
	for (int i = 0; i < MAX_SHAPE_SIZE; i++){
		for (int j = 0; j < MAX_SHAPE_SIZE; j++){
			
			if (shape->shape[i][j] != 0){
				setColorForTile( shape->shape[i][j] );
				ofRect(s * shape->x + s * i, s * shape->y + s * j, s, s);
			}
		}
	}
}


void Tetris::update(){
	
	time += 1.0f / ofGetFrameRate();
	
	float dropRate = 1.0f;
	
	if ( time > dropRate ){
		shape->moveDown();
		time = 0.0f;
	}
}


void Tetris::setColorForTile(int tile){

	switch (tile){
		
		case 1:
			glColor3f(0,1,0);
			break;
			
		case 2:
			glColor3f(0,0,1);
			break;
			
		case 3:
			glColor3f(1,1,0);
			break;
			
		case 4:
			glColor3f(1,0,0);
			break;

		case 5:
			glColor3f(1,0,1);
			break;

		case 6:
			glColor3f(0,1,1);
			break;

	}
}
