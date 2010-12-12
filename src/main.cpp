#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/CompositeViewer>
#include <osgGA/GUIEventHandler>
#include <osgGA/TrackballManipulator>
#include <osg/Camera>
#include <osg/Timer>
#include <osg/io_utils>

#include "WorldSim.h"

//#include "MouseEventHandler.h"

int main( int argc, char** argv )
{
	/* Timer */
	static osg::Timer_t old_tick, new_tick;
	static double delta;

	/* Initialize viewer */
	osg::ref_ptr<WorldSim> myGS = new WorldSim();
	osgViewer::Viewer viewer;
	osg::ref_ptr<osg::Camera> vcam = viewer.getCamera();
	

	// Configuracion de los rasgos del contexto grafico
	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
    traits->x = 200;
    traits->y = 200;
    traits->width = 600;
    traits->height = 600;
    traits->windowDecoration = true;
	traits->supportsResize = true;
	traits->doubleBuffer = true;
    traits->sharedContext = 0;
    traits->sampleBuffers = true;
	traits->samples=8;

    osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
    vcam->setGraphicsContext(gc.get());
    vcam->setViewport(new osg::Viewport(0,0, traits->width,traits->height));
	vcam->setProjectionMatrixAsPerspective(60.0f, 1.0f, 1.0f, 500.0f);

	viewer.addEventHandler( myGS->myIH->myKBH );
	viewer.addEventHandler( myGS->myIH->myMSH );
	osgGA::TrackballManipulator* tb = new osgGA::TrackballManipulator;
	viewer.setCameraManipulator( tb );
	viewer.setSceneData( myGS->getRootNode().get() );


	/* Realize the viewer */
    viewer.realize();

	// Inicializa old_tick
	old_tick = osg::Timer::instance()->getStartTick();

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
