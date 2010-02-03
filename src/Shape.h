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

#define MAX_SHAPE_SIZE		3

class Tetris;

class Shape{

	public:
	
	Shape( Tetris* board );
	
	void update(){};

	void regenerate();
	void moveLeft();
	void moveRight();
	void moveDown();
	void dropDown();
	
	void rotateRight();
	void rotateLeft();
	
		
	bool testCollision();
	void printOnBoard();
	
	int x, y;
	int shape[MAX_SHAPE_SIZE][MAX_SHAPE_SIZE];

	bool falling;
	bool fresh;
	Tetris * tetris;
	
};