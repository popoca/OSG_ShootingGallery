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

WorldSim::WorldSim(osg::ref_ptr<osgText::Text> _updateText, osg::ref_ptr< osgViewer::View > view )
: currState( Start ), hasLoaded( false )
{
	start = false;

	root = new osg::Group;
	myHH = new HUDHandler(root);
	myIH = new InputHandler(_updateText,myHH);
	sHandle = new SoundHandler( root, view );
	pSys = new ParticleSystem( root );
	
	mySH= new ShaderHandler();
	
	myIH->myKBH->getHH(myHH);

	cout << "Iniciando el grafo de escena..." << endl;

	/* Una prueba del manejador de modelos */
	mm = new ModelManager( root );

	mm->bg.push_back( new BasicModel( "../content/bg/sin_shader/sin_shader.osg", "casa" ) );
	mm->bg.push_back( new BasicModel( "../content/npcs/cielo/cielo.osg", "cielo" ) );

	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/pasto.osg", "pasto" ) );
	mySH->transAOShader(mm->bg[2]->mNode);
	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/relleno.osg", "relleno" ) );
	mySH->transAOShader(mm->bg[3]->mNode);
	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/zona_obstaculos_1.osg", "obstaculo" ) );
	mySH->transAOShader(mm->bg[4]->mNode);
	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/zona_obstaculos_2.osg", "obstaculo" ) );
	mySH->transAOShader(mm->bg[5]->mNode);
	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_transp_ao/zona_obstaculos_3.osg", "obstaculo" ) );
	mySH->transAOShader(mm->bg[6]->mNode);

	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_normal_ao_detail/shader_dif_normal_ao_detail.osg", "ao_detail" ) );
	//mySH->difShader(mm->bg[7]->mNode);
	mySH->BumpMappingShader(mm->bg[7]->mNode);
	
	mm->bg.push_back( new BasicModel( "../content/bg/shader_dif_normal_ao/shader_dif_normal_ao.osg", "ao" ) );
	//mySH->difShader(mm->bg[8]->mNode);
	mySH->aoShader(mm->bg[8]->mNode);
	mySH->bumpMap2Shader(mm->bg[8]->mNode);

	/* Inicializa el escenario */
	mm->setUpScene();

	// Creacion y configuracion de la luz
	osg::Light* myLight = new osg::Light;
    myLight->setLightNum(0);
	myLight->setPosition(osg::Vec4(0.0,500.0,4500.0,21.0));
    myLight->setAmbient(osg::Vec4(0.65f,0.75f,0.65f,1.0f));
    myLight->setDiffuse(osg::Vec4(0.75f,0.85f,0.75f,1.0f));
	myLight->setSpecular(osg::Vec4(0.75f,0.75f,0.35f,1.0f));
	myLight->setDirection(osg::Vec3(-1.0,-1.0,-1.0));
    myLight->setConstantAttenuation(9.0f);
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

	/* carga de sonidos */
	sHandle->createAmbientSound( "../content/sounds/ambientacion.wav", "AmbientSound" );
	sHandle->createEventSound( "../content/sounds/disparo.wav", "AmbientSound" );
	sHandle->createEventSound( "../content/sounds/game_over.wav", "AmbientSound" );
	sHandle->createEventSound( "../content/sounds/impacto.wav", "AmbientSound" );
	sHandle->createEventSound( "../content/sounds/level1.wav", "AmbientSound" );
	sHandle->createEventSound( "../content/sounds/level2.wav", "AmbientSound" );
	sHandle->createEventSound( "../content/sounds/level3.wav", "AmbientSound" );
	sHandle->createEventSound( "../content/sounds/level4.wav", "AmbientSound" );
	sHandle->createEventSound( "../content/sounds/level5.wav", "AmbientSound" );
	sHandle->createEventSound( "../content/sounds/winner.wav", "AmbientSound" );

}
	
