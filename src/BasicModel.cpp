#include "BasicModel.h"

using namespace std;

BasicModel::BasicModel( const char* file, const char* name )
{
	mNode = osgDB::readNodeFile( file );
	if( mNode )
	{
		mState = mNode->getOrCreateStateSet();
		mNode->setName( name );
		// Se activa la prueba de culling para las caras posteriores
		mCull = new osg::CullFace();
		mCull->setMode( osg::CullFace::BACK );
		// Se define la funcion de profundidad
		mDepth = new osg::Depth();
		mDepth->setFunction( osg::Depth::LEQUAL );
		// Agreguemos todo al StateSet
		mState->setAttribute( mCull );
		mState->setAttribute( mDepth );
		// Declaramos nuestro PAT
		mPat = new osg::PositionAttitudeTransform();
		mPat->addChild( mNode.get() );
	}
	cout << "Cargando modelo: " << file << endl;
}

BasicModel::~BasicModel()
{
}