#ifndef _MYKBDHNDL_
#define _MYKBDHNDL_

#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventHandler>
#include <osg/Object>
#include <osg/NodeVisitor>
#include "HUDHandler.h"

class MyKeyboardEventHandler : public osgGA::GUIEventHandler {
 
public:

    MyKeyboardEventHandler();
    ~MyKeyboardEventHandler();    
	HUDHandler* myHH;
	void getHH(HUDHandler* _myHH);
	bool enter_pressed;
    virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
    
};

#endif
