#include "Enemy.h"

Enemy::Enemy( const char* file, const char* file2, const char* name, double spawnTime, float delta, float speed, ParticleSystem* particle, bool hasSpawned, bool isMoving )
: BasicModel( file, name ), speed( speed ), spawnTime( spawnTime ), hasSpawned( false ), eraseTime( 5.0 ), delta( delta ), fluxing( false ), particle( particle )
{
	mNodeXplode = osgDB::readNodeFile( file2 );
	if( mNode )
	{
		mNodeXplode->setName( name );
		mState = mNodeXplode->getOrCreateStateSet();
		// mPat->addChild( mNodeXplode.get() );
	}

	if( (!strcmp (mNode->getName().c_str(), "buitre" )|| (!strcmp (mNode->getName().c_str(), "buitre2" ))))
	{
		mPat->setUpdateCallback( new EnemyController( speed, osg::Vec3f( -10.0f, 0.0f, 0.0f ), "buitre" ) );
		cout << "AI cargada para " << mNode->getName() << endl;
	}

	if( (!strcmp (mNode->getName().c_str(), "cerdito" )|| (!strcmp (mNode->getName().c_str(), "cerdito2" ))) )
	{
		mPat->setUpdateCallback( new EnemyController( speed, osg::Vec3f( -10.0f, 0.0f, 0.0f ), "cerdito" ) );
		cout << "AI cargada para " << mNode->getName() << endl;
	}

	if( (!strcmp (mNode->getName().c_str(), "conejo" )|| (!strcmp (mNode->getName().c_str(), "conejo2" ))) )
	{
		mPat->setUpdateCallback( new EnemyController( speed, osg::Vec3f( -20.0f, 0.0f, 0.0f ), "conejo" ) );
		cout << "AI cargada para " << mNode->getName() << endl;
	}

	/* Psys helper */

	// Create a modular emitter (this contains default counter, placer and shooter.)
    emitter = new osgParticle::ModularEmitter;

    // Associate this emitter with the particle system 
    emitter->setParticleSystem(particle->dustParticleSystem);

    // Get a handle to the emitter's counter and adjust the number of new particles
    // that will be added each frame
    osgParticle::RandomRateCounter *dustRate = 

    static_cast<osgParticle::RandomRateCounter *>(emitter->getCounter());
    dustRate->setRateRange(50, 60); // generate 5 to 10 particles per second

    // To customize the placer, create and initialize a multi-segment placer 

    osgParticle::MultiSegmentPlacer* lineSegment = new osgParticle::MultiSegmentPlacer();
    // Add vertices to our placer. This defines line seqments along which our particles will
    // originate. (If we co-locate a tank and this emitter, this will result in dust particles
    // originating from a line extending below and behind the tank model.) 

    lineSegment->addVertex(-4,-16,-2);
    lineSegment->addVertex(-4,-2,-2);
    lineSegment->addVertex(-4,-16,-2);

    // Use this placer for our emitter 
    emitter->setPlacer(lineSegment);

    // To customize the shooter, create and initialize a radial shooter 
    osgParticle::RadialShooter* smokeShooter = new osgParticle::RadialShooter();

    // Set properties of this shooter 
    smokeShooter->setThetaRange(0.0, 3.14159/2); // radians, relative to Z axis.
    smokeShooter->setInitialSpeedRange(1200,1200); // meters/second
    // Use this shooter for our emitter

    emitter->setShooter(smokeShooter);

}

Enemy::~Enemy()
{
}


