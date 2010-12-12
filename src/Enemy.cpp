#include "Enemy.h"

Enemy::Enemy( const char* file, const char* name )
: BasicModel( file )
{
	mNode->setName( name );
}