#include "MyKeyboardEventHandler.h"

    MyKeyboardEventHandler::MyKeyboardEventHandler()
    {}
    
    MyKeyboardEventHandler::~MyKeyboardEventHandler()
    {}

    bool MyKeyboardEventHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa, 
                        osg::Object* obj, osg::NodeVisitor* nv) { 

        switch (ea.getEventType()) {
 
            case osgGA::GUIEventAdapter::KEYDOWN: {
 				printf("Key pressed\n");
                switch (ea.getKey()) {
 
                    case osgGA::GUIEventAdapter::KEY_KP_Enter: 
                       	enter_pressed = true;
                        return true;
                }
                   default: return false;
            }
        }
    }

