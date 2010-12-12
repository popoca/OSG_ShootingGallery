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