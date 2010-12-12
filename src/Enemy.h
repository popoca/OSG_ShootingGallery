#ifndef ENEMY_H
#define ENEMY_H

#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osgDB/ReadFile>
#include <osg/Texture2D> 
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>
#include <osg/CullFace>
#include <osg/Depth>
#include <osg/MatrixTransform>
#include <string>
#include <iostream>
#include "BasicModel.h"

using namespace std;

class Enemy : public BasicModel
{
public:

	// Constructor toma una referencia a un string
	Enemy( const char* file, const char* name, float speed );
	~Enemy();

// protected:

	// Un enemigo tiene velocidad
	float speed;
	// Un Modelo para la explosion
	osg::ref_ptr< osg::Node > mNode;
	// Vectores de posicion, axis, escala
	osg::Vec3 position, axis, scale;
	// Una matriz para hacer las transformaciones
	osg::Matrix matrix;

};

#endif