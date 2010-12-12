#include "Enemy.h"

Enemy::Enemy( const char* file, const char* name, float speed )
: BasicModel( file, name ), speed( speed )
{
}