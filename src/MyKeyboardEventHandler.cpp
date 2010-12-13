#include "MyKeyboardEventHandler.h"

    MyKeyboardEventHandler::MyKeyboardEventHandler()
		: enter_pressed( false )
    {}
    
    MyKeyboardEventHandler::~MyKeyboardEventHandler()
    {}

    bool MyKeyboardEventHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa, 
                        osg::Object* obj, osg::NodeVisitor* nv) { 

        switch (ea.getEventType()) {
 
            case osgGA::GUIEventAdapter::KEYDOWN: 
 				printf("Key pressed\n");
                enter_pressed = true;
			return true;

			default:
				return false;
		}
    }

