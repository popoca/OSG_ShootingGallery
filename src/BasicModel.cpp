#include "BasicModel.h"

using namespace std;

BasicModel::BasicModel( string& file )
{
	mNode = osgDB::readNodeFile( file );
	
}

BasicModel::~BasicModel()
{
}