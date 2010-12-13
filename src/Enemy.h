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
#include "EnemyController.h"
#include <osgParticle/Particle>
#include <osgParticle/ParticleSystem>
#include <osgParticle/ParticleSystemUpdater>
#include <osgParticle/ModularEmitter>
#include <osgParticle/RandomRateCounter>
#include <osgParticle/PointPlacer>
#include <osgParticle/RadialShooter>
#include <osgParticle/MultiSegmentPlacer>
#include <osgParticle/ModularProgram>
#include <osgParticle/AccelOperator>
#include <osgParticle/FluidFrictionOperator>
#include <osg/PositionAttitudeTransform>
#include <cstring>
#include <osg/ShapeDrawable>

using namespace std;

class Enemy : public BasicModel
{
public:

	// Constructor toma una referencia a un string
	Enemy( const char* file, const char* name, const char* file2, double spawnTime, float delta, float speed, bool hasSpawned = false, bool isMoving = false );
	~Enemy();
	// metodo para iniciar el sistema de particulas
	void fluxCapacitor();
	void unfluxCapacitor();

// protected:

	// Un enemigo tiene velocidad
	float speed;
	// Una delta de tiempo para contar
	float delta;
	// Una bandera para ser visible
	bool hasSpawned;
	// Una bandera para moverse
	bool isMoving;
	// Una bandera para el condensador de flujos
	bool fluxing;
	// Un Modelo para la explosion
	osg::ref_ptr< osg::Node > mNodeXplode;
	// Vectores de posicion, axis, escala
	osg::Vec3 position, axis, scale;
	// Una matriz para hacer las transformaciones
	osg::Matrix matrix;
	// Tiempo en el que aparecera el enemigo en el sceneGraph
	double spawnTime;
	// Tiempo en el que desaparecera el enemigo del sceneGraph
	double eraseTime;

	/* Particle System */

	// Create a particle system
	osg::ref_ptr< osgParticle::ParticleSystem > dustParticleSystem;
	// Geode for psystem
	osg::ref_ptr< osg::Geode > geode;
	// Add an 'updater' to help per-frame management
	osg::ref_ptr< osgParticle::ParticleSystemUpdater > dustSystemUpdater;
	// Create a modular emitter (this contains default counter, placer and shooter.)
	osgParticle::ModularEmitter *emitter;
	// Get a handle to the emitter's counter and adjust the number of new particles
    // that will be added each frame
	osgParticle::RandomRateCounter *dustRate;
	// To customize the placer, create and initialize a multi-segment placer
	osgParticle::MultiSegmentPlacer* lineSegment;
	// matrixsleepy
	osg::ref_ptr< osg::MatrixTransform > modelTransform;
	// movedustinair? lawl
	osg::ref_ptr< osgParticle::ModularProgram > moveDustInAir;
	

};

#endif