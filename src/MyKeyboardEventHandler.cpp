#include "MyKeyboardEventHandler.h"


    MyKeyboardEventHandler::MyKeyboardEventHandler()
		: enter_pressed( false )
    {}
    
    MyKeyboardEventHandler::~MyKeyboardEventHandler()
    {}

	void MyKeyboardEventHandler::getHH(HUDHandler* _myHH)
	{
		myHH = _myHH;
	}



    bool MyKeyboardEventHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa) { 

        switch (ea.getEventType()) {
 
            case osgGA::GUIEventAdapter::KEYDOWN: 
 				printf("Key pressed\n");

			if(myHH->showing)
				myHH->quitMessage();

			enter_pressed = true;

				return true;

			default:
				return false;
		}
    }

