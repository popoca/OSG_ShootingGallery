#include "Enemy.h"
#include <cstring>

Enemy::Enemy( const char* file, const char* file2, const char* name, float speed, bool hasSpawned, bool isMoving )
: BasicModel( file, name ), speed( speed )
{
	mNodeXplode = osgDB::readNodeFile( file2 );
	if( mNode )
	{
		mNodeXplode->setName( name );
		mState = mNodeXplode->getOrCreateStateSet();
		mPatXplode = new osg::PositionAttitudeTransform();
		mPatXplode->addChild( mNodeXplode.get() );
	}

	if( !strcmp( mNode->getName().c_str(), "buitre" ) )
	{
		mPat->setUpdateCallback( new EnemyController( 1.0f, osg::Vec3f( -10.0f, 0.0f, 0.0f ), "buitre" ) );
		cout << "AI cargada para " << mNode->getName() << endl;
	}
	
}

Enemy::~Enemy()
{
}
