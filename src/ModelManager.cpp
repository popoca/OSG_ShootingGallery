#include "ModelManager.h"

using namespace std;

ModelManager::ModelManager( osg::ref_ptr< osg::Group > rt )
: root( rt )
{
	bg.reserve( 9 );
}

ModelManager::~ModelManager()
{	
}

void ModelManager::setUpScene()
{
	for( int i = 0; i < (int)bg.size(); i++ )
	{
		root->addChild( bg[i]->mMat.get() );
	}

	bg.clear();

	if( bg.empty() )
		cout << "Escenario cargado" << endl;
}