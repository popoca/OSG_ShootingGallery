//////////////////////////////////////////////////////////////////////////////////
//																				//
//					Cruz Lovera Tayde Martín									//
//							Tarea 11											//
//																				//
//////////////////////////////////////////////////////////////////////////////////

#ifndef _SOUNDHANDLER_
#define _SOUNDHANDLER_

#include <osgAL/SoundNode>
#include <osgAL/SoundRoot>
#include <osgAL/SoundManager>
#include <osgAL/SoundState>

#include <osg/DeleteHandler>
#include <osg/Group>


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
