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

#include <osgAudio/FileStream.h>
#include <osgAudio/SoundUpdateCB.h>
#include <osgAudio/SoundRoot.h>
#include <osgAudio/SoundManager.h>
#include <osgAudio/SoundState.h>
#include <osgAudio/Version.h>

class SoundHandler: public osg::Referenced
{
public:

	SoundHandler( osg::ref_ptr< osg::Group > root, osg::ref_ptr< osgViewer::Viewer > viewer );
	~SoundHandler();

	osg::ref_ptr< osgAudio::SoundState > createSoundState(const std::string& file);
	osg::ref_ptr< osgAudio::SoundState > createBotonSound(const std::string& file, const std::string& sname);
	osg::ref_ptr< osgAudio::SoundState > createAmbientSound(const std::string& file, const std::string& sname);
	void stopSound(int ssindex);
	void pauseSound(int ssindex);
	void playSound(int ssindex);
	void shutDownHandler();

private:
	osg::ref_ptr< osgAudio::SoundRoot > sound_root;
	osg::ref_ptr< osg::Group > sceneRoot;
	std::vector< osg::ref_ptr< osgAL::SoundState > > ssvector; 
	std::vector< osg::ref_ptr< osgAL::SoundState > >::iterator ssiter;
};
#endif
