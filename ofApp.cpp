#include "ofApp.h"
#include <algorithm>

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableAlphaBlending();
	ofSetCircleResolution(64);
	ofBackground(0, 0, 0);
	ofSetFrameRate(60);

	for (Circle*& c : circles)
		c = new Circle();
	for (size_t i = 0; i < CIRCLE_NUM; i++)
	{
		for (size_t j = 0; j < CIRCLE_NUM; j++)
		{
			collhis[i][j] = 0;
		}
	}
	// count = 0;
}

void collision(Circle*& a, Circle*& b) {
	int dr = (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
	int radmax = a->rad + b->rad;
	// Ç‡Çµè’ìÀÇµÇΩÇÁ
	if (dr < radmax * radmax) {
		printf("coll\n");
		float davx = ((a->math - b->math) * a->vx + 2 * b->math * b->vx) / (float)(a->math + b->math);
		float davy = ((a->math - b->math) * a->vy + 2 * b->math * b->vy) / (float)(a->math + b->math);
		float dbvx = ((b->math - a->math) * b->vx + 2 * a->math * a->vx) / (float)(a->math + b->math);
		float dbvy = ((b->math - a->math) * b->vy + 2 * a->math * a->vy) / (float)(a->math + b->math);

		a->Turn(davx, davy);
		b->Turn(dbvx, dbvy);
	}
}

int l2d(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

float collcal(int m1, float v1, int m2, float v2) {
	return ((m1 - m2) * v1 + 2 * m2 * v2) / (float)(m1 + m2);
}

void ofApp::collision(int a, int b) {
	int dr = l2d(circles[a]->x, circles[a]->y, circles[b]->x, circles[b]->y);
	int rad = circles[a]->rad + circles[b]->rad;
	// Ç‡Çµè’ìÀÇµÇΩÇÁ
	if (dr < rad * rad) {

		if (collhis[a][b]) return;

		printf("coll\n");
		float davx = collcal(circles[a]->math, circles[a]->vx, circles[b]->math, circles[b]->vx);
		float davy = collcal(circles[a]->math, circles[a]->vy, circles[b]->math, circles[b]->vy);
		float dbvx = collcal(circles[b]->math, circles[b]->vx, circles[a]->math, circles[a]->vx);
		float dbvy = collcal(circles[b]->math, circles[b]->vy, circles[a]->math, circles[a]->vy);

		circles[a]->Turn(davx, davy);
		circles[b]->Turn(dbvx, dbvy);
		collhis[a][b] = 1;
		return;
	}

	collhis[a][b] = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	for (Circle*& c : circles)
		c->Update();

	for (int i = 0; i < CIRCLE_NUM; i++) {
		for (int j = i + 1; j < CIRCLE_NUM; j++) {
			collision(i, j);
		}
	}

	/*for (Circle*& c1 : circles) {
		for (Circle*& c2 : circles) {
			if (c1 == c2) continue;
			collision(&*c1, &*c2);
		}
	}*/

	/*if (count++ % TURN_COUNT)
		for (Circle*& c : circles)
			c->Update();
	else {
		for (Circle*& c : circles){
			c->Update();
			c->Turn();
		}
	}*/

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (Circle* c : circles) {
		ofSetColor(c->r, c->g, c->b, c->a);
		ofCircle(c->x, c->y, c->rad);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
