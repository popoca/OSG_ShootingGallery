//Input handler
//Este input handler va a dar la referencia a los demás handlers
#include "InputHandler.h"
#include <osg/Group>

InputHandler::InputHandler(osg::Group *rootNode)
{
	myMSH.setRootNode(rootNode);
}

MyKeyboardEventHandler InputHandler::getKeyboardHandler()
{
	return myKBH; 
}
MouseEventHandler InputHandler::getMouseHandler()
{
	return myMSH;
}

