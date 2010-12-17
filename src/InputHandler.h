
#ifndef 	_INPUTH_
#define _INPUTH_

#include "PickerHandler.h"
#include "MyKeyboardEventHandler.h"
#include "HUDHandler.h"
#include "SoundHandler.h"
#include <osg/Group>

class InputHandler
{
	private:
	
	public:	
	
	InputHandler(osgText::Text* updateText, HUDHandler* _myHH, SoundHandler *sHandle );
	~InputHandler();
	
	MyKeyboardEventHandler* myKBH;
	PickHandler *myPKH;
	osgText::Text* updateText;
	
	MyKeyboardEventHandler* getKeyboardHandler();
	PickHandler* getPickHandler();
	
};


#endif
