#include "Enemy.h"

Enemy::Enemy( const char* file, const char* name, float speed, bool hasSpawned = false, bool isMoving = false )
: BasicModel( file, name ), speed( speed , hasSpawned( hasSpawned ), isMoving( isMoving )
{
}

Enemy::~Enemy()
{
}

