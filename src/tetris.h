/*
 *  tetris.h
 *  openFrameworks
 *
 *  Created by Oriol Ferrer Mesià on 03/02/10.
 *  Copyright 2010 uri.cat. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "Shape.h"

#define CANVAS_WIDTH	10
#define CANVAS_HEIGHT	20

#define NUM_PATTERNS	6	/*[1..6]*/

class Shape;

class Tetris{

	public:
	
	Tetris();
	~Tetris(){};
		
	void update();
	void draw();

	void clearBoard();
	void deleteFullLines();
	
	void setColorForTile(int tile);
	
	void resetCompleteMap();
	void dropDown(int line);	//this erases a full line, and drops everything down
	void checkForLines();
	
	int getClearedLines(){ return clearedLines;	};
	
	
	int board[CANVAS_WIDTH][CANVAS_HEIGHT];

	bool completeLineMap[CANVAS_HEIGHT];

	float time;
	
	Shape * shape;
	
	int clearedLines;
	
};