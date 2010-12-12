#ifndef _WORLDSIM_
#define _WORLDSIM_

#include "ShaderHandler.h"

#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osg/Matrix>
#include <osg/Group>
#include <cstdlib>

class WorldSim: public osg::Referenced
{

public:

	// Constructor 
	WorldSim();
	// Desctructor
	~WorldSim()
	{
	
	}

	// GameStates
	bool startGame(){
		if(!start)
		{
			start = true;
		}
		return start;
	}


	osg::ref_ptr<osg::Group> getRootNode() { return root; }

private:

	 osg::ref_ptr<osg::Group> root;
	 osg::ref_ptr<ShaderHandler> mySH;
	 bool start;
};

#endif