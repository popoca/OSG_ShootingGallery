#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>
#include <osg/CullFace>
#include <osg/Depth>
#include <osg/MatrixTransform>
#include "MouseEventHandler.h"

int main( int argc, char** argv )
{

	/* Timer */
	static osg::Timer_t old_tick, new_tick; 
	static double delta;

	/* Initialize viewer */


        // Construye el visualizador.
	osgViewer::Viewer *viewer = new osgViewer::Viewer();
	osg::Group *root = new osg::Group();

	// ----------------Carga de los modelos------------------------
	// Grupo 1 ---- sin shader
	// Grupo 2 ---- difuso, transparencia y ambient occlusion
	//-------------------------------------------------------------
	osg::PositionAttitudeTransform *modelXForm = new osg::PositionAttitudeTransform();
	osg::PositionAttitudeTransform *modelXForm2 = new osg::PositionAttitudeTransform();
	osg::Group *auxGroup1 = new osg::Group();
	osg::Group *auxGroup2 = new osg::Group();
	osg::Node *modelNode = osgDB::readNodeFile("sin_shader.osg");
	osg::Node *modelNode2 = osgDB::readNodeFile("pasto.osg");
	auxGroup1->addChild(modelNode);
	auxGroup2->addChild(modelNode2);

	// Construccion del grafo de escena
	modelXForm->addChild(auxGroup1);
	modelXForm2->addChild(auxGroup2);
	root->addChild(modelXForm);
	root->addChild(modelXForm2);

	// Estado de auxGroups
	osg::StateSet *modelState = auxGroup1->getOrCreateStateSet();
	osg::StateSet *modelState2 = auxGroup2->getOrCreateStateSet();

	// Se activa la prueba de culling para las caras posteriores
	osg::CullFace *cullm1 = new osg::CullFace();
	cullm1->setMode(osg::CullFace::BACK);
	modelState->setAttribute(cullm1);

	osg::CullFace *cullm2 = new osg::CullFace();
	cullm2->setMode(osg::CullFace::BACK);
	modelState2->setAttribute(cullm1);

	//// se Define la funcion de profundidad
	osg::Depth *depthfunc1 = new osg::Depth();
	depthfunc1->setFunction(osg::Depth::LEQUAL);
	modelState->setAttribute(depthfunc1);

	osg::Depth *depthfunc2 = new osg::Depth();
	depthfunc2->setFunction(osg::Depth::LEQUAL);
	modelState2->setAttribute(depthfunc1);
	
	// Estado del nodo raiz
	osg::StateSet *rootState = new osg::StateSet();
	root->setStateSet(rootState);

	osg::Camera *vcam = viewer->getCamera();

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

	osg::Vec3 eye;
	osg::Vec3 center;
	osg::Vec3 up;

	osg::Uniform* camPosition = new osg::Uniform( "camPosition", eye );

	viewer->getCamera()->getViewMatrixAsLookAt(eye, center, up);
	osg::Vec3 eyeVec = eye;
	rootState->addUniform( camPosition );

	viewer->setSceneData( root );

	viewer->setCameraManipulator(new osgGA::TrackballManipulator);
    viewer->realize();

	// Inicializa old_tick
	old_tick = osg::Timer::instance()->getStartTick();

	while(!viewer->done())
	{
		// Actualizacion de delta
		new_tick = osg::Timer::instance()->tick();
        delta = osg::Timer::instance()->delta_s(old_tick, new_tick);

		// Actualizacion de la posicion de la camara
		viewer->getCamera()->getViewMatrixAsLookAt(eye, center, up);
		camPosition->set( osg::Vec3( eye.x(), eye.y(), eye.z() ) );
		//camPosition->set( viewer->getCamera()->getBound().center() ); metodo para obtener las coords sin usar 3 osg::vec3, probar eficiencia

	    viewer->frame();
		old_tick = new_tick;
	}

    return -1;

=======
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
>>>>>>> 8e6af90702fec52e3368c07e5ba61e40f0fb97b8
}