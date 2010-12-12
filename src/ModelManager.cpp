#include "ModelManager.h"

using namespace std;

ModelManager::ModelManager( osg::ref_ptr< osg::Group > rt )
: root( rt ), init( false ), currTime( 0 )
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
		cout << "Escenario cargado en root" << endl;
}

void ModelManager::updateScene( double delta )
{
	if( !init )
	{
		currTime += delta;

		for( int i = 0; i < (int)en.size(); i++ )
		{
			if( currTime > en[i]->spawnTime )
			{
				root->addChild( en[i]->mPat.get() );
				en.erase( en.begin() + i );
			}
		}

		if( en.empty() )
		{
			cout << "Todos los enemigos han sido eliminados" << endl;
			currTime = 0;
			init = true;
		}

	}

}