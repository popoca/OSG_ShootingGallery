#include <osg/AlphaFunc>
#include <osg/ShapeDrawable>
#include <osg/PositionAttitudeTransform>
#include <osg/Geode>
#include <osg/Node>
#include <osg/ShapeDrawable>
#include <osgDB/ReadFile>
#include <osg/LightSource>
#include <osgUtil/Optimizer>
#include <osg/FrontFace>
#include <iostream>

#include "WorldSim.h"

WorldSim::WorldSim(osg::ref_ptr<osgText::Text> _updateText)
: currState( Start ), hasLoaded( false )
{
	start = false;

	root = new osg::Group;
	myIH = new InputHandler(_updateText);

	mySH= new ShaderHandler();
	
	cout << "Iniciando el grafo de escena..." << endl;

	/* Una prueba del manejador de modelos */
	mm = new ModelManager( root );

	mm->bg.push_back( new BasicModel( "../content/bg/sin_shader/sin_shader.osg", "casa" ) );
	mm->bg.push_back( new BasicModel( "../content/npcs/cielo/cielo.osg", "cielo" ) );
	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/pasto.osg", "pasto" ) );
	//mySH->aOShader(mm->bg[2]->mNode);
	mySH->transpShader(mm->bg[2]->mNode);

	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/relleno.osg", "relleno" ) );
	mySH->transpShader(mm->bg[3]->mNode);
	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/zona_obstaculos_1.osg", "obstaculo" ) );
	mySH->transpShader(mm->bg[4]->mNode);
	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/zona_obstaculos_2.osg", "obstaculo" ) );
	mySH->transpShader(mm->bg[5]->mNode);
	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/zona_obstaculos_3.osg", "obstaculo" ) );
	mySH->transpShader(mm->bg[6]->mNode);

	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_normal_ao_detail/shader_dif_normal_ao_detail.osg", "ao_detail" ) );
	mySH->illuShader(mm->bg[7]->mNode);
	mySH->BumpMappingShader(mm->bg[7]->mNode);

	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_normal_ao/shader_dif_normal_ao.osg", "ao" ) );
	mySH->illuShader2(mm->bg[8]->mNode);
	mySH->BumpMappingShader(mm->bg[8]->mNode);

	/* Inicializa el escenario */
	mm->setUpScene();

	// Creacion y configuracion de la luz
	osg::Light* myLight = new osg::Light;
    myLight->setLightNum(0);
	myLight->setPosition(osg::Vec4(0.0,0.0,1500.0,1.0));
    myLight->setAmbient(osg::Vec4(0.75f,0.75f,0.75f,1.0f));
    myLight->setDiffuse(osg::Vec4(0.75f,0.75f,0.75f,1.0f));
	myLight->setSpecular(osg::Vec4(0.75f,0.75f,0.75f,1.0f));
	myLight->setDirection(osg::Vec3(-1.0,-1.0,-1.0));
    myLight->setConstantAttenuation(1.0f);
    myLight->setLinearAttenuation(2.0f/100.0f);
    myLight->setQuadraticAttenuation(2.0f/osg::square(100.0f));

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

}
	
void WorldSim::update( float delta )
{
	switch( currState )
	{
	case Start:

		// do stuff

		//break;

	case Level1:

		if( !hasLoaded )
		{
			
			mm->en.push_back( new Enemy( "../content/npcs/buitre/buitre.osg", "../content/npcs/buitre/buitre_explosion.osg", "buitre", 0.0, 1.0f ) );
			mm->en.push_back( new Enemy( "../content/npcs/buitre/buitre.osg", "../content/npcs/buitre/buitre_explosion.osg", "buitre", 20.0, 1.0f ) );
			mm->en.push_back( new Enemy( "../content/npcs/buitre/buitre.osg", "../content/npcs/buitre/buitre_explosion.osg", "buitre", 50.0, 1.0f ) );

			hasLoaded = true;

		}
		else
			mm->updateScene( delta );

		break;

	case Level2:
		break;

	case Level3:
		break;

	case Level4:
		break;

	case Level5:
		break;

	case GameOver:
		break;
	}
}