#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>
#include "MouseEventHandler.h"

int main( int argc, char** argv )
{

	/* Timer */
	static osg::Timer_t old_tick, new_tick; 
	static double delta;

	/* Initialize viewer */
    osgViewer::Viewer viewer;

	// Rest of the code goes here

	/* Realize the viewer */
    viewer.realize();

    while( !viewer.done() )
    {

		/* tick, tick, tick... */
		new_tick = osg::Timer::instance()->tick();
        delta = osg::Timer::instance()->delta_s( old_tick, new_tick );

		/* frame */
        viewer.frame();

		/* Actualizacion del tick */
		old_tick = new_tick;
    }

    return 0;
}