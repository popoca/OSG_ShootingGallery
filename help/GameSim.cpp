#include "GameSim.h"

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


GameSim::GameSim()
{
	 start = false;

	 root = new osg::Group;
	 scene = new osg::Group;

     root->addChild( scene );

	 msh = new ShaderHandler();
	 mSoundHandler = new SoundHandler(root);
	 mAnimHandler = new AnimationHandler();
	 myIH = new InputHandler();

	 playerModel = mAnimHandler->createPlayerModel("pollo_animado/pollito.cfg");


	 alturaBases = 0.0f;

	 //time = 0;

	 timeAux1 = 0;
	 timeAux2 = 0;


	 subir = false;
	 bajar = false;
	 arriba = true;
	 abajo = false;



	osg::Light* myLight = new osg::Light;
    myLight->setLightNum(0);
    myLight->setPosition(osg::Vec4(0.0f, 0.0f, 40.0f, 0.0f));
    myLight->setAmbient(osg::Vec4(1.0f,1.0f,1.0f,1.0f));
    myLight->setDiffuse(osg::Vec4(1.0f,1.0f,1.0f,1.0f));
	myLight->setSpecular(osg::Vec4(0.8f,0.8f,0.8f,1.0f));
	myLight->setDirection(osg::Vec3(0.0,0.0,-1.0));
    myLight->setConstantAttenuation(1.0f);
    myLight->setLinearAttenuation(2.0f/70.0f);
    myLight->setQuadraticAttenuation(2.0f/osg::square(70.0f));

    osg::LightSource* lightS = new osg::LightSource;    
    lightS->setLight(myLight);
    lightS->setLocalStateSetModes(osg::StateAttribute::ON);

	lightS->setStateSetModes(*root->getOrCreateStateSet(),osg::StateAttribute::ON);
	root->addChild(lightS);

	mBotonSound = mSoundHandler->createBotonSound("sounds/boton_presionado.wav", "SoundState1");
	//mAmbientSound = mSoundHandler->createAmbientSound("sounds/ambiente.wav", "SoundState2");
	//root->addChild(mAmbientSound.get());
	

	//Esfera para la luz
	osg::PositionAttitudeTransform *sphere = new osg::PositionAttitudeTransform();
	osg::Sphere *mSphr = new osg::Sphere(osg::Vec3(0.0, 0.0, 0.0), 4.0f);
	osg::ShapeDrawable *sphrD = new osg::ShapeDrawable(mSphr);
	osg::Geode *geodeSphr = new osg::Geode();
	geodeSphr->addDrawable(sphrD);
	sphere->addChild(geodeSphr);
	root->addChild(sphere);
	sphere->setPosition(osg::Vec3(myLight->getPosition().x(), myLight->getPosition().y(), myLight->getPosition().z()));


	mt1 = new osg::MatrixTransform();
	rNode1 = osgDB::readNodeFile("models/sin_shader.osg");
	rNode1->getOrCreateStateSet()->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	mt1->addChild(rNode1);
	scene->addChild(mt1);

	//mt2 = new osg::MatrixTransform();
	//rNode2 = osgDB::readNodeFile("models/dif_normal.osg");
	//rNode2->getOrCreateStateSet()->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	////msh->TextureShader(rNode2);
	//mt2->addChild(rNode2);
	//scene->addChild(mt2);

	mt3 = new osg::MatrixTransform();
	rNode3 = osgDB::readNodeFile("models/bases.osg");
	mt3->addChild(rNode3);
	scene->addChild(mt3);
	
	mt4 = new osg::MatrixTransform();
	rNode4 = osgDB::readNodeFile("models/base_pad.osg");
	//msh->TextureShader(rNode4);
	mt4->addChild(rNode4);
	scene->addChild(mt4);

	//mt5 = new osg::MatrixTransform();
	//rNode5 = osgDB::readNodeFile("models/dif_normal_spec.osg");
	//rNode5->getOrCreateStateSet()->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	////msh->TextureShader(rNode5);
	//mt5->addChild(rNode5);
	//scene->addChild(mt5);

	mt6 = new osg::MatrixTransform();
	rNode6 = osgDB::readNodeFile("models/1.osg");
	//msh->TextureShader(rNode6);
	mt6->addChild(rNode6);
	scene->addChild(mt6);
	mt6->addChild(mBotonSound.get());

	mt7 = new osg::MatrixTransform();
	rNode7= osgDB::readNodeFile("models/2.osg");
	//msh->TextureShader(rNode7);
	mt7->addChild(rNode7);
	scene->addChild(mt7);
	mt7->addChild(mBotonSound.get());

	mt8 = new osg::MatrixTransform();
	rNode8 = osgDB::readNodeFile("models/3.osg");
	//msh->TextureShader(rNode8);
	mt8->addChild(rNode8);
	scene->addChild(mt8);
	mt8->addChild(mBotonSound.get());

	mt9 = new osg::MatrixTransform();
	rNode9 = osgDB::readNodeFile("models/4.osg");
	//msh->TextureShader(rNode9);
	mt9->addChild(rNode9);
	scene->addChild(mt9);
	mt9->addChild(mBotonSound.get());

	mt10 = new osg::MatrixTransform();
	rNode10 = osgDB::readNodeFile("models/5.osg");
	//msh->TextureShader(rNode10);
	mt10->addChild(rNode10);
	scene->addChild(mt10);
	mt10->addChild(mBotonSound.get());

	mt11 = new osg::MatrixTransform();
	rNode11 = osgDB::readNodeFile("models/6.osg");
	//msh->TextureShader(rNode11);
	mt11->addChild(rNode11);
	scene->addChild(mt11);
	mt11->addChild(mBotonSound.get());

	mt12 = new osg::MatrixTransform();
	rNode12 = osgDB::readNodeFile("models/7.osg");
	//msh->TextureShader(rNode12);
	mt12->addChild(rNode12);
	scene->addChild(mt12);
	mt12->addChild(mBotonSound.get());

	mt13 = new osg::MatrixTransform();
	rNode13 = osgDB::readNodeFile("models/8.osg");
	//msh->TextureShader(rNode13);
	mt13->addChild(rNode13);
	scene->addChild(mt13);
	mt13->addChild(mBotonSound.get());

	mt14 = new osg::MatrixTransform();
	rNode14 = osgDB::readNodeFile("models/9.osg");
	//msh->TextureShader(rNode14);
	mt14->addChild(rNode14);
	scene->addChild(mt14);
	mt14->addChild(mBotonSound.get());


	mt15 = new osg::MatrixTransform();
	rNode15 = osgDB::readNodeFile("models/eje_1.osg");
	mt15->addChild(rNode15);
	scene->addChild(mt15);

	rNode16 = osgDB::readNodeFile("models/eje_1_cuchilla_1.osg");
	mt15->addChild(rNode16);
	
	rNode17 = osgDB::readNodeFile("models/eje_1_cuchilla_2.osg");
	mt15->addChild(rNode17);

	rNode18 = osgDB::readNodeFile("models/eje_1_cuchilla_3.osg");
	mt15->addChild(rNode18);

	rNode19 = osgDB::readNodeFile("models/eje_1_cuchilla_4.osg");
	mt15->addChild(rNode19);

	centro1 = osg::Vec3(mt15->getChild(0)->getBound().center());


	mt16 = new osg::MatrixTransform();
	rNode20 = osgDB::readNodeFile("models/eje_2.osg");
	mt16->addChild(rNode20);
	scene->addChild(mt16);

	rNode21 = osgDB::readNodeFile("models/eje_2_cuchilla_1.osg");
	mt16->addChild(rNode21);
	
	rNode22 = osgDB::readNodeFile("models/eje_2_cuchilla_2.osg");
	mt16->addChild(rNode22);

	rNode23 = osgDB::readNodeFile("models/eje_2_cuchilla_3.osg");
	mt16->addChild(rNode23);

	rNode24 = osgDB::readNodeFile("models/eje_2_cuchilla_4.osg");
	mt16->addChild(rNode24);

	centro2 = osg::Vec3(mt16->getChild(0)->getBound().center());


	mt17 = new osg::MatrixTransform();
	rNode25 = osgDB::readNodeFile("models/eje_3.osg");
	mt17->addChild(rNode25);
	scene->addChild(mt17);

	rNode26 = osgDB::readNodeFile("models/eje_3_cuchilla_1.osg");
	mt17->addChild(rNode26);
	
	rNode27 = osgDB::readNodeFile("models/eje_3_cuchilla_2.osg");
	mt17->addChild(rNode27);

	rNode28 = osgDB::readNodeFile("models/eje_3_cuchilla_3.osg");
	mt17->addChild(rNode28);

	rNode29 = osgDB::readNodeFile("models/eje_3_cuchilla_4.osg");
	mt17->addChild(rNode29);

	centro3 = osg::Vec3(mt17->getChild(0)->getBound().center());


	mt18 = new osg::MatrixTransform();
	rNode30 = osgDB::readNodeFile("models/eje_4.osg");
	mt18->addChild(rNode30);
	scene->addChild(mt18);

	rNode31 = osgDB::readNodeFile("models/eje_4_cuchilla_1.osg");
	mt18->addChild(rNode31);
	
	rNode32 = osgDB::readNodeFile("models/eje_4_cuchilla_2.osg");
	mt18->addChild(rNode32);

	rNode33 = osgDB::readNodeFile("models/eje_4_cuchilla_3.osg");
	mt18->addChild(rNode33);

	rNode34 = osgDB::readNodeFile("models/eje_4_cuchilla_4.osg");
	mt18->addChild(rNode34);

	centro4 = osg::Vec3(mt18->getChild(0)->getBound().center());


	mt19 = new osg::MatrixTransform();
	rNode35 = osgDB::readNodeFile("models/eje_5.osg");
	mt19->addChild(rNode35);
	scene->addChild(mt19);

	rNode36 = osgDB::readNodeFile("models/eje_5_cuchilla_1.osg");
	mt19->addChild(rNode36);
	
	rNode37 = osgDB::readNodeFile("models/eje_5_cuchilla_2.osg");
	mt19->addChild(rNode37);

	rNode38 = osgDB::readNodeFile("models/eje_5_cuchilla_3.osg");
	mt19->addChild(rNode38);

	rNode39 = osgDB::readNodeFile("models/eje_5_cuchilla_4.osg");
	mt19->addChild(rNode39);

	centro5 = osg::Vec3(mt19->getChild(0)->getBound().center());


	mt20 = new osg::MatrixTransform();
	rNode40 = osgDB::readNodeFile("models/eje_6.osg");
	mt20->addChild(rNode40);
	scene->addChild(mt20);

	rNode41 = osgDB::readNodeFile("models/eje_6_cuchilla_1.osg");
	mt20->addChild(rNode41);
	
	rNode42 = osgDB::readNodeFile("models/eje_6_cuchilla_2.osg");
	mt20->addChild(rNode42);

	rNode43 = osgDB::readNodeFile("models/eje_6_cuchilla_3.osg");
	mt20->addChild(rNode43);

	rNode44 = osgDB::readNodeFile("models/eje_6_cuchilla_4.osg");
	mt20->addChild(rNode44);

	centro6 = osg::Vec3(mt20->getChild(0)->getBound().center());


	mt21 = new osg::MatrixTransform();
	rNode45 = osgDB::readNodeFile("models/eje_7.osg");
	mt21->addChild(rNode45);
	scene->addChild(mt21);

	rNode46 = osgDB::readNodeFile("models/eje_7_cuchilla_1.osg");
	mt21->addChild(rNode46);
	
	rNode47 = osgDB::readNodeFile("models/eje_7_cuchilla_2.osg");
	mt21->addChild(rNode47);

	rNode48 = osgDB::readNodeFile("models/eje_7_cuchilla_3.osg");
	mt21->addChild(rNode48);

	rNode49 = osgDB::readNodeFile("models/eje_7_cuchilla_4.osg");
	mt21->addChild(rNode49);

	centro7 = osg::Vec3(mt21->getChild(0)->getBound().center());


	mt22 = new osg::MatrixTransform();
	rNode50 = osgDB::readNodeFile("models/eje_8.osg");
	mt22->addChild(rNode50);
	scene->addChild(mt22);

	rNode51 = osgDB::readNodeFile("models/eje_8_cuchilla_1.osg");
	mt22->addChild(rNode51);
	
	rNode52 = osgDB::readNodeFile("models/eje_8_cuchilla_2.osg");
	mt22->addChild(rNode52);

	rNode53 = osgDB::readNodeFile("models/eje_8_cuchilla_3.osg");
	mt22->addChild(rNode53);

	rNode54 = osgDB::readNodeFile("models/eje_8_cuchilla_4.osg");
	mt22->addChild(rNode54);

	centro8 = osg::Vec3(mt22->getChild(0)->getBound().center());


	mt23 = new osg::MatrixTransform();
	rNode55 = osgDB::readNodeFile("models/eje_9.osg");
	mt23->addChild(rNode55);
	scene->addChild(mt23);

	rNode56 = osgDB::readNodeFile("models/eje_9_cuchilla_1.osg");
	mt23->addChild(rNode56);
	
	rNode57 = osgDB::readNodeFile("models/eje_9_cuchilla_2.osg");
	mt23->addChild(rNode57);

	rNode58 = osgDB::readNodeFile("models/eje_9_cuchilla_3.osg");
	mt23->addChild(rNode58);

	rNode59 = osgDB::readNodeFile("models/eje_9_cuchilla_4.osg");
	mt23->addChild(rNode59);

	centro9 = osg::Vec3(mt23->getChild(0)->getBound().center());
	

	cerdoM1 = new osg::MatrixTransform();
	cerdo = osgDB::readNodeFile("models/cerdito_static.osg");
	cerdoM1->addChild(cerdo);
	scene->addChild(cerdoM1);
	transMatCerdos.makeTranslate(osg::Vec3(centro1.x(), centro1.y(), 5.5f));
	cerdoM1->preMult(transMatCerdos);

	cerdoM2 = new osg::MatrixTransform();
	cerdoM2->addChild(cerdo);
	scene->addChild(cerdoM2);
	transMatCerdos.makeTranslate(osg::Vec3(centro2.x(), centro2.y(), 5.5f));
	cerdoM2->preMult(transMatCerdos);

	cerdoM3 = new osg::MatrixTransform();
	cerdoM3->addChild(cerdo);
	scene->addChild(cerdoM3);
	transMatCerdos.makeTranslate(osg::Vec3(centro3.x(), centro3.y(), 5.5f));
	cerdoM3->preMult(transMatCerdos);

	cerdoM4 = new osg::MatrixTransform();
	cerdoM4->addChild(cerdo);
	scene->addChild(cerdoM4);
	transMatCerdos.makeTranslate(osg::Vec3(centro4.x(), centro4.y(), 5.5f));
	cerdoM4->preMult(transMatCerdos);

	cerdoM5 = new osg::MatrixTransform();
	cerdoM5->addChild(cerdo);
	scene->addChild(cerdoM5);
	transMatCerdos.makeTranslate(osg::Vec3(centro5.x(), centro5.y(), 5.5f));
	cerdoM5->preMult(transMatCerdos);

	cerdoM6 = new osg::MatrixTransform();
	cerdoM6->addChild(cerdo);
	scene->addChild(cerdoM6);
	transMatCerdos.makeTranslate(osg::Vec3(centro6.x(), centro6.y(), 5.5f));
	cerdoM6->preMult(transMatCerdos);

	cerdoM7 = new osg::MatrixTransform();
	cerdoM7->addChild(cerdo);
	scene->addChild(cerdoM7);
	transMatCerdos.makeTranslate(osg::Vec3(centro7.x(), centro7.y(), 5.5f));
	cerdoM7->preMult(transMatCerdos);

	cerdoM8 = new osg::MatrixTransform();
	cerdoM8->addChild(cerdo);
	scene->addChild(cerdoM8);
	transMatCerdos.makeTranslate(osg::Vec3(centro8.x(), centro8.y(), 5.5f));
	cerdoM8->preMult(transMatCerdos);

	cerdoM9 = new osg::MatrixTransform();
	cerdoM9->addChild(cerdo);
	scene->addChild(cerdoM9);
	transMatCerdos.makeTranslate(osg::Vec3(centro9.x(), centro9.y(), 5.5f));
	cerdoM9->preMult(transMatCerdos);


	osgUtil::Optimizer optimizer1;
	optimizer1.optimize(rNode1, osgUtil::Optimizer::FLATTEN_STATIC_TRANSFORMS | osgUtil::Optimizer::REMOVE_REDUNDANT_NODES | osgUtil::Optimizer::DEFAULT_OPTIMIZATIONS);
	//osgUtil::Optimizer optimizer2;
	//optimizer2.optimize(rNode2, osgUtil::Optimizer::FLATTEN_STATIC_TRANSFORMS | osgUtil::Optimizer::REMOVE_REDUNDANT_NODES | osgUtil::Optimizer::DEFAULT_OPTIMIZATIONS);
	//osgUtil::Optimizer optimizer3;
	//optimizer.optimize(rNode1, osgUtil::Optimizer::FLATTEN_STATIC_TRANSFORMS | osgUtil::Optimizer::REMOVE_REDUNDANT_NODES | osgUtil::Optimizer::DEFAULT_OPTIMIZATIONS);

	osg::Matrix rotMPlayer;
	osg::Matrix transMPlayer;

	playerMT = new osg::MatrixTransform();

	transMPlayer.makeTranslate(osg::Vec3(40.0f, 0.0f, 3.5f));
	rotMPlayer.makeRotate((osg::Quat((3.14/2), osg::Vec3d(0, 0, 1))));

	transMPlayer.preMult(rotMPlayer);
	playerMT->setMatrix(transMPlayer);

	playerMT->addChild(playerModel.get());
	scene->addChild(playerMT);

	myIH->setController(playerMT);

	mAnimHandler->changePlayerAnimation(1, 0.6);
}


