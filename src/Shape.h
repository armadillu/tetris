/*
 *  Shape.h
 *  openFrameworks
 *
 *  Created by Oriol Ferrer Mesià on 03/02/10.
 *  Copyright 2010 uri.cat. All rights reserved.
 *
 */

#pragma once

#include "tetris.h"

#define MAX_SHAPE_SIZE		4

class Tetris;

class Shape{

	public:
	
	Shape( Tetris* board );
	
	void update(){};
	void draw();

	void regenerate();
	void moveLeft();
	void moveRight();
	void moveDown();
	void dropDown();
	
		
	bool testCollision();
	void printOnBoard();
	
	int x, y;
	int shape[MAX_SHAPE_SIZE][MAX_SHAPE_SIZE];

	bool falling;
	bool fresh;
	Tetris * tetris;
	
};