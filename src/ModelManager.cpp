#include "ModelManager.h"

using namespace std;

ModelManager::ModelManager( osg::ref_ptr< osg::Group > rt )
: root( rt ), init( false )
{
	bg.reserve( 9 );
	en.reserve( 5 );
}

ModelManager::~ModelManager()
{	
}

void ModelManager::setUpScene()
{
	for( int i = 0; i < (int)bg.size(); i++ )
	{
		root->addChild( bg[i]->mPat.get() );
	}

	bg.clear();

	if( bg.empty() )
		cout << "Escenario cargado" << endl;
}

void ModelManager::updateScene()
{
	if( !init )
	{
		for( int i = 0; i < (int)en.size(); i++ )
		{
			root->addChild( en[i]->mPat.get() );
		}

		en.clear();

		if( en.empty() )
			cout << "Enemigos cargados" << endl;

		init = true;
	}

}