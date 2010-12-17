#include "SoundHandler.h"

using namespace osgAudio;

// Constructor
SoundHandler::SoundHandler(osg::ref_ptr< osg::Group > root, osg::ref_ptr< osgViewer::View > viewer )
: sceneRoot( root )
{
	// Se inicializa la instancias del manejador de sonidos de osgAL
	// con 16 canales de audio y se configura el modelo de atenuacion
	osgAudio::SoundManager::instance()->init( 16, true );
    osgAudio::SoundManager::instance()->getEnvironment()->setDistanceModel(osgAudio::InverseDistance);
    osgAudio::SoundManager::instance()->getEnvironment()->setDopplerFactor(1);

	// Create ONE (only one, otherwise the transformation of the listener and update for SoundManager will be
    // called several times, which is not catastrophic, but unnecessary) 
    // SoundRoot that will make sure the listener is updated and
    // to keep the internal state of the SoundManager updated
    // This could also be done manually, this is just a handy way of doing it.
    sound_root = new osgAudio::SoundRoot;

	// Specify the camera from our viewer. The view matrix from this camera
    // will be used during update to set the Listener position. Note this
    // will not work if the viewer is rendering to multiple displays; will
    // need to select a slave camera.
    sound_root->setCamera( viewer->getCamera() );

	// The position in the scenegraph of this node is not important.
    // Just as long as the cull traversal should be called after any changes to the SoundManager are made.
    sceneRoot->addChild( sound_root.get() );

	/* fail begins here */

	// Se agrega el sonido raiz al grafo de escena
	/*sound_root = new osgAL::SoundRoot;
	sceneRoot = root;
	sceneRoot->addChild(sound_root.get());*/

}

SoundHandler::~SoundHandler()
{
}

// Apaga al manejador de sonidos, antes de ser destruido
void SoundHandler::shutDownHandler()
{
	// Very important to call before end of main!
    if (osg::Referenced::getDeleteHandler()) {
        osg::Referenced::getDeleteHandler()->setNumFramesToRetainObjects(0);
        osg::Referenced::getDeleteHandler()->flushAll();
    }
    osgAudio::SoundManager::instance()->shutdown();
}

// Detiene el sonido con el indice ssindex
void SoundHandler::stopSound(int ssindex)
{
	ssiter = ssvector.begin();
	ssiter = ssiter + ssindex;
	(*ssiter)->setStopMethod( osgAudio::SourceState::Stopped );
	(*ssiter)->setPlay(false);
}

// Pausa el sonido con el indice ssindex
void SoundHandler::pauseSound( int ssindex )
{
	ssiter = ssvector.begin();
	ssiter = ssiter + ssindex;
	
	(*ssiter)->setStopMethod( osgAudio::SourceState::Paused );
	(*ssiter)->setPlay(false);

}

// Reproduce el sonido con el indice ssindex
void SoundHandler::playSound(int ssindex)
{
	ssiter = ssvector.begin();
	ssiter = ssiter + ssindex;
	(*ssiter)->setPlay(true);

}

// Crea y configura un sonido puntual
osg::ref_ptr< osgAudio::SoundNode > SoundHandler::createPositionalSound(const std::string& file, const std::string& name)
{
	// Create a sample, load a .wav file.
    osgAudio::Sample *sample = new osgAudio::Sample(
        osgDB::findDataFile( file ) );

	// Create a named sound state.
    osg::ref_ptr<osgAudio::SoundState> sound_state = new osgAudio::SoundState( name );

	// Let the soundstate use the sample we just created
    sound_state->setSample(sample);

	// Set its gain (volume) to 0.9
    sound_state->setGain(0.9f);

	// Set its pitch to 1 (normal speed)
    sound_state->setPitch(1);

	// Make it play
    sound_state->setPlay(true);

	// The sound should loop over and over again
    sound_state->setLooping(true);

	// Allocate a hardware soundsource to this soundstate (priority 10)
    sound_state->allocateSource(10, false);

	// At 70 the gain will be half of full!
    sound_state->setReferenceDistance(70);
    sound_state->setRolloffFactor(4);
    sound_state->apply();
   
	// Add the soundstate to the sound manager, so we can find it later on if we want to
    osgAudio::SoundManager::instance()->addSoundState(sound_state.get());

	
	// Se crea un nodo de sonido con el estado configurado
	osg::ref_ptr< osgAudio::SoundNode > sound = new osgAudio::SoundNode();
	sound->setSoundState( sound_state );

	ssvector.push_back( sound_state.get() );

	sceneRoot->addChild( sound.get() );

	return sound.get();
}

// Crea y configura un sonido puntual para la colision
osg::ref_ptr< osgAudio::SoundNode > SoundHandler::createEventSound(const std::string& file, const std::string& name)
{
	// Create a sample, load a .wav file.
    osgAudio::Sample *sample = new osgAudio::Sample(
        osgDB::findDataFile( file ) );

	// Create a named sound state.
    osg::ref_ptr<osgAudio::SoundState> sound_state = new osgAudio::SoundState( name );

	// Let the soundstate use the sample we just created
    sound_state->setSample(sample);

	// Set its gain (volume) to 0.9
    sound_state->setGain(0.9f);

	// Set its pitch to 1 (normal speed)
    sound_state->setPitch(1);

	// Make it play
    sound_state->setPlay(false);

	// The sound should not loop over and over again
    sound_state->setLooping(false);

	// Allocate a hardware soundsource to this soundstate (priority 10)
    sound_state->allocateSource(10, false);

	// At 70 the gain will be half of full!
    sound_state->setReferenceDistance(70);
    sound_state->setRolloffFactor(4);
    sound_state->apply();
   
	// Add the soundstate to the sound manager, so we can find it later on if we want to
    osgAudio::SoundManager::instance()->addSoundState(sound_state.get());

	
	// Se crea un nodo de sonido con el estado configurado
	osg::ref_ptr< osgAudio::SoundNode > sound = new osgAudio::SoundNode;
	sound->setSoundState( sound_state );

	ssvector.push_back( sound_state.get() );

	sceneRoot->addChild( sound.get() );

	return sound.get();
}

// Crea y configura un sonido ambiental
osg::ref_ptr< osgAudio::SoundNode > SoundHandler::createAmbientSound(const std::string& file, const std::string& name)
{
	// Create a sample, load a .wav file.
    osgAudio::Sample *sample = new osgAudio::Sample(
        osgDB::findDataFile( file ) );
	// Create a named sound state.
    osg::ref_ptr<osgAudio::SoundState> sound_state = new osgAudio::SoundState( name );
	// Let the soundstate use the sample we just created
    sound_state->setSample( sample );
	// Set its gain (volume) to 0.9
    sound_state->setGain(0.4f);
	// Set its pitch to 1 (normal speed)
    sound_state->setPitch(1);
	// Make it play
    sound_state->setPlay(true);
	// The sound should loop over and over again
    sound_state->setLooping(true);
	// Allocate a hardware soundsource to this soundstate (priority 10)
    sound_state->allocateSource(10, false);
	// Set Ambient to true
	sound_state->setAmbient( true );
    sound_state->apply();
   
	// Add the soundstate to the sound manager, so we can find it later on if we want to
    osgAudio::SoundManager::instance()->addSoundState(sound_state.get());
	
	// Se crea un nodo de sonido con el estado configurado
	osg::ref_ptr< osgAudio::SoundNode > sound = new osgAudio::SoundNode;
	sound->setSoundState( sound_state );

	ssvector.push_back( sound_state.get() );

	sceneRoot->addChild( sound.get() );

	return sound.get();
}