//////////////////////////////////////////////////////////////////////////////////
//																				//
//					Cruz Lovera Tayde Martín									//
//						   Wack a Pig											//
//																				//
//////////////////////////////////////////////////////////////////////////////////

#include "SoundHandler.h"

// Constructor
SoundHandler::SoundHandler(osg::Group* root)
{
	// Se inicializa la instancias del manejador de sonidos de osgAL
	// con 16 canales de audio y se configura el modelo de atenuacion
	osgAL::SoundManager::instance()->init(16);
	osgAL::SoundManager::instance()->getEnvironment()->setDistanceModel(openalpp::InverseDistance);
	//osgAL::SoundManager::instance()->getEnvironment()->setDistanceModel(openalpp::InverseDistanceClamped);
	osgAL::SoundManager::instance()->getEnvironment()->setDopplerFactor(1);


	// Se agrega el sonido raiz al grafo de escena
	sound_root = new osgAL::SoundRoot;
	sceneRoot = root;
	sceneRoot->addChild(sound_root.get());

	

	
}

SoundHandler::~SoundHandler()
{

}

// Apaga al manejador de sonidos, antes de ser destruido
void SoundHandler::shutDownHandler()
{

	if (osg::Referenced::getDeleteHandler()) {
		osg::Referenced::getDeleteHandler()->setNumFramesToRetainObjects(0);
		osg::Referenced::getDeleteHandler()->flushAll();
	}
	osgAL::SoundManager::instance()->shutdown();

}

// Detiene el sonido con el indice ssindex
void SoundHandler::stopSound(int ssindex)
{
	ssiter = ssvector.begin();
	ssiter = ssiter + ssindex;
	(*ssiter)->setStopMethod(openalpp::SourceState::Stopped);
	(*ssiter)->setPlay(false);

	
}

// Pausa el sonido con el indice ssindex
void SoundHandler::pauseSound(int ssindex)
{
	ssiter = ssvector.begin();
	ssiter = ssiter + ssindex;
	
	(*ssiter)->setStopMethod(openalpp::SourceState::Paused);
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
osg::ref_ptr<osgAL::SoundNode> SoundHandler::createPositionalSound(const std::string& file, const std::string& sname)
{
	// Carga el archivo de sonido
	openalpp::Sample *sample = new openalpp::Sample(file.c_str());

	// Crea un estado para el sonido
	osg::ref_ptr<osgAL::SoundState> sound_state = new osgAL::SoundState(sname.c_str());

	// Se asigna el sonido al estado
	sound_state->setSample(sample);

	// Se configura la ganancia (volumen) en 0.9
	sound_state->setGain(0.9f);

	// Se configura  el pitch en 1 (velocidad normal)
	sound_state->setPitch(1);

	// Reproduccion del sonido
	sound_state->setPlay(true);

	// Se configura un loop de sonido
	sound_state->setLooping(true);

	// Se crea una fuente para el sonido y se define su prioridad
	sound_state->allocateSource(10, false);

	// A una distancia de 30 unidades la ganacia sera 
	// la mitad de su valor maximo
	sound_state->setReferenceDistance(30);
	sound_state->setRolloffFactor(4);

	
	sound_state->apply();
   
	// Agrega el estado creado a la instancia del manejador de sonidos
	osgAL::SoundManager::instance()->addSoundState(sound_state.get());

	
	// Se crea un nodo de sonido con el estado configurado
	osg::ref_ptr<osgAL::SoundNode> sound = new osgAL::SoundNode;
	sound->setSoundState(sound_state);

	ssvector.push_back(sound_state.get());

	return sound.get();
}
// Crea y configura un sonido puntual para la colision
osg::ref_ptr<osgAL::SoundNode> SoundHandler::createBotonSound(const std::string& file, const std::string& sname)
{
	// Carga el archivo de sonido
	openalpp::Sample *sample = new openalpp::Sample(file.c_str());

	// Crea un estado para el sonido
	osg::ref_ptr<osgAL::SoundState> sound_state = new osgAL::SoundState(sname.c_str());

	// Se asigna el sonido al estado
	sound_state->setSample(sample);

	// Se configura la ganancia (volumen) en 0.9
	sound_state->setGain(1.0f);

	// Se configura  el pitch en 1 (velocidad normal)
	sound_state->setPitch(1);

	// Reproduccion del sonido
	sound_state->setPlay(false);

	// Se configura un loop de sonido
	sound_state->setLooping(false);

	// Se crea una fuente para el sonido y se define su prioridad
	sound_state->allocateSource(10, false);

	// A una distancia de 50 unidades la ganacia sera 
	// la mitad de su valor maximo
	sound_state->setReferenceDistance(50);
	sound_state->setRolloffFactor(4);

	
	sound_state->apply();
   
	// Agrega el estado creado a la instancia del manejador de sonidos
	osgAL::SoundManager::instance()->addSoundState(sound_state.get());

	
	// Se crea un nodo de sonido con el estado configurado
	osg::ref_ptr<osgAL::SoundNode> sound = new osgAL::SoundNode;
	sound->setSoundState(sound_state);

	ssvector.push_back(sound_state.get());

	return sound.get();
}

// Crea y configura un sonido ambiental
osg::ref_ptr<osgAL::SoundNode> SoundHandler::createAmbientSound(const std::string& file, const std::string& sname)
{
	openalpp::Sample *sample = new openalpp::Sample(file.c_str());

	// Configuracion, ver sonido puntual
	osg::ref_ptr<osgAL::SoundState> sound_state = new osgAL::SoundState(sname.c_str());
	sound_state->setSample(sample);
	sound_state->setGain(0.3f);
	sound_state->setPitch(1);
	sound_state->setPlay(true);
	sound_state->setLooping(true);
	sound_state->allocateSource(10, false);
	// Se activa la bandera de sonido ambiental
	sound_state->setAmbient(true);
	
	sound_state->apply();
   
	osgAL::SoundManager::instance()->addSoundState(sound_state.get());

	osg::ref_ptr<osgAL::SoundNode> sound = new osgAL::SoundNode;
	sound->setSoundState(sound_state);

	ssvector.push_back(sound_state.get());

	return sound.get();
}