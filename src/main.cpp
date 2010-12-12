#include "WorldSim.h"

#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/CompositeViewer>
#include <osgGA/GUIEventHandler>
#include <osgGA/TrackballManipulator>
#include <osg/Camera>
#include <osg/Timer>
#include <osg/io_utils>
#include <iostream>


//#include "MouseEventHandler.h"

using namespace std;

int main( int argc, char** argv )
{
	/* Timer */
	static osg::Timer_t old_tick, new_tick;
	static double delta;

	/* Needed stuff */
	osg::ref_ptr<osgText::Text> updateText = new osgText::Text;

	/* Initialize viewer */
	osg::ref_ptr<osgViewer::View> view = new osgViewer::View;
	view->setUpViewAcrossAllScreens();
	osg::ref_ptr<WorldSim> myGS = new WorldSim(updateText);
	view->setSceneData(myGS->getRootNode());
	view->setUpViewAcrossAllScreens();
	osgViewer::Viewer viewer;
	osgGA::TrackballManipulator* tb = new osgGA::TrackballManipulator;
	viewer.setCameraManipulator( tb );
	viewer.setSceneData( myGS->getRootNode().get());
	viewer.addEventHandler(myGS->myIH->getKeyboardHandler());
	viewer.addEventHandler(myGS->myIH->myPKH);
	
	/* Realize the viewer */
    viewer.realize();

	// Inicializa old_tick
	old_tick = osg::Timer::instance()->getStartTick();
	
	/* Para obtener las coords de la camara */
	osg::Vec3f center, eye, up;

    while( !viewer.done() )
    {

		/* tick, tick, tick... */
		new_tick = osg::Timer::instance()->tick();
        delta = osg::Timer::instance()->delta_s( old_tick, new_tick );

		viewer.getCamera()->getViewMatrixAsLookAt( eye, center, up );

		cout << "Camera pos: " << center.x() << ", " <<
			center.y() << ", " <<
			center.z() << endl;

		/* frame */
        viewer.frame();

		/* Actualizacion del tick */
		old_tick = new_tick;
    }

    return 0;
}
