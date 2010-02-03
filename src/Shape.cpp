/*
 *  Shape.cpp
 *  openFrameworks
 *
 *  Created by Oriol Ferrer Mesià on 03/02/10.
 *  Copyright 2010 uri.cat. All rights reserved.
 *
 */

#include "Shape.h"

Shape::Shape( Tetris* board){
	ofSeedRandom( ofGetElapsedTimeMillis() );
	tetris = board;
	regenerate();
}


void Shape::regenerate(){
	
	x = CANVAS_WIDTH / 2 - MAX_SHAPE_SIZE / 2;
	y = -MAX_SHAPE_SIZE;

	int color = ofRandom(1, NUM_PATTERNS);
	int tiles = 0;
	
	for (int i = 0; i < MAX_SHAPE_SIZE; i++){
		for (int j = 0; j < MAX_SHAPE_SIZE; j++){
			if (ofRandom(0, 1) < 0.3){
				shape[i][j] = color;
				tiles++;
			}else
				shape[i][j] = 0;
		}
	}
	
	if (tiles == 0)	//at least one quad!
		shape[0][0] = color;
	
	fresh = true;
	falling = true;
	
}


bool Shape::testCollision(){

//	if ( y > CANVAS_HEIGHT - MAX_SHAPE_SIZE){
//		printf("collide floor!\n");
//		return true;
//	}
		
	int collide = false;
	
	for (int i = 0; i < MAX_SHAPE_SIZE; i++){
		for (int j = 0; j < MAX_SHAPE_SIZE; j++){

			int xx = i+x;
			int yy = j+y;
			
			if ( xx >= 0 && xx < CANVAS_WIDTH && yy >= 0 && yy < CANVAS_HEIGHT){
							
				if ( tetris->board[xx][yy] == 0 || shape[i][j] == 0){
					//good, no collision on this tile
				}else{
					collide = true;
					break;
				}
			}
			
			if ( shape[i][j] != 0 && yy >= CANVAS_HEIGHT)
				collide = true;
			
			if ( shape[i][j] != 0 && xx < 0)
				collide = true;

			if ( shape[i][j] != 0 && xx >= CANVAS_WIDTH)
				collide = true;


		}
	}

	return collide;	//collision
}


void Shape::printOnBoard(){

	for (int i = 0; i < MAX_SHAPE_SIZE; i++){
		for (int j = 0; j < MAX_SHAPE_SIZE; j++){
			if (tetris->board[i+x][j+y] == 0)
				tetris->board[i+x][j+y] = shape[i][j];
		}
	}
}


void Shape::rotateLeft(){
	
	int t[MAX_SHAPE_SIZE][MAX_SHAPE_SIZE];
	
	for (int i = 0; i < MAX_SHAPE_SIZE; i++){
		for (int j = 0; j < MAX_SHAPE_SIZE; j++){
			t[i][j] = shape[MAX_SHAPE_SIZE -j -1][i];
		}
	}
	
	for (int i = 0; i < MAX_SHAPE_SIZE; i++){
		for (int j = 0; j < MAX_SHAPE_SIZE; j++){
			shape[i][j]= t[i][j];
		}
	}	
}


void Shape::rotateRight(){
	
	int t[MAX_SHAPE_SIZE][MAX_SHAPE_SIZE];
	
	for (int i = 0; i < MAX_SHAPE_SIZE; i++){
		for (int j = 0; j < MAX_SHAPE_SIZE; j++){
			t[i][j] = shape[j][MAX_SHAPE_SIZE -i -1];
		}
	}
	
	for (int i = 0; i < MAX_SHAPE_SIZE; i++){
		for (int j = 0; j < MAX_SHAPE_SIZE; j++){
			shape[i][j]= t[i][j];
		}
	}	
}

void Shape::moveLeft(){

	fresh = false;
	
	x--;
	
	if( testCollision() == true ) //we collide
		x++;
}


void Shape::moveRight(){

	fresh = false;

	x++;
	
	if( testCollision() == true ) //we collide
		x--;
}


void Shape::moveDown(){

	fresh = false;
	y++;
		
	if( testCollision() == true ){ //we collide
		y--;
		falling = false;
		printOnBoard();
		
		tetris->deleteFullLines();
		regenerate();
		
	} 
}

void Shape::dropDown(){

	fresh = false;
	while (fresh == false)
		moveDown();
	
}

