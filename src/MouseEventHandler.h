#ifndef _MYMSHNDL_
#define _MYMSHNDL_

#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIEventHandler>
#include <osg/Object>
#include <osg/NodeVisitor>
#include <osgUtil/IntersectionVisitor>
#include <osgUtil/LineSegmentIntersector>
#include <osg/Group>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <iostream>

class MouseEventHandler : public osgGA::GUIEventHandler {
 
    protected:
    float _mX, _mY;
 
    public:

     MouseEventHandler();
    ~MouseEventHandler();
	void setRootNode( osg::ref_ptr< osg::Group > rootNode );
    
	osg::ref_ptr< osg::Group > mRootNode;

    virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
};

#endif
