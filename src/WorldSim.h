#ifndef _WORLDSIM_
#define _WORLDSIM_

#include "ShaderHandler.h"
#include "InputHandler.h"
#include "ModelManager.h"
#include "HUDHandler.h"

#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osg/Matrix>
#include <osg/Group>
#include <cstdlib>

class WorldSim: public osg::Referenced
{

public:
	
	InputHandler* myIH;
	HUDHandler* myHH;
	
	// Constructor 
	WorldSim(osg::ref_ptr<osgText::Text> _updateText);
	// Desctructor
	~WorldSim()
	{
	
	}

	osg::ref_ptr<osg::Group> getRootNode() { return root; }

	/* estructura para detectar el estado actual del juego */
	enum GameState{ Start, Level1, Level2, Level3, Level4, Level5, GameOver };
	GameState currState;

	/* metodo para actualizar la escena dependiendo del estado actual */
	void update( float delta );
	bool hasLoaded;

private:

	 osg::ref_ptr<osg::Group> root;
	 osg::ref_ptr<ShaderHandler> mySH;
	 osg::ref_ptr< ModelManager > mm;
	 bool start;
};

#endif
