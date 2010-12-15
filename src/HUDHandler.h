#ifndef _SHOOTHUD_
#define _SHOOTHUD_

#include <osg/PositionAttitudeTransform>
#include <osg/Group>
#include <osg/Node>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osgText/Font>
#include <osgText/Text>
#include <osg/MatrixTransform>
#include <osg/Geode>
#include <osg/Projection>
#include <osg/ShapeDrawable>
#include <osg/Geometry>
#include <osgGA/TrackballManipulator>
#include <osg/Image>
#include <string.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <osg/PositionAttitudeTransform>

using namespace std;

class HUDHandler
{
private:

public:
	int MAX;
	int SCORE;
	osg::ref_ptr<osg::Group> root;
	osg::Geode* HUDGeode;
	osg::Projection* HUDProjectionMatrix;
	osg::Geometry* HUDBackgroundGeometry;
	osg::Vec3Array* HUDBackgroundVertices;
	osg::DrawElementsUInt* HUDBackgroundIndices;
	osg::Vec4Array* HUDcolors;
	osg::Vec2Array* texcoords;
	osg::Texture2D* HUDTexture;
	osg::Vec3Array* HUDnormals;
	osg::StateSet* HUDStateSet;
	osg::MatrixTransform* HUDModelViewMatrix;
	bool showing;
	
	HUDHandler(osg::ref_ptr<osg::Group> root);
	~HUDHandler();
	
	void init_text();
	void init_images();
	void init_general();
	void shoot();
	void reload();
	void achievePork();
	void achieveBird();
	void achieveRabbit();
	void setupBulletsHUD();
	osg::Geode* getGeode();
	void updateScore();
	int currentBullets;
	void initDisplayMessage();
	void showMessage(const char* message);
	void quitMessage();
	osg::Geode* buildCursor();
	osg::PositionAttitudeTransform* buildBullets();
	void setCursorPosition(double x, double y);
	
	
	void moveCursor(double x, double y);
	
	osg::Image* bullet;
	osg::Image* bullet1;
	osg::Image* bullet2;
	osg::Image* bullet3;
	osg::Image* bullet4;
	osg::Image* bullet5;
	osg::Image* bullet6;
	osg::Image* transparent;
	osg::Image* current_bullet_image;
	
	osg::Image* cursor;
	osgText::Text* scoreText;
	osgText::Text* messageText;
	osg::Drawable* bulletImage;
	osg::PositionAttitudeTransform* patCursor;
	

};

#endif
