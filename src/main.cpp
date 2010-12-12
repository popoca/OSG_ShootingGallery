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
#include "ModelManager.h"

//#include "MouseEventHandler.h"

int main( int argc, char** argv )
{

	/* Timer */
	static osg::Timer_t old_tick, new_tick; 
	static double delta;

	/* Initialize viewer */
	osgViewer::Viewer *viewer = new osgViewer::Viewer();
	osg::Group *root = new osg::Group();

	// ----------------Carga de los modelos-----------------------------
	// Grupo 1 ---- sin shader
	// Grupo 2 ---- difuso, transparencia y ambient occlusion
	// Grupo 3 ---- difuso, normal, ambient occlusion y detalle
	// Grupo 4 ---- difuso, normal y ambient occlusion
	//------------------------------------------------------------------
	osg::PositionAttitudeTransform *modelXForm = new osg::PositionAttitudeTransform();
	osg::PositionAttitudeTransform *modelXForm2 = new osg::PositionAttitudeTransform();
	osg::PositionAttitudeTransform *modelXForm3 = new osg::PositionAttitudeTransform();
	osg::PositionAttitudeTransform *modelXForm4 = new osg::PositionAttitudeTransform();

	osg::Group *auxGroup1 = new osg::Group();
	osg::Group *auxGroup2 = new osg::Group();
	osg::Group *auxGroup3 = new osg::Group();
	osg::Group *auxGroup4 = new osg::Group();

	// grupo 1
	osg::Node *modelNode = osgDB::readNodeFile("../content/bg/sin_shader/sin_shader.osg");
	osg::Node *modelNode9 = osgDB::readNodeFile("../content/npcs/cielo/cielo.osg");
	// grupo 2
	osg::Node *modelNode2 = osgDB::readNodeFile("../content/bg/shader_dif_transp_ao/pasto.osg");
	osg::Node *modelNode3 = osgDB::readNodeFile("../content/bg/shader_dif_transp_ao/relleno.osg");
	osg::Node *modelNode4 = osgDB::readNodeFile("../content/bg/shader_dif_transp_ao/zona_obstaculos_1.osg");
	osg::Node *modelNode5 = osgDB::readNodeFile("../content/bg/shader_dif_transp_ao/zona_obstaculos_2.osg");
	osg::Node *modelNode6 = osgDB::readNodeFile("../content/bg/shader_dif_transp_ao/zona_obstaculos_3.osg");
	// grupo 3
	osg::Node *modelNode7 = osgDB::readNodeFile("../content/bg/shader_dif_normal_ao_detail/shader_dif_normal_ao_detail.osg");
	// grupo 4
	osg::Node *modelNode8 = osgDB::readNodeFile("../content/bg/shader_dif_normal_ao/shader_dif_normal_ao.osg");

	auxGroup1->addChild(modelNode);
	auxGroup1->addChild(modelNode9);

	auxGroup2->addChild(modelNode2);
	auxGroup2->addChild(modelNode3);
	auxGroup2->addChild(modelNode4);
	auxGroup2->addChild(modelNode5);
	auxGroup2->addChild(modelNode6);

	auxGroup3->addChild(modelNode7);

	auxGroup3->addChild(modelNode8);

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


	// Construccion del grafo de escena
	modelXForm->addChild(auxGroup1);
	modelXForm2->addChild(auxGroup2);
	modelXForm3->addChild(auxGroup3);
	modelXForm4->addChild(auxGroup4);
	root->addChild(modelXForm);
	root->addChild(modelXForm2);
	root->addChild(modelXForm3);
	root->addChild(modelXForm4);

	// Estado de auxGroups
	osg::StateSet *modelState = auxGroup1->getOrCreateStateSet();
	osg::StateSet *modelState2 = auxGroup2->getOrCreateStateSet();
	osg::StateSet *modelState3 = auxGroup2->getOrCreateStateSet();
	osg::StateSet *modelState4 = auxGroup2->getOrCreateStateSet();

	// Se activa la prueba de culling para las caras posteriores
	osg::CullFace *cullm1 = new osg::CullFace();
	cullm1->setMode(osg::CullFace::BACK);
	modelState->setAttribute(cullm1);

	osg::CullFace *cullm2 = new osg::CullFace();
	cullm2->setMode(osg::CullFace::BACK);
	modelState2->setAttribute(cullm2);

	osg::CullFace *cullm3 = new osg::CullFace();
	cullm3->setMode(osg::CullFace::BACK);
	modelState3->setAttribute(cullm3);

	osg::CullFace *cullm4 = new osg::CullFace();
	cullm4->setMode(osg::CullFace::BACK);
	modelState4->setAttribute(cullm4);

	//// se Define la funcion de profundidad
	osg::Depth *depthfunc1 = new osg::Depth();
	depthfunc1->setFunction(osg::Depth::LEQUAL);
	modelState->setAttribute(depthfunc1);

	osg::Depth *depthfunc2 = new osg::Depth();
	depthfunc2->setFunction(osg::Depth::LEQUAL);
	modelState2->setAttribute(depthfunc2);

	osg::Depth *depthfunc3 = new osg::Depth();
	depthfunc3->setFunction(osg::Depth::LEQUAL);
	modelState3->setAttribute(depthfunc3);

	osg::Depth *depthfunc4 = new osg::Depth();
	depthfunc4->setFunction(osg::Depth::LEQUAL);
	modelState4->setAttribute(depthfunc4);
	
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