void WorldSim::update( float delta )
{
	myHH->update(delta);
	switch( currState )
	{
	case Start:

		// do stuff
		myHH->showMessage("Get Ready!\nPress any key");
		myHH->showing = true;
		if( myIH->myKBH->enter_pressed )
		{
				myHH->quitMessage();
				myIH->myKBH->enter_pressed = false;
				currState = Level1;
		}

		break;

	case Level1:

		if( !hasLoaded )
		{
			
			mm->en.push_back( new Enemy( 
				"../content/npcs/buitre/buitre.osg", 
				"../content/npcs/buitre/buitre_explosion.osg", 
				"buitre2", 
				0.0, 
				delta, 
				0.4f,
				pSys ) );
			mm->en.push_back( new Enemy( 
				"../content/npcs/cerdo/cerdito.osg", 
				"../content/npcs/cerdo/cerdito_explosion.osg", 
				"cerdito2", 
				10.0, 
				delta, 
				0.1f,
				pSys ) );
			mm->en.push_back( new Enemy( 
				"../content/npcs/conejo/conejo.osg", 
				"../content/npcs/conejo/conejo_explosion.osg", 
				"conejo2", 
				20.0, 
				delta, 
				0.4f,
				pSys ) );

			hasLoaded = true;

		}
		else
			mm->updateScene( delta );

		if( mm->end )
		{
			mm->en.clear();
			hasLoaded = false;
			myHH->showMessage("Level Cleared!\nPress any key!");
			myHH->showing = true;
			if( myIH->myKBH->enter_pressed )
			{
					myHH->quitMessage();
					myIH->myKBH->enter_pressed = false;
					mm->end = false;
					currState = Level2;
			}
		}

		break;

	case Level2:

		if( !hasLoaded )
		{

			mm->end = false;
			
			mm->en.push_back( new Enemy( "../content/npcs/buitre/buitre.osg", "../content/npcs/buitre/buitre_explosion.osg", "buitre", 0.0, delta, 0.6f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/cerdo/cerdito.osg", "../content/npcs/cerdo/cerdito_explosion.osg", "cerdito", 5.0, delta, 0.3f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/conejo/conejo.osg", "../content/npcs/conejo/conejo_explosion.osg", "conejo", 10.0, delta, 0.6f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/buitre/buitre.osg", "../content/npcs/buitre/buitre_explosion.osg", "buitre", 15.0, delta, 0.6f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/cerdo/cerdito.osg", "../content/npcs/cerdo/cerdito_explosion.osg", "cerdito", 20.0, delta, 0.3f, pSys ) );

			hasLoaded = true;

		}
		else
			mm->updateScene( delta );

		if( mm->end )
		{
			mm->en.clear();
			hasLoaded = false;
			myHH->showMessage("Level Cleared!\nPress any key!");
			myHH->showing = true;
			if( myIH->myKBH->enter_pressed )
			{
					myHH->quitMessage();
					myIH->myKBH->enter_pressed = false;
					mm->end = false;
					currState = Level3;
			}
		}

		break;

	case Level3:

		if( !hasLoaded )
		{

			mm->end = false;
			
			mm->en.push_back( new Enemy( "../content/npcs/buitre/buitre.osg", "../content/npcs/buitre/buitre_explosion.osg", "buitre", 0.0, delta, 0.8f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/cerdo/cerdito.osg", "../content/npcs/cerdo/cerdito_explosion.osg", "cerdito", 5.0, delta, 0.5f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/conejo/conejo.osg", "../content/npcs/conejo/conejo_explosion.osg", "conejo", 10.0, delta, 0.8f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/buitre/buitre.osg", "../content/npcs/buitre/buitre_explosion.osg", "buitre", 15.0, delta, 0.8f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/cerdo/cerdito.osg", "../content/npcs/cerdo/cerdito_explosion.osg", "cerdito", 20.0, delta, 0.5f, pSys ) );

			hasLoaded = true;

		}
		else
			mm->updateScene( delta );

		if( mm->end )
		{
			mm->en.clear();
			hasLoaded = false;
			myHH->showMessage("Level Cleared!\nPress any key!");
			myHH->showing = true;
			if( myIH->myKBH->enter_pressed )
			{
					myHH->quitMessage();
					myIH->myKBH->enter_pressed = false;
					mm->end = false;
					currState = Level4;
			}
		}

		break;

	case Level4:

		if( !hasLoaded )
		{
			mm->end = false;
			
			mm->en.push_back( new Enemy( "../content/npcs/buitre/buitre.osg", "../content/npcs/buitre/buitre_explosion.osg", "buitre", 0.0, delta, 0.9f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/cerdo/cerdito.osg", "../content/npcs/cerdo/cerdito_explosion.osg", "cerdito", 10.0, delta, 0.6f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/conejo/conejo.osg", "../content/npcs/conejo/conejo_explosion.osg", "conejo", 20.0, delta, 0.9f, pSys ) );

			hasLoaded = true;

		}
		else
			mm->updateScene( delta );

		if( mm->end )
		{
			mm->en.clear();
			hasLoaded = false;
			myHH->showMessage("Level Cleared!\nPress any key!");
			myHH->showing = true;
			if( myIH->myKBH->enter_pressed )
			{
					myHH->quitMessage();
					myIH->myKBH->enter_pressed = false;
					mm->end = false;
					currState = Level5;
			}
		}

		break;

	case Level5:

		if( !hasLoaded )
		{
			mm->end = false;
			
			mm->en.push_back( new Enemy( "../content/npcs/buitre/buitre.osg", "../content/npcs/buitre/buitre_explosion.osg", "buitre", 0.0, delta, 1.0f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/cerdo/cerdito.osg", "../content/npcs/cerdo/cerdito_explosion.osg", "cerdito", 10.0, delta, 0.7f, pSys ) );
			mm->en.push_back( new Enemy( "../content/npcs/conejo/conejo.osg", "../content/npcs/conejo/conejo_explosion.osg", "conejo", 20.0, delta, 1.0f, pSys ) );

			hasLoaded = true;

		}
		else
			mm->updateScene( delta );

		if( mm->end )
		{
			mm->en.clear();
			hasLoaded = false;
			myHH->showMessage("Level Cleared!\nPress any key!");
			myHH->showing = true;
			if( myIH->myKBH->enter_pressed )
			{
					myHH->quitMessage();
					myIH->myKBH->enter_pressed = false;
					mm->end = false;
					currState = GameOver;
			}
		}

		break;

	case GameOver:

		myHH->showMessage("Congratulations!\nPress any key");
		myHH->showing = true;
		if( myIH->myKBH->enter_pressed )
		{
			mm->en.clear();
			myHH->quitMessage();
			myIH->myKBH->enter_pressed = false;
			mm->end = false;
			currState = Level1;
		}

		break;
	}
}
