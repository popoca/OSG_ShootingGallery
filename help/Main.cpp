#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/CompositeViewer>
#include <osgViewer/Viewer>

#include <osgGA/TrackballManipulator>
#include <osgGA/GUIEventHandler>

#include <osg/io_utils>

#include <osg/Camera>

#include <osg/Timer>

#include "GameSim.h"

static osg::Timer_t old_tick, new_tick; 
static double delta;

int main(int argc, char *argv[])
{

	osg::ref_ptr<GameSim> mgs = new GameSim();


	osgViewer::Viewer viewer;

	 osg::ref_ptr<osg::Camera> vcam = viewer.getCamera();

	//osg::ref_ptr<osg::GraphicsContext::Traits> traits = new
	//osg::GraphicsContext::Traits;
	//traits->x = 30;
	//traits->y = 30;
	//traits->width = 640;
	//traits->height = 480;
	//traits->windowDecoration = true;
	//traits->doubleBuffer = true;
	//traits->sharedContext = 0 ;
	//traits->samples = 0;

     //osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
     //vcam->setGraphicsContext(gc.get());
     //vcam->setViewport(new osg::Viewport(0,0, traits->width,traits->height));


	 osgGA::TrackballManipulator* tb = new osgGA::TrackballManipulator;
	 //tb->setHomePosition( osg::Vec3f(0.f,0.f,20.f), osg::Vec3f(0.f,20.f,20.f), osg::Vec3f(0,0,1) );
	 //vcam->setViewMatrixAsLookAt( osg::Vec3f(130.0f,0.0f,35.0f), osg::Vec3f(0.0f, 0.0f, 5.0f), osg::Vec3f(0,0,1));
     viewer.setCameraManipulator( tb );

	 //vcam->setClearColor(osg::Vec4( 0.0f, 0.0f, 0.0f, 1.0f ));

	 //vcam->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
	 //vcam->setProjectionMatrixAsPerspective(40.0f, 1.3333, 1.0, 10000.0);

	 viewer.setSceneData( mgs->getRootNode().get());

	 viewer.addEventHandler(mgs->getMyInputHandler());

	 viewer.setUpViewInWindow(100,100, 800, 600);
	
     viewer.realize();
    
	

	old_tick = osg::Timer::instance()->getStartTick();

    while(!viewer.done())
    {
		//actualizacion de delta
	    //---------------------2------------------------------
        new_tick = osg::Timer::instance()->tick();
        delta = osg::Timer::instance()->delta_s(old_tick, new_tick);

		if(mgs->startGame())
		{
			mgs->updateD(delta);
			mgs->update();
		}

        viewer.frame();   
		old_tick = new_tick;
    }

	mgs->shutDown();

    return 0;
    
}
