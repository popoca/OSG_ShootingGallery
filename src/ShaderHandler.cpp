#include "ShaderHandler.h"
#include "FindNodeVisitor.h"
#include <osg/Depth>
#include <osg/TexEnv>
#include <osg/Texture2D>
#include <osgDB/ReadFile>
#include <osgDB/FileUtils>
#include <osgViewer/Viewer>
#include <osg/TexGen>
#include <osg/StateSet>

ShaderHandler::ShaderHandler()
{
	//cambiando code?
	_shadersList.resize(1);
	_shadersList[0] = new osg::Program();
	_vertexList.resize(1);
	_vertexList[0] = new osg::Shader( osg::Shader::VERTEX );
	_fragmentList.resize(1);
	_fragmentList[0] = new osg::Shader( osg::Shader::FRAGMENT );
	_shadersList[0]->addShader(_vertexList[0]);
	_shadersList[0]->addShader(_fragmentList[0]);
	_shadersList[0]->setName( "transAOShader" );
	_vertexList[0]->loadShaderSourceFromFile( "../shaders/ppillu.vert" );
	_fragmentList[0]->loadShaderSourceFromFile( "../shaders/ppillu.frag" );

	_shadersList.resize(2);
	_shadersList[1] = new osg::Program();
	_vertexList.resize(2);
	_vertexList[1] = new osg::Shader( osg::Shader::VERTEX );
	_fragmentList.resize(2);
	_fragmentList[1] = new osg::Shader( osg::Shader::FRAGMENT );
	_shadersList[1]->addShader(_vertexList[1]);
	_shadersList[1]->addShader(_fragmentList[1]);
	_shadersList[1]->setName( "difShader" );
	_vertexList[1]->loadShaderSourceFromFile( "../shaders/illu.vert" );
	_fragmentList[1]->loadShaderSourceFromFile( "../shaders/illu.frag" );

	_shadersList.resize(3);
	_shadersList[2] = new osg::Program();
	_vertexList.resize(3);
	_vertexList[2] = new osg::Shader( osg::Shader::VERTEX );
	_fragmentList.resize(3);
	_fragmentList[2] = new osg::Shader( osg::Shader::FRAGMENT );
	_shadersList[2]->addShader(_vertexList[2]);
	_shadersList[2]->addShader(_fragmentList[2]);
	_shadersList[2]->setName( "BumpMappingShader" );
	_vertexList[2]->loadShaderSourceFromFile( "../shaders/ppillu2.vert" );
	_fragmentList[2]->loadShaderSourceFromFile( "../shaders/ppillu2.frag" );


	_shadersList.resize(4);
	_shadersList[3] = new osg::Program();
	_vertexList.resize(4);
	_vertexList[3] = new osg::Shader( osg::Shader::VERTEX );
	_fragmentList.resize(4);
	_fragmentList[3] = new osg::Shader( osg::Shader::FRAGMENT );
	_shadersList[3]->addShader(_vertexList[3]);
	_shadersList[3]->addShader(_fragmentList[3]);
	_shadersList[3]->setName( "aoShader" );
	_vertexList[3]->loadShaderSourceFromFile( "../shaders/ppillu.vert" );
	_fragmentList[3]->loadShaderSourceFromFile( "../shaders/ppillu.frag" );

	_shadersList.resize(5);
	_shadersList[4] = new osg::Program();
	_vertexList.resize(5);
	_vertexList[4] = new osg::Shader( osg::Shader::VERTEX );
	_fragmentList.resize(5);
	_fragmentList[4] = new osg::Shader( osg::Shader::FRAGMENT );
	_shadersList[4]->addShader(_vertexList[4]);
	_shadersList[4]->addShader(_fragmentList[4]);
	_shadersList[4]->setName( "bumpMap2Shader" );
	_vertexList[4]->loadShaderSourceFromFile( "../shaders/ppillu.vert" );
	_fragmentList[4]->loadShaderSourceFromFile( "../shaders/ppillu.frag" );

}

ShaderHandler::~ShaderHandler(){};