void Enemy::fluxCapacitor()
{
	// PSystem
	// Create and initialize a particle system
	//osg::ref_ptr< osgParticle::ParticleSystem > dustParticleSystem = new osgParticle::ParticleSystem;

	//// Set the attributes 'texture', 'emmisive' and 'lighting'
 //   dustParticleSystem->setDefaultAttributes("../content/sangre2.tga", true, false);

	//// Since the particle system is derived from the class Drawable, we can create
 //   // add it to the scene as a child of a geode
	//osg::ref_ptr< osg::Geode > geode = new osg::Geode(); 
	//mPat->addChild(geode);
 //   geode->addDrawable( dustParticleSystem );

 //   // Add an 'updater' to help per-frame management
	//osg::ref_ptr< osgParticle::ParticleSystemUpdater > dustSystemUpdater = new osgParticle::ParticleSystemUpdater;

 //   // Associate this updater with our particle system 
 //   dustSystemUpdater->addParticleSystem(dustParticleSystem);
 //   // add the updater node to the scene graph
 //   mPat->addChild(dustSystemUpdater);

 //   // Create a particle to be used by our particle system and define a few
 //   // of its properties
 //   osgParticle::Particle smokeParticle; 
 //   smokeParticle.setSizeRange( osgParticle::rangef(0.05,20.0) ); // meters

 //   smokeParticle.setLifeTime(4); // seconds
 //   smokeParticle.setMass(0.1); // in kilograms
 //   // Make this our particle system's default particle 
 //   dustParticleSystem->setDefaultParticleTemplate(smokeParticle);

	//// Create a modular emitter (this contains default counter, placer and shooter.)
 //   osgParticle::ModularEmitter *emitter = new osgParticle::ModularEmitter;
	//
	//// Associate this emitter with the particle system 
 //   emitter->setParticleSystem(dustParticleSystem);

 //   // Get a handle to the emitter's counter and adjust the number of new particles
 //   // that will be added each frame
 //   osgParticle::RandomRateCounter *dustRate = 

 //   static_cast<osgParticle::RandomRateCounter *>(emitter->getCounter());
 //   dustRate->setRateRange(5, 10); // generate 5 to 10 particles per second

	//// To customize the placer, create and initialize a multi-segment placer 

 //   osgParticle::MultiSegmentPlacer* lineSegment = new osgParticle::MultiSegmentPlacer();
 //   // Add vertices to our placer. This defines line seqments along which our particles will
 //   // originate. (If we co-locate a tank and this emitter, this will result in dust particles
 //   // originating from a line extending below and behind the tank model.) 
 //   lineSegment->addVertex(-4,-16,-2);
 //   lineSegment->addVertex(-4,-2,-2);
 //   lineSegment->addVertex(-4,-16,-2);

	// // Use this placer for our emitter 
 //   emitter->setPlacer(lineSegment);

 //   // To customize the shooter, create and initialize a radial shooter 
 //   osgParticle::RadialShooter* smokeShooter = new osgParticle::RadialShooter();

 //   // Set properties of this shooter 
 //   smokeShooter->setThetaRange(2.0, 3.14159/2); // radians, relative to Z axis.
 //   smokeShooter->setInitialSpeedRange(500,1); // meters/second
 //   // Use this shooter for our emitter

 //   emitter->setShooter(smokeShooter);

	//osg::ref_ptr< osg::MatrixTransform > modelTransform = new osg::MatrixTransform(); 
 //   //modelTransform->setUpdateCallback( new orbit() ); // Callback that drives in a circle 

 //   // Add the emitter and the tank as children of this transform 
 //   modelTransform->addChild(emitter);
 //   modelTransform->addChild(mNode);
 //   //mPat->addChild(modelTransform);

	// // Create a modular program and attach it to our particle system
	//osg::ref_ptr< osgParticle::ModularProgram > moveDustInAir = new osgParticle::ModularProgram;
 //   moveDustInAir->setParticleSystem( dustParticleSystem );

 //   // Create an operator that simulates gravity, adjust it and add it to our program
 //   osgParticle::AccelOperator *accelUp = new osgParticle::AccelOperator;
 //   accelUp->setToGravity(-1); // scale factor for normal acceleration due to gravity. 
 //   moveDustInAir->addOperator( accelUp );

 //   // Add an operator to our program to calculate the friction of air.
 //   osgParticle::FluidFrictionOperator *airFriction = new osgParticle::FluidFrictionOperator;
 //   airFriction->setFluidToAir();

 //   airFriction->setFluidDensity(1.2929/*air*/*2.0f);
 //   moveDustInAir->addOperator(airFriction);

 //   // Finally, add the program to the scene 
 //   mPat->addChild(moveDustInAir);

}

void Enemy::unfluxCapacitor()
{
	// PSystem
	/*mPat->removeChild( geode );
	mPat->removeChild( dustSystemUpdater );
	mPat->removeChild( modelTransform );
	mPat->removeChild( moveDustInAir );*/
}