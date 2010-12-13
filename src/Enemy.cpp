#include "Enemy.h"
#include <cstring>

Enemy::Enemy( const char* file, const char* file2, const char* name, double spawnTime, float speed, bool hasSpawned, bool isMoving )
: BasicModel( file, name ), speed( speed ), spawnTime( spawnTime ), hasSpawned( false )
{
	mNodeXplode = osgDB::readNodeFile( file2 );
	if( mNode )
	{
		mNodeXplode->setName( name );
		mState = mNodeXplode->getOrCreateStateSet();
		// mPat->addChild( mNodeXplode.get() );
	}

	if( !strcmp( mNode->getName().c_str(), "buitre" ) )
	{
		mPat->setUpdateCallback( new EnemyController( 1.0f, osg::Vec3f( -10.0f, 0.0f, 0.0f ), "buitre" ) );
		cout << "AI cargada para " << mNode->getName() << endl;
	}

	if( !strcmp( mNode->getName().c_str(), "cerdito" ) )
	{
		mPat->setUpdateCallback( new EnemyController( 1.0f, osg::Vec3f( -10.0f, 0.0f, 0.0f ), "cerdito" ) );
		cout << "AI cargada para " << mNode->getName() << endl;
	}

	if( !strcmp( mNode->getName().c_str(), "conejo" ) )
	{
		mPat->setUpdateCallback( new EnemyController( 1.0f, osg::Vec3f( -20.0f, 0.0f, 0.0f ), "conejo" ) );
		cout << "AI cargada para " << mNode->getName() << endl;
	}
	
}

Enemy::~Enemy()
{
}
