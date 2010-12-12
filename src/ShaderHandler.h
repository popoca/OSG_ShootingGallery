#ifndef _SHADERHANDLER_
#define _SHADERHANDLER_

#include <osg/Program>
#include <osg/Node>
#include <osg/Geode>
#include <osgUtil/TangentSpaceGenerator>
#include <osg/Material>



class ShaderHandler: public osg::Referenced
{
public:

	ShaderHandler();

	~ShaderHandler();

	void BumpMappingShader(osg::Node* node);
	void TextureShader(osg::Node* node);
	void IlluminationShader(osg::Node* node);

private:

	std::vector<osg::Program*> _shadersList;
	std::vector<osg::Shader*> _vertexList;
	std::vector<osg::Shader*> _fragmentList;

};
#endif
