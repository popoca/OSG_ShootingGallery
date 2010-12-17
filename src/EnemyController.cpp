#include "EnemyController.h"
#define Pi 3.1416

using namespace std;

EnemyController::EnemyController( float delta, osg::Vec3f pos, const char* name )
: accAngle( 0.0f ), x( 0.0f ), y( 0.0f ), reverse( false ), delta( delta ), pos( pos ), name( name )
{
}

EnemyController::~EnemyController()
{
}

void EnemyController::operator()( osg::Node* node, osg::NodeVisitor* nv )
{
	osg::ref_ptr< osg::PositionAttitudeTransform > tData = dynamic_cast<osg::PositionAttitudeTransform*> (node);

	/* AI para el conejo */
	if(tData != NULL )
    {
		if( !strcmp( name.c_str(), "conejo" ) ) /* si el nodo es un conejo */
		{
			if( !reverse )
			{
				if( accAngle < 3.1416f )
				{
					if( x > 0.0f )
					{
						tData->setPosition(osg::Vec3f( -50.0f + x, 0.0f, 10.0f ));
						x -= ( 2.0f * (float)delta );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle += ( 1.0f * (float)delta);
					 }
				}
				else
				{
					reverse = true;
				}
			 }
			 else
			 {
				if( accAngle > 0.0f )
				{
					if( x < 500.0f )
					 {
						tData->setPosition(osg::Vec3f( -50.0f + x, 0.0f, 10.0f ));
						x += ( 2.0f * (float)delta );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle -= ( 1.0f * (float)delta );
					 }
				}
				else
					reverse = false;
			 }
		}

		if( !strcmp( name.c_str(), "conejo2" ) ) /* si el nodo es un conejo */
		{
			if( !reverse )
			{
				if( accAngle < 3.1416f )
				{
					if( x > 0.0f )
					{
						tData->setPosition(osg::Vec3f( -50.0f + x, 300.0f, 10.0f ));
						x -= ( 2.0f * (float)delta );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle += ( 1.0f * (float)delta);
					 }
				}
				else
				{
					reverse = true;
				}
			 }
			 else
			 {
				if( accAngle > 0.0f )
				{
					if( x < 500.0f )
					 {
						tData->setPosition(osg::Vec3f( -50.0f + x, 300.0f, 10.0f ));
						x += ( 2.0f * (float)delta );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle -= ( 1.0f * (float)delta );
					 }
				}
				else
					reverse = false;
			 }
		}
		if( !strcmp( name.c_str(), "cerdito" ) ) /* si el nodo es un cerdito */
		{
			if( !reverse )
			{
				if( accAngle < 3.1416f )
				{
					if( x > 0.0f )
					{
						tData->setPosition(osg::Vec3f( -50.0f + x, 0.0f, 10.0f ));
						x -= ( 2.0f * (float)delta );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle += ( 1.0f * (float)delta);
					 }
				}
				else
				{
					reverse = true;
				}
			 }
			 else
			 {
				if( accAngle > 0.0f )
				{
					if( x < 160.0f )
					 {
						tData->setPosition(osg::Vec3f( -50.0f + x, 0.0f, 10.0f ));
						x += ( 2.0f * (float)delta );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle -= ( 1.0f * (float)delta );
					 }
				}
				else
					reverse = false;
			 }
		}
		if( !strcmp( name.c_str(), "cerdito2" ) ) /* si el nodo es un cerdito */
		{
			if( !reverse )
			{
				if( accAngle < 3.1416f )
				{
					if( x > 0.0f )
					{
						tData->setPosition(osg::Vec3f( -50.0f + x, 300.0f, 10.0f ));
						x -= ( 2.0f * (float)delta );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle += ( 1.0f * (float)delta);
					 }
				}
				else
				{
					reverse = true;
				}
			 }
			 else
			 {
				if( accAngle > 0.0f )
				{
					if( x < 160.0f )
					 {
						tData->setPosition(osg::Vec3f( -50.0f + x, 0.0f, 10.0f ));
						x += ( 2.0f * (float)delta );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 300.0f, 1.0f)) );
						accAngle -= ( 1.0f * (float)delta );
					 }
				}
				else
					reverse = false;
			 }
		}
		if( !strcmp( name.c_str(), "buitre" ) ) /* si el nodo es un buitre */
		{
			if( !reverse )
			{
				if( accAngle < 3.1416f )
				{
					if( x > 0.0f )
					{
						tData->setPosition(osg::Vec3f( -400.0f + x, 0.0f, 190.0f + y * 100.0f * (float) delta ));
						x -= ( 2.0f * (float)delta );
						y = sinf( x * ( Pi / 180.0f ) );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle += ( 1.0f * (float)delta);
					 }
				}
				else
				{
					reverse = true;
				}
			 }
			 else
			 {
				if( accAngle > 0.0f )
				{
					if( x < 900.0f )
					 {
						tData->setPosition(osg::Vec3f( -400.0f + x, 0.0f, 190.0f + y * 100.0f * (float) delta ));
						x += ( 2.0f * (float)delta );
						y = sinf( x * ( Pi / 180.0f ) );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle -= ( 1.0f * (float)delta );
					 }
				}
				else
					reverse = false;
			 }
		}

		if( !strcmp( name.c_str(), "buitre2" ) ) /* si el nodo es un buitre */
		{
			if( !reverse )
			{
				if( accAngle < 3.1416f )
				{
					if( x > 0.0f )
					{
						tData->setPosition(osg::Vec3f( -400.0f + x, 500.0f, 190.0f + y * 100.0f * (float) delta ));
						x -= ( 2.0f * (float)delta );
						y = sinf( x * ( Pi / 180.0f ) );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle += ( 1.0f * (float)delta);
					 }
				}
				else
				{
					reverse = true;
				}
			 }
			 else
			 {
				if( accAngle > 0.0f )
				{
					if( x < 900.0f )
					 {
						tData->setPosition(osg::Vec3f( -400.0f + x, 500.0f, 190.0f + y * 100.0f * (float) delta ));
						x += ( 2.0f * (float)delta );
						y = sinf( x * ( Pi / 180.0f ) );
					 }
					 else
					 {
						tData->setAttitude( osg::Quat(accAngle, osg::Vec3( 0.0f, 0.0f, 1.0f)) );
						accAngle -= ( 1.0f * (float)delta );
					 }
				}
				else
					reverse = false;
			 }
		}
		
	}
      traverse(node, nv); 

}
