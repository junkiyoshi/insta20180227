#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofNoFill();
	ofSetColor(128);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	float radius = 300;
	int deg_span = 1;
	for (int z = -1200; z <= 300; z += 15) {

		ofBeginShape();
		for (int deg = 0; deg < 360; deg += deg_span) {

			float x = radius * cos(deg * DEG_TO_RAD);
			float y = radius * sin(deg * DEG_TO_RAD);
			float tmp_radius = ofMap(ofNoise(x * 0.005, y * 0.005, z * 0.005 + ofGetFrameNum() * 0.05), 0, 1, 200, 300);

			x = tmp_radius * cos(deg * DEG_TO_RAD);
			y = tmp_radius * sin(deg * DEG_TO_RAD);
			ofPoint point = ofPoint(x, y, z);
			ofVertex(point);
		}
		ofEndShape(true);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}