#ifndef _GAMESIM_
#define _GAMESIM_
#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osg/Matrix>
#include <osg/Group>
#include <cstdlib>

class GameSim: public osg::Referenced
{

public:

	// Constructor 
	GameSim();
	// Desctructor
	~GameSim();

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
	 bool start;
};

#endif