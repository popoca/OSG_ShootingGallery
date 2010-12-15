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
#include <cstring>
#include "BasicModel.h"
#include "EnemyController.h"
#include "ParticleSystem.h"

using namespace std;

class Enemy : public BasicModel
{
public:

	// Constructor toma una referencia a un string
	Enemy( const char* file, const char* name, const char* file2, 
		double spawnTime, float delta, float speed, ParticleSystem* particle,
		bool hasSpawned = false, bool isMoving = false
		);
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

	// Un sistema de particulas asociado para este tipo de enemigos
	ParticleSystem* particle;

	/* emmiter */
	osgParticle::ModularEmitter *emitter;

};

#endif