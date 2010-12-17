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

	SoundHandler(osg::Group* root);
	~SoundHandler();

	osg::ref_ptr<osgAL::SoundNode> createPositionalSound(const std::string& file, const std::string& sname);
	osg::ref_ptr<osgAL::SoundNode> createBotonSound(const std::string& file, const std::string& sname);
	osg::ref_ptr<osgAL::SoundNode> createAmbientSound(const std::string& file, const std::string& sname);
	void stopSound(int ssindex);
	void pauseSound(int ssindex);
	void playSound(int ssindex);
	void shutDownHandler();

private:
	osg::ref_ptr<osgAL::SoundRoot> sound_root;
	osg::Group *sceneRoot;
	std::vector<osgAL::SoundState*> ssvector; 
	std::vector<osgAL::SoundState*>::iterator ssiter;
};
#endif
