#include "BasicModel.h"

using namespace std;

BasicModel::BasicModel( const char* file )
{
	mNode = osgDB::readNodeFile( file );
	if( mNode )
	{
		mNode->setName( file );
		mState = mNode->getOrCreateStateSet();
		// Se activa la prueba de culling para las caras posteriores
		mCull = new osg::CullFace();
		mCull->setMode( osg::CullFace::BACK );
		// Se define la funcion de profundidad
		mDepth = new osg::Depth();
		mDepth->setFunction( osg::Depth::LEQUAL );
		mMat = new osg::MatrixTransform();
		mMat->addChild( mNode.get() );
	}
	cout << "Cargando modelo: " << file << endl;
}

BasicModel::~BasicModel()
{
}