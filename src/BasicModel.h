#ifndef BASICMODEL_H
#define BASICMODEL_H

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

using namespace std;

class BasicModel : public osg::Referenced
{
public:

	// Constructor toma una referencia a un string
	BasicModel( const char* file );
	~BasicModel();

// protected:

	// Una lista de Modelos
	osg::ref_ptr< osg::Node > mNode;
	// Una matriz de transformacion
	osg::ref_ptr< osg::MatrixTransform > mMat;
	// Un StateSet
	osg::ref_ptr< osg::StateSet > mState;
	// Un cullFace
	osg::ref_ptr< osg::CullFace > mCull;
	// Un depth
	osg::ref_ptr< osg::Depth > mDepth;
	// Vectores de posicion, axis, escala
	osg::Vec3 position, axis, scale;
	// Una matriz para hacer las transformaciones
	osg::Matrix matrix;

};

#endif