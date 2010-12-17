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

		if( en[i]->hasSpawned )
		{
			en[i]->killTime -= delta;
		}

		// si le damos a un enemigo
		if( !strcmp( en[i]->mNode->getName().c_str(), "X" ) || en[i]->killTime < 0 )
		{
			// y no estamos explotando
			if( !en[i]->fluxing )
			{
				// 88mph
				//en[i]->fluxCapacitor();
				// cambia el modelo por el de la explosion
				en[i]->mPat->replaceChild( en[i]->mNode, en[i]->mNodeXplode );
				en[i]->mPat->addChild( en[i]->emitter );
				en[i]->fluxing = true;
			}
			else
			{
				if ( en[i]->eraseTime < 3.5 )
				{
					en[i]->mPat->removeUpdateCallback( en[i]->mPat->getUpdateCallback() );
				}
				if( en[i]->eraseTime >= 0 )
				{
					en[i]->eraseTime -= 0.1f;
				}
				else
				{
					//en[i]->unfluxCapacitor();
					en[i]->mPat->removeChild( en[i]->mNodeXplode );
					root->removeChild( en[i]->mPat.get() );
					en.erase( en.begin() + i );
				}
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