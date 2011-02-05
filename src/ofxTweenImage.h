/*
 *  ofxTweenImage.h
 *  ofxTweenExample
 *
 *  Created by Kris Meeusen on 01/02/11.
 *  Copyright 2011 Lab101. All rights reserved.
 *
 */
#include "ofImage.h"
#include "ofMain.h"
#include "ofxTween.h"
#include "ofxEasing.h"

class ofxTweenImage : public ofImage {
	public:
	
	ofxTweenImage();
	void moveTo(ofPoint point,float duration);
	void moveTo(ofPoint point,ofxEasing & easing,float duration,float delay);

	void scaleTo(float targetScale,ofxEasing & easing,float duration,float delay);

	void rotateTo(float targetRotation,ofxEasing & easing,float duration,float delay);

	
	void draw();
	
	void setPosition(float x,float y);
	ofPoint getPosition();
	
	void setScale(float s);
	float getScale();

	void setRotation(float r);
	float getRotation();
	
	void update();
	
	bool isAnimationRunning();

	ofxTween scaleTween;
	ofxTween rotateTween;
	ofxTween moveMultiTween;
	
	ofxTween tweenelastic;
	ofxEasingElastic easingelastic;


private:
	ofPoint position;
	float scale;
	float rotation;
	
};