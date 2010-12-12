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
#include <osg/ShapeDrawable>
#include <string>
#include <vector>
#include "ModelManager.h"

//#include "MouseEventHandler.h"

int main( int argc, char** argv )
{
	/* Timer */
	static osg::Timer_t old_tick, new_tick; 
	static double delta;

	/* Initialize viewer */
	osgViewer::Viewer *viewer = new osgViewer::Viewer();
	osg::ref_ptr< osg::Group > root = new osg::Group();
	/* Una prueba del manejador de modelos */
	ModelManager mm( root );

	// ----------------Carga de los modelos-----------------------------
	// Grupo 1 ---- sin shader
	// Grupo 2 ---- difuso, transparencia y ambient occlusion
	// Grupo 3 ---- difuso, normal, ambient occlusion y detalle
	// Grupo 4 ---- difuso, normal y ambient occlusion
	//------------------------------------------------------------------

	// grupo 1
	mm.bg.push_back( new BasicModel( "../content/bg/sin_shader/sin_shader.osg", "casa" ) );
	mm.bg.push_back( new BasicModel( "../content/npcs/cielo/cielo.osg", "cielo" ) );
	mm.bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/pasto.osg", "pasto" ) );
	mm.bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/relleno.osg", "relleno" ) );
	mm.bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/zona_obstaculos_1.osg", "obstaculo" ) );
	mm.bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/zona_obstaculos_2.osg", "obstaculo" ) );
	mm.bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/zona_obstaculos_3.osg", "obstaculo" ) );

	mm.bg.push_back( new BasicModel( "../content/bg/shader_dif_normal_ao_detail/shader_dif_normal_ao_detail.osg", "ao_detail" ) );
	mm.bg.push_back( new BasicModel( "../content/bg/shader_dif_normal_ao/shader_dif_normal_ao.osg", "ao" ) );
	mm.setUpScene();

	// Creacion y configuracion de la luz
	osg::Light* myLight = new osg::Light;
    myLight->setLightNum(0);
	myLight->setPosition(osg::Vec4(0.0,0.0,90.0,1.0));
    myLight->setAmbient(osg::Vec4(1.0f,1.0f,1.0f,1.0f));
    myLight->setDiffuse(osg::Vec4(1.0f,1.0f,1.0f,1.0f));
	myLight->setSpecular(osg::Vec4(1.0f,1.0f,1.0f,1.0f));
	myLight->setDirection(osg::Vec3(0.0,0.0,-1.0));
    myLight->setConstantAttenuation(1.0f);
    myLight->setLinearAttenuation(2.0f/80.0f);
    myLight->setQuadraticAttenuation(2.0f/osg::square(80.0f));

    osg::LightSource* lightS = new osg::LightSource;    
    lightS->setLight(myLight);
    lightS->setLocalStateSetModes(osg::StateAttribute::ON); 

    lightS->setStateSetModes(*root->getOrCreateStateSet(),osg::StateAttribute::ON);

	//Dibujamos una esfera para la luz
	osg::PositionAttitudeTransform *sphere = new osg::PositionAttitudeTransform();
	osg::Sphere *mSphr = new osg::Sphere(osg::Vec3(0.0, 0.0, 0.0), 5.0f);
	osg::ShapeDrawable *sphD = new osg::ShapeDrawable(mSphr);
	osg::Geode *geoSphr = new osg::Geode();
	geoSphr->addDrawable(sphD);
	sphere->addChild(geoSphr);
	root->addChild(lightS);
	root->addChild(sphere);
	sphere->setPosition(osg::Vec3(myLight->getPosition().x(), myLight->getPosition().y(), myLight->getPosition().z()));
	
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

	/* Realize the viewer */
    viewer->realize();

	// Inicializa old_tick
	old_tick = osg::Timer::instance()->getStartTick();

    while( !viewer->done() )
    {

		/* tick, tick, tick... */
		new_tick = osg::Timer::instance()->tick();
        delta = osg::Timer::instance()->delta_s( old_tick, new_tick );

		/* frame */
        viewer->frame();

		/* Actualizacion del tick */
		old_tick = new_tick;
    }

    return 0;
}