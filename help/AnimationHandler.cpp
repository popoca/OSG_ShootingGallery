#include "AnimationHandler.h"

AnimationHandler::AnimationHandler()
{
	//chestBoneID = -1;
	//rhandBoneID = -1;
}

AnimationHandler::~AnimationHandler()
{
}

osgCal::Model* AnimationHandler::makeModel( osgCal::CoreModel* cm, osgCal::BasicMeshAdder* ma)
{
    osgCal::Model* model = new osgCal::Model();
	// Agrega el modelo base y el 
    model->load( cm, ma );

    return model;
}

osgCal::Model* AnimationHandler::createPlayerModel(const std::string& file)
{
		// Modelo base
		coreModel = new osgCal::CoreModel();
		// Clase para agregar las mallas
        osg::ref_ptr< osgCal::BasicMeshAdder > meshAdder( new osgCal::DefaultMeshAdder );
		// Clase para configurar los parametros del modelo
        osg::ref_ptr< osgCal::MeshParameters > p( new osgCal::MeshParameters );
 
		// Skinning por software
        p->software = true;
		// Carga del modelo base
        //coreModel->load( "../femSoldier/femSoldier.cfg", p.get() );  
		coreModel->load( file.c_str(), p.get() ); 

		myModel = makeModel( coreModel.get(), meshAdder.get());
		
		// Animacion de inicio
		curanim = 1;
	
		// Inicia el ciclo de animacion
		myModel->blendCycle( curanim, 1.0f, 1.0f );
		
		// se obtienen los indices de los huesos de la mano y el torso
		//chestBoneID = coreModel->getCalCoreModel()->getBoneId("Bip01 Spine03");
		//rhandBoneID = coreModel->getCalCoreModel()->getBoneId("Bip01 R Hand01");

		// Se guarda la referencia al modelo de cal3d
		osgCal::ModelData *mModelData = (osgCal::ModelData*) myModel->getModelData();
		cModel = mModelData->getCalModel();

		return myModel;
}

void AnimationHandler::changePlayerAnimation(int c0, float delay)
{
	// Se detiene el ciclo de animacion actual
	myModel->clearCycle( curanim, delay );
	myModel->clearCycle( 1, delay );

	// se establece la nueva animacion
	curanim = c0;
	
	// Inicia el nuevo ciclo de animacion
	// En este ejemplo siempre hacemos blending con la animacion 0
	// Con el unico proposito de que el movimiento del personaje sea
	// mas suave
	myModel->blendCycle( c0, 0.6f, delay);
	myModel->blendCycle( 1, 0.6f, delay);
    
}
//osg::Matrix AnimationHandler::playerChestPAT()
//{
//	// A traves del modelo de cal3d se obtiene la referencia 
//	// al hueso del torso 
//	cBone = cModel->getSkeleton()->getBone(chestBoneID);
//	
//	// Rotacion y traslacion del hueso
//	CalVector tmpvec = cBone->getTranslationAbsolute();
//	CalQuaternion tmpquat = cBone->getRotationAbsolute();
//	
//	// Creacion de la matriz para aplicar la transformacion
//	tmpquat.invert();
//	chestMatrix = osg::Matrix::translate(osg::Vec3(tmpvec.x, tmpvec.y, tmpvec.z));	
//	chestMatrix.preMult(osg::Matrix::rotate(osg::Quat(tmpquat.x, tmpquat.y, tmpquat.z, tmpquat.w)));
//	
//	return chestMatrix;
//}

//osg::Matrix AnimationHandler::playerRHandPAT()
//{
//	// A traves del modelo de cal3d se obtiene la referencia 
//	// al hueso de la mano
//	rhBone = cModel->getSkeleton()->getBone(rhandBoneID);
//	
//	// Rotacion y traslacion del hueso
//	CalVector tmpvec = rhBone->getTranslationAbsolute();
//	CalQuaternion tmpquat = rhBone->getRotationAbsolute();
//
//	// Creacion de la matriz para aplicar la transformacion
//	tmpquat.invert();
//	rhandMatrix = osg::Matrix::translate(osg::Vec3(tmpvec.x, tmpvec.y, tmpvec.z));	
//	rhandMatrix.preMult(osg::Matrix::rotate(osg::Quat(tmpquat.x, tmpquat.y, tmpquat.z, tmpquat.w)));
//	
//	return rhandMatrix;
//}