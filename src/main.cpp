#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>

int main()
{
    osgViewer::Viewer viewer;
    viewer.realize();

    while( !viewer.done() )
    {
        viewer.frame();
    }
    return 0;
}