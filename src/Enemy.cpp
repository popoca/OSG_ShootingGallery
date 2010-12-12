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
	cout << "Cargando modelo: " << file2 << endl;

	if( !strcmp( name, "buitre" ) )
	{
		mPat->setUpdateCallback( new EnemyController( 1.0f ) );
		cout << "AI cargada para " << name << endl;
	}
}

Enemy::~Enemy()
{
}

void Enemy::loadIA()
{

}
