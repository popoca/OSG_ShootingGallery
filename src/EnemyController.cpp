#include "EnemyController.h"

EnemyController::EnemyController()
{
	accAngle = 0.0f;
	ymov = 0.0f;
	reverse = false;
}

EnemyController::~EnemyController()
{
}

virtual void EnemyController::operator()( osg::Node* node, osg::NodeVisitor* nv )
{
	osg::ref_ptr< osg::Matrix > tData = 
         dynamic_cast<osg::PositionAttitudeTransform*> (node);

      if(tData != NULL)
      {
		 if( !reverse )
		 {
			if( accAngle < 3.1415f )
			{
				if( ymov < 20.0f )
				 {
					tData->setPosition(osg::Vec3f(0.0, ymov, 10.0));
					ymov += ( 2.0 * (float)delta );
				 }
				 else
				 {
					tData->setAttitude(osg::Quat(accAngle, osg::Vec3(0.0f, 0.0f, 1.0f)));
					accAngle += ( 1.0 * (float)delta);
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
				if( ymov > 0.0f )
				 {
					tData->setPosition(osg::Vec3f(0.0, ymov, 10.0));
					ymov -= ( 2.0 * (float)delta );
				 }
				 else
				 {
					tData->setAttitude(osg::Quat(accAngle, osg::Vec3(0.0f, 0.0f, 1.0f)));
					accAngle -= ( 1.0 * (float)delta);
				 }
			}
			else
				reverse = false;
		 }



         /*tData->setPosition(osg::Vec3f(0.0, accAngle, 10.0));
		 tData->setAttitude(osg::Quat(accAngle, osg::Vec3(0.0f, 0.0f, 1.0f)));
         accAngle+=(0.5*(float)delta);*/
      }
      traverse(node, nv); 
}