void ShaderHandler:: transAOShader(osg::Node* node)
{
	osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();

	nodeState->addUniform( new osg::Uniform( "colorMap", 0 ));
	nodeState->addUniform( new osg::Uniform( "ambientO", 0 ) );


	osg::ref_ptr<FindNodeVisitor> fnv = new FindNodeVisitor("Geode");
	nodeState->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	node->accept(*(fnv.get()));

	std::vector<osg::Node*>::iterator giter;
	for(giter = fnv->foundNodeList.begin(); giter != fnv->foundNodeList.end(); giter++)
	{
		osg::Geode* tmpgeode = dynamic_cast<osg::Geode*>(*giter);
		for(unsigned int i = 0; i< tmpgeode->getNumDrawables(); i++)
		{
			osg::StateSet *tmpstate = tmpgeode->getDrawable(i)->getOrCreateStateSet();
			tmpstate->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
			tmpstate->setMode( GL_BLEND, osg::StateAttribute::ON );
			tmpstate->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );

			//--------Para activa el otro tipo de transparencia
			osg::Depth* depth = new osg::Depth;
			depth->setWriteMask( false );

			tmpstate->setAttributeAndModes( depth, osg::StateAttribute::ON );

			// Disable conflicting modes.
			tmpstate->setMode( GL_LIGHTING, osg::StateAttribute::OFF );

			osg::Geometry *tmpGeo = dynamic_cast<osg::Geometry *>(tmpgeode->getDrawable(0));

			osg::Material *material = new osg::Material();
			material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
			material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
			material->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(0.4f, 0.4f, 0.4f, 1.0f));
			material->setShininess(osg::Material::FRONT_AND_BACK, 60.0f);
			tmpstate->setAttribute(material, osg::StateAttribute::ON);
		}
	}

	nodeState->setAttributeAndModes(_shadersList[0],osg::StateAttribute::ON);
}

void ShaderHandler::difShader(osg::Node* node)
{
	osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();

	nodeState->addUniform( new osg::Uniform( "colorMap", 0 ) );
	nodeState->addUniform( new osg::Uniform( "ambientO", 2 ) );


	osg::ref_ptr<FindNodeVisitor> fnv = new FindNodeVisitor("Geode");
	//nodeState->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	node->accept(*(fnv.get()));

	std::vector<osg::Node*>::iterator giter;
	for(giter = fnv->foundNodeList.begin(); giter != fnv->foundNodeList.end(); giter++)
	{
		osg::Geode* tmpgeode = dynamic_cast<osg::Geode*>(*giter);
		for(unsigned int i = 0; i< tmpgeode->getNumDrawables(); i++)
		{
			osg::StateSet *tmpstate = tmpgeode->getDrawable(i)->getOrCreateStateSet();
			tmpstate->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
		

			//osg::Geometry *tmpGeo = dynamic_cast<osg::Geometry *>(tmpgeode->getDrawable(0));

			osg::Material *material = new osg::Material();
			material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0.9f, 0.9f, 0.9f, 1.0f));
			material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0.9f, 0.9f, 0.9f, 1.0f));
			material->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(0.2f, 0.2f, 0.2f, 1.0f));
			material->setShininess(osg::Material::FRONT_AND_BACK, 60.0f);
			tmpstate->setAttribute(material, osg::StateAttribute::ON);

		}
	
	}

	nodeState->setAttributeAndModes(_shadersList[1],osg::StateAttribute::ON);
}

void ShaderHandler::BumpMappingShader(osg::Node* node)
{
	osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();

	nodeState->addUniform( new osg::Uniform( "colorMap", 3 ) );
	nodeState->addUniform( new osg::Uniform( "normalMap", 1 ) );
 

	osg::ref_ptr<FindNodeVisitor> fnv = new FindNodeVisitor("Geode");
	//nodeState->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	node->accept(*(fnv.get()));

	std::vector<osg::Node*>::iterator giter;
	for(giter = fnv->foundNodeList.begin(); giter != fnv->foundNodeList.end(); giter++)
	{
		osg::Geode* tmpgeode = dynamic_cast<osg::Geode*>(*giter);
		for(unsigned int i = 0; i< tmpgeode->getNumDrawables(); i++)
		{
			osg::StateSet *tmpstate = tmpgeode->getDrawable(i)->getOrCreateStateSet();
			tmpstate->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);

			osg::Geometry *tmpGeo = dynamic_cast<osg::Geometry *>(tmpgeode->getDrawable(0));

			osg::Material *material = new osg::Material();
			material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0.7f,0.7f,0.0f,1.0f));
			material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0.7f,0.7f,0.0f,1.0f));
			material->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(0.5f,0.5f,0.5f,1.0f));
			material->setShininess(osg::Material::FRONT_AND_BACK, 128.0f);
			tmpstate->setAttribute(material, osg::StateAttribute::ON);

			//osgUtil::TangentSpaceGenerator *tsg = new osgUtil::TangentSpaceGenerator();
			//tsg->generate(tmpGeo, 1);
			//osg::Vec4Array *a_tangent = tsg->getTangentArray();
			//tmpGeo->setVertexAttribArray(6, a_tangent);
			//tmpGeo->setVertexAttribBinding(6, osg::Geometry::BIND_PER_VERTEX);
			//_shadersList[1]->addBindAttribLocation("vTangent", 6);
		
		}	
		nodeState->setAttributeAndModes(_shadersList[2],osg::StateAttribute::ON);
	}
}

