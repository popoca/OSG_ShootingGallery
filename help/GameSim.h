#ifndef _GAMESIM_
#define _GAMESIM_

#include "SoundHandler.h"
#include "ShaderHandler.h"
#include "AnimationHandler.h"
#include "InputHandler.h"

#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osg/Matrix>
#include <osg/Group>

#include <cstdlib>


class GameSim: public osg::Referenced
{

public:

	GameSim();

	~GameSim()
	{
	
	}

	void updateD( double a ){
		delta = a;
	}

	void shutDown(){
		mSoundHandler->shutDownHandler();
	}

	void update();

	void cerditos();

	bool startGame(){
		if(!start && (myIH->b1 || myIH->b2 || myIH->b3 || myIH->b4 || myIH->b5
			|| myIH->b6 || myIH->b7 || myIH->b8 || myIH->b9))
		{
			start = true;
		}
		return start;
	}

	osg::ref_ptr<osg::Group> getRootNode()
	{
		return root;
	}

	osg::ref_ptr<InputHandler> getMyInputHandler()
	{
		return myIH;
	}

	

private:

	 osg::ref_ptr<osg::Group> root;
	 osg::ref_ptr<osg::Group> scene;
	 osg::ref_ptr<ShaderHandler> msh;
	 osg::ref_ptr<SoundHandler> mSoundHandler;
	 osg::ref_ptr<AnimationHandler> mAnimHandler;
	 osg::ref_ptr<InputHandler> myIH;

	 osg::ref_ptr<osg::MatrixTransform> playerMT;
	 osg::ref_ptr<osg::Node> playerModel;

	 osg::ref_ptr<osgAL::SoundNode> mAmbientSound;
	 osg::ref_ptr<osgAL::SoundNode> mElevadorSound;
	 osg::ref_ptr<osgAL::SoundNode> mBotonSound;
	 osg::ref_ptr<osgAL::SoundNode> mCuchillasSound;
	 osg::ref_ptr<osgAL::SoundNode> mCerdito1Sound;
	 osg::ref_ptr<osgAL::SoundNode> mCerdito2Sound;
	 osg::ref_ptr<osgAL::SoundNode> mCerdito3Sound;

	 osg::ref_ptr<osg::MatrixTransform> mt1;
	 osg::ref_ptr<osg::Node> rNode1;
	 osg::ref_ptr<osg::MatrixTransform> mt2;
	 osg::ref_ptr<osg::Node> rNode2;
	 osg::ref_ptr<osg::MatrixTransform> mt3;
	 osg::ref_ptr<osg::Node> rNode3;
	 osg::ref_ptr<osg::MatrixTransform> mt4;
	 osg::ref_ptr<osg::Node> rNode4;
	 osg::ref_ptr<osg::MatrixTransform> mt5;
	 osg::ref_ptr<osg::Node> rNode5;
	 osg::ref_ptr<osg::MatrixTransform> mt6;
	 osg::ref_ptr<osg::Node> rNode6;
	 osg::ref_ptr<osg::MatrixTransform> mt7;
	 osg::ref_ptr<osg::Node> rNode7;
	 osg::ref_ptr<osg::MatrixTransform> mt8;
	 osg::ref_ptr<osg::Node> rNode8;
	 osg::ref_ptr<osg::MatrixTransform> mt9;
	 osg::ref_ptr<osg::Node> rNode9;
	 osg::ref_ptr<osg::MatrixTransform> mt10;
	 osg::ref_ptr<osg::Node> rNode10;
	 osg::ref_ptr<osg::MatrixTransform> mt11;
	 osg::ref_ptr<osg::Node> rNode11;
	 osg::ref_ptr<osg::MatrixTransform> mt12;
	 osg::ref_ptr<osg::Node> rNode12;
	 osg::ref_ptr<osg::MatrixTransform> mt13;
	 osg::ref_ptr<osg::Node> rNode13;
	 osg::ref_ptr<osg::MatrixTransform> mt14;
	 osg::ref_ptr<osg::Node> rNode14;