void GameSim::update()
{
	myIH->update(delta);


	//time += delta;

	if(timeAux1 <= 5.0 && arriba)
	{
		timeAux1 += delta;
	}
	else if(timeAux1 <= 2.0 && abajo)
	{
		timeAux1 += delta;
	}
	else if(arriba)
	{
		bajar = true;
		arriba = false;
		timeAux1 = 0;
	}
	else if(abajo)
	{
		subir = true;
		abajo = false;
		timeAux1 = 0;
		cerditos();
	}
	
	if(timeAux2 <= 2.0 && subir)
	{
		timeAux2 += delta;
		alturaBases = 5.0f*(float)delta;
	}
	else if(timeAux2 <= 2.0 && bajar)
	{
		timeAux2 += delta;
		alturaBases = -5.0f*(float)delta;
	}
	else if(subir)
	{
		subir = false;
		arriba = true;
		timeAux2 = 0;
		alturaBases = 0.0f;
	}
	else if(bajar)
	{
		bajar = false;
		abajo = true;
		timeAux2 = 0;
		alturaBases = 0.0f;
	}

	transMatBases.makeTranslate(osg::Vec3(0.0f, 0.0f, alturaBases));
	mt3->postMult(transMatBases);

	cerdoM1->postMult(transMatBases);
	cerdoM2->postMult(transMatBases);
	cerdoM3->postMult(transMatBases);
	cerdoM4->postMult(transMatBases);
	cerdoM5->postMult(transMatBases);
	cerdoM6->postMult(transMatBases);
	cerdoM7->postMult(transMatBases);
	cerdoM8->postMult(transMatBases);
	cerdoM9->postMult(transMatBases);
}


	
	
