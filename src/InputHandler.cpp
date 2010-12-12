//Input handler
//Este input handler va a dar la referencia a los demás handlers
#include "InputHandler.h"
#include <osg/Group>

InputHandler::InputHandler(osgText::Text* _updateText)
{
	updateText = _updateText;
	//printf("Not created");
	myPKH = new PickHandler(updateText);
	myKBH = new MyKeyboardEventHandler();
	//myMSH->setRootNode(rootNode);
}

MyKeyboardEventHandler* InputHandler::getKeyboardHandler()
{
	return myKBH; 
}
PickHandler* InputHandler::getPickHandler()
{
	return myPKH;
}

