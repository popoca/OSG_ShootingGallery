
#ifndef _PICKER_
#define _PICKER_

#include <osgUtil/Optimizer>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgViewer/CompositeViewer>
#include <osgGA/TerrainManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>
#include <osg/Material>
#include <osg/Geode>
#include <osg/BlendFunc>
#include <osg/Depth>
#include <osg/Projection>
#include <osg/MatrixTransform>
#include <osg/Camera>
#include <osg/io_utils>
#include <osg/ShapeDrawable>
#include <osgText/Text>
#include <sstream>
#include <iostream>
#include <osgViewer/GraphicsWindow>
#include <string>
#include "HUDHandler.h"
#include "SoundHandler.h"

class PickHandler : public osgGA::GUIEventHandler {
public: 

    PickHandler(osgText::Text* updateText, HUDHandler* _myHH, SoundHandler *sHandle );
    ~PickHandler();
    
    bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);

    virtual void pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea);

    void setLabel(const std::string& name)
    {
        if (_updateText.get()) _updateText->setText(name);
    }
    HUDHandler* myHH;
	SoundHandler *sHandle;
protected:

    osg::ref_ptr<osgText::Text>  _updateText;
};

#endif
