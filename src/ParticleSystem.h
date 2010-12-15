#ifndef PARTICLE_H
#define PARTICLE_H

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
#include <osg/ShapeDrawable>
#include <osg/MatrixTransform>
#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osgDB/ReadFile>
#include <osg/Texture2D> 
#include <osgDB/ReadFile> 
#include <iostream>

class ParticleSystem : public osg::Referenced
{
public:

	ParticleSystem( osg::ref_ptr< osg::Group > root );
	~ParticleSystem();

	// Un sistema de particulas tiene una referencia a root
	osg::ref_ptr< osg::Group > root;

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