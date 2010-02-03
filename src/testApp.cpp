#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

	game.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	glTranslatef(20,20,0);
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

