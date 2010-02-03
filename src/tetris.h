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
#define CANVAS_HEIGHT	25

#define NUM_PATTERNS	5	/*[0..4]*/

class Shape;

class Tetris{

	public:
	
	Tetris();
	~Tetris(){};
		
	void update();
	void checkForLines();
	void dropDown(int line);
	void draw();

	void setColorForTile(int tile);
	
	void resetCompleteMap();
	
	
	int board[CANVAS_WIDTH][CANVAS_HEIGHT];

	bool completeLineMap[CANVAS_HEIGHT];

	float time;
	
	Shape * shape;
	
};