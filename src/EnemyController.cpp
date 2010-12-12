#include "EnemyController.h"

EnemyController::EnemyController( float delta )
: accAngle( 0.0f ), x( 0.0f ), reverse( false ), delta( delta )
{
}

EnemyController::~EnemyController()
{
}

void EnemyController::operator()( osg::Node* node, osg::NodeVisitor* nv )
{
	osg::ref_ptr< osg::PositionAttitudeTransform > tData = dynamic_cast<osg::PositionAttitudeTransform*> (node);

	if(tData != NULL)
    {
		if( !reverse )
		{
			if( accAngle < 3.1415f )
			{
				if( x > 0.0f )
				{
					tData->setPosition(osg::Vec3f( x, 0.0f, 10.0f ));
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
					tData->setPosition(osg::Vec3f( x, 0.0f, 10.0f ));
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
      traverse(node, nv); 
}
