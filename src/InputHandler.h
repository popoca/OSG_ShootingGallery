
#ifndef 	_INPUTH_
#define _INPUTH_

#include "MouseEventHandler.h"
#include "MyKeyboardEventHandler.h"
#include <osg/Group>

class InputHandler
{
	private:
	
	public:	
	
	InputHandler(osg::Group* rootNode);
	~InputHandler();
	osg::Vec3f camera;
	
	MyKeyboardEventHandler myKBH;
	MouseEventHandler myMSH;
	
	MyKeyboardEventHandler getKeyboardHandler();
	MouseEventHandler getMouseHandler();
	
};


#endif
