#include "ParticleSystem.h"

ParticleSystem::ParticleSystem( osg::ref_ptr< osg::Group > root )
: root( root )
{
	// Create and initialize a particle system
    dustParticleSystem = new osgParticle::ParticleSystem;

    // Set the attributes 'texture', 'emmisive' and 'lighting'
    dustParticleSystem->setDefaultAttributes(
    "../content/sangre2.tga", 
    true, false);

    // Since the particle system is derived from the class Drawable, we can create
    // add it to the scene as a child of a geode 
    geode = new osg::Geode; 

    root->addChild(geode);
    geode->addDrawable(dustParticleSystem);

    // Add an 'updater' to help per-frame management
    dustSystemUpdater = new osgParticle::ParticleSystemUpdater;

    // Associate this updater with our particle system 
    dustSystemUpdater->addParticleSystem(dustParticleSystem);
    // add the updater node to the scene graph
    root->addChild(dustSystemUpdater);

    // Create a partical to be used by our particle system and define a few
    // of its properties
    osgParticle::Particle smokeParticle; 
    smokeParticle.setSizeRange(osgParticle::rangef(0.1,40.0)); // meters

    smokeParticle.setLifeTime(1); // seconds
    smokeParticle.setMass(0.01); // in kilograms
    // Make this our particle system's default particle 
    dustParticleSystem->setDefaultParticleTemplate(smokeParticle);

	/* Modular Program */

	// Create a modular program and attach it to our particle system
    osgParticle::ModularProgram *moveDustInAir = new osgParticle::ModularProgram;
    moveDustInAir->setParticleSystem(dustParticleSystem);

    // Create an operator that simulates gravity, adjust it and add it to our program
    osgParticle::AccelOperator *accelUp = new osgParticle::AccelOperator;
    accelUp->setToGravity(-1); // scale factor for normal acceleration due to gravity. 
    moveDustInAir->addOperator(accelUp);

    // Add an operator to our program to calculate the friction of air.
    osgParticle::FluidFrictionOperator *airFriction = new osgParticle::FluidFrictionOperator;
    airFriction->setFluidToAir();

    //airFriction->setFluidDensity(1.2929/*air*/*5.0f);
    moveDustInAir->addOperator(airFriction);

    // Finally, add the program to the scene 
    root->addChild(moveDustInAir);


}

ParticleSystem::~ParticleSystem()
{

}