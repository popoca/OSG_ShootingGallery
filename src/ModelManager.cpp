#include "ModelManager.h"

using namespace std;

ModelManager::ModelManager( osg::ref_ptr< osg::Group > rt )
: root( rt ), end( false ), currTime( 0 )
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
	// Aumenta el tiempo actual
	currTime += delta;

	// Para cada enemigo
	for( int i = 0; i < (int)en.size(); i++ )
	{
		// si no ha spawneado, y ya es hora de spawnear
		if( currTime > en[i]->spawnTime && !en[i]->hasSpawned )
		{
			root->addChild( en[i]->mPat.get() );
			en[i]->hasSpawned = true;
		}

		if( !strcmp( en[i]->mNode->getName().c_str(), "X" ) )
		{

			en[i]->mPat->replaceChild( en[i]->mNode, en[i]->mNodeXplode );
			if( en[i]->eraseTime >= 0 )
			{
				en[i]->eraseTime -= 0.1f;
			}
			else
			{
				en[i]->mPat->removeChild( en[i]->mNodeXplode );
				//mPat->addChild( mNodeXplode.get() );
				en.erase( en.begin() + i );
			}
		}
	}

	if( en.empty() && !end )
	{
		cout << "Todos los enemigos han sido eliminados" << endl;
		currTime = 0;
		end = true;
	}

}