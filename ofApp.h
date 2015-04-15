#pragma once

#include "ofMain.h"

class Circle {
public:
	int x, y;
	float vx, vy;
	float cor;
	float math;
	int rad;
	int r, g, b, a;

	Circle() {
		rad = 100;
		x = ofRandom(rad, ofGetWidth() - rad);
		y = ofRandom(rad, ofGetHeight() - rad);
		cor = ofRandomuf();
		math = 1;
		Turn();
		r = ofRandom(100, 200);
		g = ofRandom(100, 200);
		b = ofRandom(100, 200);
		a = 200;
	}

	void Update() {
		if (x + vx - rad < 0 || x + vx + rad > ofGetWidth()) vx = -vx;
		if (y + vy - rad < 0 || y + vy + rad > ofGetHeight()) vy = -vy;
		x += vx;
		y += vy;
	}

	void Turn() {
		vx = ofRandom(0, 10) * ofRandomf();
		vy = ofRandom(0, 10) * ofRandomf();
	}

	void Turn(float x, float y) {
		vx = x;
		vy = y;
	}
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		static const int CIRCLE_NUM = 20;
		Circle* circles[CIRCLE_NUM];
		
		//static const int TURN_COUNT = 60;
		//int count;

		int collhis[CIRCLE_NUM][CIRCLE_NUM];
		void collision(int a, int b);
};