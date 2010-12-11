#ifndef _INPUTHANDLER_
#define _INPUTHANDLER_

#include <osgViewer/Viewer>
#include <osg/MatrixTransform>
#include <osgGA/GUIEventHandler>

class InputHandler : public osgGA::GUIEventHandler 
{
public: 

	InputHandler();
	~InputHandler();

	void setController( osg::ref_ptr< osg::MatrixTransform > jModel );
	void update( double a );
	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
	bool wflag, vflag, sflag, playerSL, playerSR;
	bool b1, b2, b3, b4, b5, b6, b7, b8, b9;
	//bool mouseMoving, dragRB, dragLB;
        
private:
		
	//int	oldy, newy, deltay;
	//int	oldx, newx, deltax;
	double delta;
	osg::ref_ptr< osg::MatrixTransform > tModel;
	osg::Matrix trans;
		
};

#endif
