#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(0,0,0);
}

//--------------------------------------------------------------
void testApp::update(){

	game.update();
}

//--------------------------------------------------------------
void testApp::draw(){

	string aux =  "Lines: ";
	aux += ofToString (game.getClearedLines() );
	glColor3ub(255,255,255);
	ofDrawBitmapString(aux, 40,40);

	glTranslatef(40,60,0);
	game.draw();
		
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	if (key == OF_KEY_LEFT)
		game.shape->moveLeft();

	if (key == OF_KEY_RIGHT)
		game.shape->moveRight();

	if (key == OF_KEY_UP)
		game.shape->dropDown();

	if (key == OF_KEY_DOWN)
		game.shape->moveDown();

	if (key == ' ')
		game.clearBoard();
	
	if (key == 's')
		game.shape->rotateRight();

	if (key == 'a')
		game.shape->rotateLeft();

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

