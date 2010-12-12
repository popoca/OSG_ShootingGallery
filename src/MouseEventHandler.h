#ifndef _MYMSHNDL_
#define _MYMSHNDL_

#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIEventHandler>
#include <osg/Object>
#include <osg/NodeVisitor>
#include <osgUtil/IntersectionVisitor>
#include <osgUtil/LineSegmentIntersector>
#include <osg/Group>

class MouseEventHandler : public osgGA::GUIEventHandler {
 
    protected:
    float _mX, _mY;
 
    public:
    
     MouseEventHandler();
    ~MouseEventHandler();
    void setRootNode(osg::Group *rootNode);
    
    
 	osg::Group* mRootNode;

    virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
};

#endif
