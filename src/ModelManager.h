#ifndef MODELMANAGER_H
#define MODELMANAGER_H

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
#include <algorithm>
#include "BasicModel.h"

using namespace std;

class ModelManager : public osg::Referenced
{
public:

	/* Methods */

	// Constructor toma una referencia a un string
	ModelManager( osg::ref_ptr< osg::Group > rt );
	// Destructor
	~ModelManager();
	// Metodos para agregar todo a root
	void setUpScene();

	// Esta clase tiene una referencia a root
	osg::ref_ptr< osg::Group > root;
	// Una lista de BasicModels para el escenario
	vector< osg::ref_ptr< BasicModel > > bg;
	// Una lista de Enemies para los enemigos
	

};

#endif