void ShaderHandler:: aoShader(osg::Node* node)
{
	osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();

	nodeState->addUniform( new osg::Uniform( "colorMap", 0 ));
	nodeState->addUniform( new osg::Uniform( "normalMap", 1 ));
	nodeState->addUniform( new osg::Uniform( "ambientO", 0 ) );


	osg::ref_ptr<FindNodeVisitor> fnv = new FindNodeVisitor("Geode");
	nodeState->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	node->accept(*(fnv.get()));

	std::vector<osg::Node*>::iterator giter;
	for(giter = fnv->foundNodeList.begin(); giter != fnv->foundNodeList.end(); giter++)
	{
		osg::Geode* tmpgeode = dynamic_cast<osg::Geode*>(*giter);
		for(unsigned int i = 0; i< tmpgeode->getNumDrawables(); i++)
		{
			osg::StateSet *tmpstate = tmpgeode->getDrawable(i)->getOrCreateStateSet();
			tmpstate->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);

			osg::Material *material = new osg::Material();
			material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
			material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
			material->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(0.4f, 0.4f, 0.4f, 1.0f));
			material->setShininess(osg::Material::FRONT_AND_BACK, 60.0f);
			tmpstate->setAttribute(material, osg::StateAttribute::ON);
		}
	}

	nodeState->setAttributeAndModes(_shadersList[3],osg::StateAttribute::ON);
}
void ShaderHandler::bumpMap2Shader(osg::Node* node)
{
	osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();

	nodeState->addUniform( new osg::Uniform( "colorMap", 0 ) );
	nodeState->addUniform( new osg::Uniform( "normalMap", 1 ) );
	nodeState->addUniform( new osg::Uniform( "ambientO", 2 ) );
 

	osg::ref_ptr<FindNodeVisitor> fnv = new FindNodeVisitor("Geode");
	//nodeState->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	node->accept(*(fnv.get()));

	std::vector<osg::Node*>::iterator giter;
	for(giter = fnv->foundNodeList.begin(); giter != fnv->foundNodeList.end(); giter++)
	{
		osg::Geode* tmpgeode = dynamic_cast<osg::Geode*>(*giter);
		for(unsigned int i = 0; i< tmpgeode->getNumDrawables(); i++)
		{
			osg::StateSet *tmpstate = tmpgeode->getDrawable(i)->getOrCreateStateSet();
			tmpstate->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);

			osg::Geometry *tmpGeo = dynamic_cast<osg::Geometry *>(tmpgeode->getDrawable(0));

			osg::Material *material = new osg::Material();
			material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0.45f,0.45f,0.45f,1.0f));
			material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0.7f,0.7f,0.7f,1.0f));
			material->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(0.7f,0.7f,0.7f,1.0f));
			material->setShininess(osg::Material::FRONT_AND_BACK, 128.0f);
			tmpstate->setAttribute(material, osg::StateAttribute::ON);

			osgUtil::TangentSpaceGenerator *tsg = new osgUtil::TangentSpaceGenerator();
			tsg->generate(tmpGeo, 1);
			osg::Vec4Array *a_tangent = tsg->getTangentArray();
			tmpGeo->setVertexAttribArray(6, a_tangent);
			tmpGeo->setVertexAttribBinding(6, osg::Geometry::BIND_PER_VERTEX);
			_shadersList[4]->addBindAttribLocation("vTangent", 6);
		
		}	
		nodeState->setAttributeAndModes(_shadersList[4],osg::StateAttribute::ON);
	}
}