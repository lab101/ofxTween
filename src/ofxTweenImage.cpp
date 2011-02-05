/*
 *  ofxTweenImage.cpp
 *  ofxTweenExample
 *
 *  Created by Kris Meeusen on 01/02/11.
 *  Copyright 2011 Lab101. All rights reserved.
 *
 */

#include "ofxTweenImage.h"
//unsigned delay = 2000;

bool ofxTweenImage::isAnimationRunning() {
	return moveMultiTween.isRunning() || scaleTween.isRunning();
}


ofxTweenImage::ofxTweenImage()
{
	setScale(1);
	setRotation(0);
}

void ofxTweenImage::setPosition(float x,float y)
{
	position.x = x;
	position.y = y;
}

ofPoint ofxTweenImage::getPosition()
{
	return position;
}

void ofxTweenImage::setScale(float s)
{
	scale = s;
}

float ofxTweenImage::getScale()
{
	return scale;
}

void ofxTweenImage::setRotation(float r)
{
	rotation = r;
}

float ofxTweenImage::getRotation()
{
	return rotation;
}


void ofxTweenImage::moveTo(ofPoint point,float duration)
{
	//moveTo(point,ofxTween::easeInOut, duration,0);
}

void ofxTweenImage::moveTo(ofPoint point,ofxEasing & easing,float duration,float delay)
{	
	moveMultiTween.setParameters(easing,ofxTween::easeOut, position.x,point.x,duration,delay);
    moveMultiTween.addValue(position.x,point.x);
    moveMultiTween.addValue(position.y,point.y);
	moveMultiTween.start();
}

void ofxTweenImage::scaleTo(float targetScale,ofxEasing & easing,float duration,float delay)
{	
	scaleTween.setParameters(easing,ofxTween::easeOut, scale,targetScale,duration,delay);
}

void ofxTweenImage::rotateTo(float targetRotation,ofxEasing & easing,float duration,float delay)
{	
	rotateTween.setParameters(easing,ofxTween::easeOut, rotation,targetRotation,duration,delay);
}

void ofxTweenImage::update()
{
	if (moveMultiTween.isRunning()) {
		moveMultiTween.update();
		position.x = moveMultiTween.getTarget(1);
		position.y = moveMultiTween.getTarget(2);	
	}
	
	if(scaleTween.isRunning())
	{
		scale = scaleTween.update();
	}
	
	if(rotateTween.isRunning())
	{
		rotation = rotateTween.update();
	}
	
}

void ofxTweenImage::draw()
{
	glPushMatrix();
		
	ofTranslate(position.x,position.y, 0);
	
	ofScale(scale, scale, 1);
	ofRotateZ(rotation);
	
	ofImage::setAnchorPercent(0.5, 0.5);
	ofImage::draw(0,0);
	glPopMatrix();
}