	 osg::ref_ptr<osg::MatrixTransform> mt15;
	 osg::ref_ptr<osg::Node> rNode15;
	 osg::ref_ptr<osg::Node> rNode16;
	 osg::ref_ptr<osg::Node> rNode17;
	 osg::ref_ptr<osg::Node> rNode18;
	 osg::ref_ptr<osg::Node> rNode19;
	 osg::ref_ptr<osg::MatrixTransform> mt16;
	 osg::ref_ptr<osg::Node> rNode20;
	 osg::ref_ptr<osg::Node> rNode21;
	 osg::ref_ptr<osg::Node> rNode22;
	 osg::ref_ptr<osg::Node> rNode23;
	 osg::ref_ptr<osg::Node> rNode24;
	 osg::ref_ptr<osg::MatrixTransform> mt17;
	 osg::ref_ptr<osg::Node> rNode25;
	 osg::ref_ptr<osg::Node> rNode26;
	 osg::ref_ptr<osg::Node> rNode27;
	 osg::ref_ptr<osg::Node> rNode28;
	 osg::ref_ptr<osg::Node> rNode29;
	 osg::ref_ptr<osg::MatrixTransform> mt18;
	 osg::ref_ptr<osg::Node> rNode30;
	 osg::ref_ptr<osg::Node> rNode31;
	 osg::ref_ptr<osg::Node> rNode32;
	 osg::ref_ptr<osg::Node> rNode33;
	 osg::ref_ptr<osg::Node> rNode34;
 	 osg::ref_ptr<osg::MatrixTransform> mt19;
	 osg::ref_ptr<osg::Node> rNode35;
	 osg::ref_ptr<osg::Node> rNode36;
	 osg::ref_ptr<osg::Node> rNode37;
	 osg::ref_ptr<osg::Node> rNode38;
	 osg::ref_ptr<osg::Node> rNode39;
	 osg::ref_ptr<osg::MatrixTransform> mt20;
	 osg::ref_ptr<osg::Node> rNode40;
	 osg::ref_ptr<osg::Node> rNode41;
	 osg::ref_ptr<osg::Node> rNode42;
	 osg::ref_ptr<osg::Node> rNode43;
	 osg::ref_ptr<osg::Node> rNode44;
 	 osg::ref_ptr<osg::MatrixTransform> mt21;
	 osg::ref_ptr<osg::Node> rNode45;
	 osg::ref_ptr<osg::Node> rNode46;
	 osg::ref_ptr<osg::Node> rNode47;
	 osg::ref_ptr<osg::Node> rNode48;
	 osg::ref_ptr<osg::Node> rNode49;
	 osg::ref_ptr<osg::MatrixTransform> mt22;
	 osg::ref_ptr<osg::Node> rNode50;
	 osg::ref_ptr<osg::Node> rNode51;
	 osg::ref_ptr<osg::Node> rNode52;
	 osg::ref_ptr<osg::Node> rNode53;
	 osg::ref_ptr<osg::Node> rNode54;
 	 osg::ref_ptr<osg::MatrixTransform> mt23;
	 osg::ref_ptr<osg::Node> rNode55;
	 osg::ref_ptr<osg::Node> rNode56;
	 osg::ref_ptr<osg::Node> rNode57;
	 osg::ref_ptr<osg::Node> rNode58;
	 osg::ref_ptr<osg::Node> rNode59;

	 osg::ref_ptr<osg::Node> cerdo;
	 osg::ref_ptr<osg::MatrixTransform> cerdoM1;
	 osg::ref_ptr<osg::MatrixTransform> cerdoM2;
	 osg::ref_ptr<osg::MatrixTransform> cerdoM3;
	 osg::ref_ptr<osg::MatrixTransform> cerdoM4;
	 osg::ref_ptr<osg::MatrixTransform> cerdoM5;
	 osg::ref_ptr<osg::MatrixTransform> cerdoM6;
	 osg::ref_ptr<osg::MatrixTransform> cerdoM7;
	 osg::ref_ptr<osg::MatrixTransform> cerdoM8;
	 osg::ref_ptr<osg::MatrixTransform> cerdoM9;

	 osg::Vec3 centro1,centro2,centro3,centro4,centro5,centro6,centro7,centro8,centro9;

	 osg::Matrix transMatBases;

	 double delta;
	 double time;

	 float alturaBases;


	 bool start;
};

#endif