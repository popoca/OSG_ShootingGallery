#include  "HUDHandler.h"

using namespace std;

HUDHandler::HUDHandler(osg::ref_ptr<osg::Group> rootNode)
{
	SCORE = 0;
	MAX = 5;
	currentBullets = MAX;
	root = rootNode;
	init_text();
	initDisplayMessage();
	init_images();
	init_general();
	HUDGeode->addDrawable(scoreText);
	//achievePork();
	//achieveBird();
	
}

HUDHandler::~HUDHandler(){}

void HUDHandler::init_text()
{
	scoreText = new osgText::Text();
	scoreText->setCharacterSize(25);
	scoreText->setFont("../content/font/font.ttf");
	scoreText->setText("SCORE\t0");
	scoreText->setPosition( osg::Vec3(700,800,0) );
	scoreText->setColor( osg::Vec4(255, 255, 255, 1) );
	
}

void HUDHandler::initDisplayMessage()
{
	messageText = new osgText::Text();
	messageText->setCharacterSize(45);
	messageText->setFont("../content/font/font.ttf");
	messageText->setPosition( osg::Vec3(200,400,0) );
	messageText->setColor( osg::Vec4(255, 255, 255, 1) );
	
}
void HUDHandler::showMessage(const char* message)
{
	messageText->setText(message);
	HUDGeode->addDrawable(messageText);
}

void HUDHandler::quitMessage()
{
	HUDGeode->removeDrawable(messageText);
}


void HUDHandler::init_images()
{
	bullet1 = osgDB::readImageFile("../content/bullet.tga");
	bullet2 = osgDB::readImageFile("../content/bullet2.tga");
	cursor = osgDB::readImageFile("../content/crosshair.tga");
}
void HUDHandler::init_general()
{

	HUDGeode = new osg::Geode();
	HUDProjectionMatrix = new osg::Projection;
	HUDProjectionMatrix->setMatrix(osg::Matrix::ortho2D(0,1024,0,860));
	

	
	HUDModelViewMatrix = new osg::MatrixTransform;
	HUDModelViewMatrix->setMatrix(osg::Matrix::identity());
	HUDModelViewMatrix->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	
	root->addChild(HUDProjectionMatrix);
	
	HUDProjectionMatrix->addChild(HUDModelViewMatrix);
	HUDModelViewMatrix->addChild( HUDGeode );
	
	HUDBackgroundGeometry = new osg::Geometry();
	HUDBackgroundVertices = new osg::Vec3Array;
    HUDBackgroundVertices->push_back( osg::Vec3( 0,    0,-1) );
    HUDBackgroundVertices->push_back( osg::Vec3(1024,  0,-1) );
    HUDBackgroundVertices->push_back( osg::Vec3(1024,0,-1) );
    HUDBackgroundVertices->push_back( osg::Vec3(   0,0,-1) );
	HUDBackgroundIndices = new osg::DrawElementsUInt(osg::PrimitiveSet::POLYGON, 0);
    HUDBackgroundIndices->push_back(0);
    HUDBackgroundIndices->push_back(1);
    HUDBackgroundIndices->push_back(2);
    HUDBackgroundIndices->push_back(3);
    
	HUDcolors = new osg::Vec4Array;
	HUDcolors->push_back(osg::Vec4(0.8f,0.8f,0.8f,0.8f));
	texcoords = new osg::Vec2Array(4);
	
    (*texcoords)[0].set(0.0f,0.0f);
    (*texcoords)[1].set(1.0f,0.0f);
    (*texcoords)[2].set(1.0f,1.0f);
    (*texcoords)[3].set(0.0f,1.0f);
    
      
    
    HUDBackgroundGeometry->setTexCoordArray(0,texcoords);
	HUDTexture = new osg::Texture2D;
	
	
	
	HUDTexture->setDataVariance(osg::Object::DYNAMIC);
	HUDTexture->setImage(bullet2);
	
	HUDnormals = new osg::Vec3Array;
    HUDnormals->push_back(osg::Vec3(0.0f,0.0f,1.0f));
    HUDBackgroundGeometry->setNormalArray(HUDnormals);
    HUDBackgroundGeometry->setNormalBinding(osg::Geometry::BIND_OVERALL);
    HUDBackgroundGeometry->addPrimitiveSet(HUDBackgroundIndices);
    HUDBackgroundGeometry->setVertexArray(HUDBackgroundVertices);
    HUDBackgroundGeometry->setColorArray(HUDcolors);
    HUDBackgroundGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	HUDGeode->addDrawable(HUDBackgroundGeometry);
	HUDStateSet = new osg::StateSet();
    HUDStateSet->setTextureAttributeAndModes(0,HUDTexture,osg::StateAttribute::ON);
    HUDStateSet->setMode(GL_BLEND,osg::StateAttribute::ON);
    HUDStateSet->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);
    HUDStateSet->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );
    HUDStateSet->setRenderBinDetails( 11, "RenderBin");
	
}
void HUDHandler::setupBulletsHUD()
{
	
}
void HUDHandler::shoot()
{
	if(currentBullets == 0)
		reload();
}

void HUDHandler::reload(/*Time variable here*/)
{
	/*
	 * 	Time stuff here
	 */
	currentBullets = MAX;
	
}
void HUDHandler::achieveBird()
{
	SCORE += 10;
	updateScore();
	
}
void HUDHandler::achievePork()
{
	SCORE += 15;
	updateScore();
}
void HUDHandler::achieveRabbit()
{
	SCORE += 20;
	updateScore();
}
void HUDHandler::updateScore()
{
	ostringstream os;
	os<<SCORE;
	string s = os.str();
	string G = "SCORE\t";
	scoreText->setText(G+s);
}
osg::Geode* HUDHandler::getGeode()
{
	return HUDGeode;
}
	
