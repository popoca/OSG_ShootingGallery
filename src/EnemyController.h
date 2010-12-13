#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

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
#include <osg/Matrix>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class EnemyController : public osg::NodeCallback 
{
public:

   //Constructor
	EnemyController( float delta, osg::Vec3f pos, const char* name );
   ~EnemyController();
   void update();

   // Reimplementacion del metodo operator, metodo que se invoca cada
   // vez que se recorre y actualiza el grafo de escena, Nota se
   // presupone que el nodo que se va a operar es un nodo PositionAttitudeTransform
   virtual void operator()( osg::Node* node, osg::NodeVisitor* nv );

   // delta de tiempo
   float delta;
   float speed;

private:

	osg::Vec3f pos;
	string name;
	float accAngle;
	float x;
	float y;
	bool reverse;

};

#endif