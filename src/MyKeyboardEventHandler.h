#ifndef _MYKBDHNDL_
#define _MYKBDHNDL_

#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventHandler>
#include <osg/Object>
#include <osg/NodeVisitor>

class MyKeyboardEventHandler : public osgGA::GUIEventHandler {
 
public:
    MyKeyboardEventHandler();
    ~MyKeyboardEventHandler();     
    bool enter_pressed;
    virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa, 
                        osg::Object* obj, osg::NodeVisitor* nv);
    
};

#endif
