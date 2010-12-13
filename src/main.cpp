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
	//osgGA::TrackballManipulator* tb = new osgGA::TrackballManipulator;
	//viewer.setCameraManipulator( tb );
	osg::Vec3 *eye = new osg::Vec3f(16.1683,-898.822,121.376);
	osg::Vec3 *center = new osg::Vec3f(16.1782,-897.822,121.368);
	osg::Vec3 *up = new osg::Vec3f(-0.0170962,0.00822059,0.99982);
	viewer.getCamera()->setViewMatrixAsLookAt(*eye, *center, *up);

	viewer.setSceneData( myGS->getRootNode().get());
	viewer.addEventHandler(myGS->myIH->getKeyboardHandler());
	viewer.addEventHandler(myGS->myIH->myPKH);
	
	/* Realize the viewer */
    viewer.realize();

	// Inicializa old_tick
	old_tick = osg::Timer::instance()->getStartTick();
	
	/* Para obtener las coords de la camara */
//	osg::Vec3f center, eye, up;

    while( !viewer.done() )
    {

		/* tick, tick, tick... */
		new_tick = osg::Timer::instance()->tick();
        delta = osg::Timer::instance()->delta_s( old_tick, new_tick );

//		viewer.getCamera()->getViewMatrixAsLookAt( eye, center, up );

		/*cout << "Camera pos: " << eye.x() << ", " <<
			eye.y() << ", " <<
			eye.z() << ", " << center.x() << ", " <<
			center.y() << ", " <<
			center.z() << ", " << up.x() << ", " <<
			up.y() << ", " <<
			up.z() << endl;*/

		myGS->update( delta );

		/* frame */
        viewer.frame();

		/* Actualizacion del tick */
		old_tick = new_tick;
    }

    return 0;
}
