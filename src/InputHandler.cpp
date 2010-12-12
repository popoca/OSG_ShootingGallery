//Input handler
//Este input handler va a dar la referencia a los demás handlers
#include "InputHandler.h"
#include <osg/Group>

InputHandler::InputHandler(osg::Group *rootNode)
{
	printf("Not created");
	myMSH = new MouseEventHandler();
	myKBH = new MyKeyboardEventHandler();
	myMSH->setRootNode(rootNode);
	
}

MyKeyboardEventHandler* InputHandler::getKeyboardHandler()
{
	return myKBH; 
}
MouseEventHandler* InputHandler::getMouseHandler()
{
	return myMSH;
}

