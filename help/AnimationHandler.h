#ifndef _ANIMATIONHANDLER_
#define _ANIMATIONHANDLER_

#include <osg/MatrixTransform>
#include <osgCal/CoreModel>
#include <osgCal/Model>

class AnimationHandler: public osg::Referenced
{
public:
	AnimationHandler();
	~AnimationHandler();
	// Carga el modelo animado desde un archivo de configuracion
	// para agregar al grafo de escena
	osgCal::Model* createPlayerModel(const std::string& file);
	// Cambia la animacion actual a la animacion c0 en el intervalo
	// de tiempo indicado por delay
	void changePlayerAnimation(int c0, float delay);
	// Obtiene la matriz de tranformacion del torso del personaje
	//osg::Matrix playerChestPAT();
	// Obtiene la matriz de tranformacion de la mano derecha
	//osg::Matrix playerRHandPAT();

private:
	osgCal::Model* makeModel( osgCal::CoreModel* cm, osgCal::BasicMeshAdder* ma);

	osgCal::Model *myModel;
	osg::Matrix chestMatrix, rhandMatrix;
	osg::ref_ptr< osgCal::CoreModel > coreModel;
	//int chestBoneID, rhandBoneID;
	int curanim;

	CalModel *cModel;
	//CalBone *cBone, *rhBone;
	//CalMatrix
};

#endif
