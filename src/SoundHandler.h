#ifndef SOUND_H
#define SOUND_H

#include <osgDB/FileUtils>
#include <osg/DeleteHandler>
#include <osg/Notify>
#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osg/Geometry>
#include <osg/Geode>
#include <osgUtil/Optimizer>
#include <osgDB/Registry>
#include <osgDB/ReadFile>
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/Viewer>
#include <osg/DeleteHandler>
#include <osg/Group>

#include <osgAudio/FileStream.h>
#include <osgAudio/SoundUpdateCB.h>
#include <osgAudio/SoundRoot.h>
#include <osgAudio/SoundManager.h>
#include <osgAudio/SoundState.h>
#include <osgAudio/Version.h>
#include <osgAudio/SoundNode.h>

class SoundHandler: public osg::Referenced
{
public:

	SoundHandler::SoundHandler(osg::ref_ptr< osg::Group > root, osg::ref_ptr< osgViewer::View > viewer );
	~SoundHandler();

	osg::ref_ptr< osgAudio::SoundNode > createPositionalSound(const std::string& file, const std::string& sname);
	osg::ref_ptr< osgAudio::SoundNode > createEventSound(const std::string& file, const std::string& sname);
	osg::ref_ptr< osgAudio::SoundNode > createAmbientSound(const std::string& file, const std::string& sname);
	void stopSound(int ssindex);
	void pauseSound(int ssindex);
	void playSound(int ssindex);
	void shutDownHandler();

private:

	osg::ref_ptr< osgAudio::SoundRoot > sound_root;
	osg::ref_ptr< osg::Group > sceneRoot;
	std::vector< osgAudio::SoundState* > ssvector; 
	std::vector< osgAudio::SoundState* >::iterator ssiter;



};
#endif
