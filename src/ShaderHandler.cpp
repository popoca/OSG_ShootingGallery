#include "ShaderHandler.h"
#include "FindNodeVisitor.h"

ShaderHandler::ShaderHandler()
{
	_shadersList.resize(1);
	_shadersList[0] = new osg::Program();
	_vertexList.resize(1);
	_vertexList[0] = new osg::Shader( osg::Shader::VERTEX );
	_fragmentList.resize(1);
	_fragmentList[0] = new osg::Shader( osg::Shader::FRAGMENT );
	_shadersList[0]->addShader(_vertexList[0]);
	_shadersList[0]->addShader(_fragmentList[0]);
	_shadersList[0]->setName( "BumpMappingShader" );
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
	_shadersList[1]->setName( "IlluminationShader" );
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
	_shadersList[2]->setName( "aOShader" );
	_vertexList[2]->loadShaderSourceFromFile( "../shaders/st.vert" );
	_fragmentList[2]->loadShaderSourceFromFile( "../shaders/st.frag" );
}

ShaderHandler::~ShaderHandler(){};

void ShaderHandler::BumpMappingShader(osg::Node* node)
{
	osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();

	nodeState->addUniform( new osg::Uniform( "colorMap", 0 ) );
	nodeState->addUniform( new osg::Uniform( "normalMap", 1 ) );
 

	osg::ref_ptr<FindNodeVisitor> fnv = new FindNodeVisitor("Geode");
	//nodeState->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	node->accept(*(fnv.get()));
	//std::cout<<fnv->foundNodeList.size()<<std::endl;

	std::vector<osg::Node*>::iterator giter;
	for(giter = fnv->foundNodeList.begin(); giter != fnv->foundNodeList.end(); giter++)
	{
		osg::Geode* tmpgeode = dynamic_cast<osg::Geode*>(*giter);
		for(unsigned int i = 0; i< tmpgeode->getNumDrawables(); i++)
		{
			osg::StateSet *tmpstate = tmpgeode->getDrawable(i)->getOrCreateStateSet();
			tmpstate->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
		
		//}

			osg::Geometry *tmpGeo = dynamic_cast<osg::Geometry *>(tmpgeode->getDrawable(0));

			osg::Material *material = new osg::Material();
			material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0.6f,0.6f,0.6f,1.0f));
			material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0.6f,0.6f,0.6f,1.0f));
			material->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(0.6f,0.6f,0.6f,1.0f));
			material->setShininess(osg::Material::FRONT_AND_BACK, 120.0f);
			tmpstate->setAttribute(material, osg::StateAttribute::ON);

			osgUtil::TangentSpaceGenerator *tsg = new osgUtil::TangentSpaceGenerator();
			tsg->generate(tmpGeo, 1);
			osg::Vec4Array *a_tangent = tsg->getTangentArray();
			tmpGeo->setVertexAttribArray(6, a_tangent);
			tmpGeo->setVertexAttribBinding(6, osg::Geometry::BIND_PER_VERTEX);
			_shadersList[1]->addBindAttribLocation("vTangent", 6);
		
		}	
		nodeState->setAttributeAndModes(_shadersList[0],osg::StateAttribute::ON);
	}
}

void ShaderHandler::IlluminationShader(osg::Node* node)
{
	osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();

	nodeState->addUniform( new osg::Uniform( "colorMap", 0 ) );
	nodeState->addUniform( new osg::Uniform( "ambientO", 2 ) );


	osg::ref_ptr<FindNodeVisitor> fnv = new FindNodeVisitor("Geode");
	//nodeState->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	node->accept(*(fnv.get()));
	//std::cout<<fnv->foundNodeList.size()<<std::endl;

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

void ShaderHandler::aOShader(osg::Node* node)
{
	osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();

	//nodeState->addUniform( new osg::Uniform("Environment", 3) );
	nodeState->addUniform( new osg::Uniform( "colorMap", 1 ) );
	//nodeState->addUniform( new osg::Uniform( "ambientO", 1 ) );
	nodeState->addUniform( new osg::Uniform( "normalMap", 3 ) );
	//osg::Uniform* tsUniform   = new osg::Uniform( "time_scale", 4.0f );
	//osg::Uniform* t2piUniform   = new osg::Uniform( "time_0_2PI", 0.0f );
 

	osg::ref_ptr<FindNodeVisitor> fnv = new FindNodeVisitor("Geode");
	//nodeState->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	node->accept(*(fnv.get()));
	//std::cout<<fnv->foundNodeList.size()<<std::endl;

	std::vector<osg::Node*>::iterator giter;
	for(giter = fnv->foundNodeList.begin(); giter != fnv->foundNodeList.end(); giter++)
	{
		osg::Geode* tmpgeode = dynamic_cast<osg::Geode*>(*giter);
		for(unsigned int i = 0; i< tmpgeode->getNumDrawables(); i++)
		{
			osg::StateSet *tmpstate = tmpgeode->getDrawable(i)->getOrCreateStateSet();
			tmpstate->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
		
		//}

			osg::Geometry *tmpGeo = dynamic_cast<osg::Geometry *>(tmpgeode->getDrawable(0));

			osg::Material *material = new osg::Material();
			material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0.0f,0.0f,0.0f,1.0f));
			material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(1.0f,1.0f,1.0f,1.0f));
			material->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(0.7f,0.7f,0.7f,1.0f));
			material->setShininess(osg::Material::FRONT_AND_BACK, 40.0f);
			tmpstate->setAttribute(material, osg::StateAttribute::ON);
		}	
		nodeState->setAttributeAndModes(_shadersList[2],osg::StateAttribute::ON);
	}
}