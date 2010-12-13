#include  "HUDHandler.h"

using namespace std;

HUDHandler::HUDHandler(osg::ref_ptr<osg::Group> rootNode)
{
	SCORE = 0;
	MAX = 5;
	currentBullets = MAX;
	root = rootNode;
	init_images();
	init_text();
	initDisplayMessage();
	init_general();
	HUDGeode->addDrawable(scoreText);
	osg::Geode* cursor_geode = buildCursor();
	patCursor = new osg::PositionAttitudeTransform();
	patCursor->addChild(cursor_geode);
	HUDModelViewMatrix->addChild(patCursor);
	patCursor->setPosition(osg::Vec3d(100.0f,100.0f,-1.0f));
	osg::Geode* bullet_geode = buildBullets();
	HUDModelViewMatrix->addChild(bullet_geode);
	
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
	bullet = osgDB::readImageFile("../content/bullet.tga");
	bullet1 = osgDB::readImageFile("../content/bullets1.tga");
	bullet2 = osgDB::readImageFile("../content/bullets2.tga");
	bullet3 = osgDB::readImageFile("../content/bullets3.tga");
	bullet4 = osgDB::readImageFile("../content/bullets4.tga");
	bullet5 = osgDB::readImageFile("../content/bullets5.tga");
	bullet6 = osgDB::readImageFile("../content/bullets6.tga");
	cursor = osgDB::readImageFile("../content/crosshair.tga");
	transparent = osgDB::readImageFile("../content/bullet2.tga");
	current_bullet_image = bullet;
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

	//Hasta aqui se define la matriz de vista
}

osg::Geode* HUDHandler::buildBullets()
{
	osg::Geode* bulletBuilt = new osg::Geode();
	 
	       // Set up geometry for the HUD and add it to the HUD
       osg::Geometry* mHUDBackgroundGeometry = new osg::Geometry();

       osg::Vec3Array* mHUDBackgroundVertices = new osg::Vec3Array;
       mHUDBackgroundVertices->push_back( osg::Vec3( 0,    0,-1) );
       mHUDBackgroundVertices->push_back( osg::Vec3(110,  0,-1) );
       mHUDBackgroundVertices->push_back( osg::Vec3(110,128,-1) );
       mHUDBackgroundVertices->push_back( osg::Vec3(   0,128,-1) );

       osg::DrawElementsUInt* mHUDBackgroundIndices =
          new osg::DrawElementsUInt(osg::PrimitiveSet::POLYGON, 0);
       mHUDBackgroundIndices->push_back(0);
       mHUDBackgroundIndices->push_back(1);
       mHUDBackgroundIndices->push_back(2);
       mHUDBackgroundIndices->push_back(3);

       osg::Vec4Array* mHUDcolors = new osg::Vec4Array;
       mHUDcolors->push_back(osg::Vec4(6.0f,6.0f,6.0f,10.0f));

       osg::Vec2Array* mtexcoords = new osg::Vec2Array(4);
       (*mtexcoords)[0].set(0.0f,0.0f);
       (*mtexcoords)[1].set(1.0f,0.0f);
       (*mtexcoords)[2].set(1.0f,1.0f);
       (*mtexcoords)[3].set(0.0f,1.0f);

       mHUDBackgroundGeometry->setTexCoordArray(0,mtexcoords);
       osg::Texture2D* mHUDTexture = new osg::Texture2D;
       mHUDTexture->setDataVariance(osg::Object::DYNAMIC);
       mHUDTexture->setImage(current_bullet_image);
       osg::Vec3Array* mHUDnormals = new osg::Vec3Array;
       mHUDnormals->push_back(osg::Vec3(0.0f,0.0f,1.0f));
       mHUDBackgroundGeometry->setNormalArray(mHUDnormals);
       mHUDBackgroundGeometry->setNormalBinding(osg::Geometry::BIND_OVERALL);
       mHUDBackgroundGeometry->addPrimitiveSet(mHUDBackgroundIndices);
       mHUDBackgroundGeometry->setVertexArray(mHUDBackgroundVertices);
       mHUDBackgroundGeometry->setColorArray(mHUDcolors);
       mHUDBackgroundGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);

		bulletBuilt->addDrawable(mHUDBackgroundGeometry);
		
		 // Create and set up a state set using the texture from above:
       osg::StateSet* mHUDStateSet = new osg::StateSet();
       bulletBuilt->setStateSet(mHUDStateSet);
       mHUDStateSet->
          setTextureAttributeAndModes(0,mHUDTexture,osg::StateAttribute::ON);

       // For this state set, turn blending on (so alpha texture looks right)
       mHUDStateSet->setMode(GL_BLEND,osg::StateAttribute::ON);

       // Disable depth testing so geometry is draw regardless of depth values
       // of geometry already draw.
       mHUDStateSet->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);
       mHUDStateSet->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );

       // Need to make sure this geometry is draw last. RenderBins are handled
       // in numerical order so set bin number to 11
       mHUDStateSet->setRenderBinDetails( 11, "RenderBin");
       
       return bulletBuilt;
}



osg::Geode* HUDHandler::buildCursor()
{
	osg::Geode* bulletBuilt = new osg::Geode();
	 
	       // Set up geometry for the HUD and add it to the HUD
       osg::Geometry* mHUDBackgroundGeometry = new osg::Geometry();

       osg::Vec3Array* mHUDBackgroundVertices = new osg::Vec3Array;
       mHUDBackgroundVertices->push_back( osg::Vec3( 0,    0,-1) );
       mHUDBackgroundVertices->push_back( osg::Vec3(110,  0,-1) );
       mHUDBackgroundVertices->push_back( osg::Vec3(110,128,-1) );
       mHUDBackgroundVertices->push_back( osg::Vec3(   0,128,-1) );

       osg::DrawElementsUInt* mHUDBackgroundIndices =
          new osg::DrawElementsUInt(osg::PrimitiveSet::POLYGON, 0);
       mHUDBackgroundIndices->push_back(0);
       mHUDBackgroundIndices->push_back(1);
       mHUDBackgroundIndices->push_back(2);
       mHUDBackgroundIndices->push_back(3);

       osg::Vec4Array* mHUDcolors = new osg::Vec4Array;
       mHUDcolors->push_back(osg::Vec4(0.6f,0.6f,0.6f,6.0f));

       osg::Vec2Array* mtexcoords = new osg::Vec2Array(4);
       (*mtexcoords)[0].set(0.0f,0.0f);
       (*mtexcoords)[1].set(1.0f,0.0f);
       (*mtexcoords)[2].set(1.0f,1.0f);
       (*mtexcoords)[3].set(0.0f,1.0f);

       mHUDBackgroundGeometry->setTexCoordArray(0,mtexcoords);
       osg::Texture2D* mHUDTexture = new osg::Texture2D;
       mHUDTexture->setDataVariance(osg::Object::DYNAMIC);
       mHUDTexture->setImage(cursor);
       osg::Vec3Array* mHUDnormals = new osg::Vec3Array;
       mHUDnormals->push_back(osg::Vec3(0.0f,0.0f,1.0f));
       mHUDBackgroundGeometry->setNormalArray(mHUDnormals);
       mHUDBackgroundGeometry->setNormalBinding(osg::Geometry::BIND_OVERALL);
       mHUDBackgroundGeometry->addPrimitiveSet(mHUDBackgroundIndices);
       mHUDBackgroundGeometry->setVertexArray(mHUDBackgroundVertices);
       mHUDBackgroundGeometry->setColorArray(mHUDcolors);
       mHUDBackgroundGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);

		bulletBuilt->addDrawable(mHUDBackgroundGeometry);
		
		 // Create and set up a state set using the texture from above:
       osg::StateSet* mHUDStateSet = new osg::StateSet();
       bulletBuilt->setStateSet(mHUDStateSet);
       mHUDStateSet->
          setTextureAttributeAndModes(0,mHUDTexture,osg::StateAttribute::ON);

       // For this state set, turn blending on (so alpha texture looks right)
       mHUDStateSet->setMode(GL_BLEND,osg::StateAttribute::ON);

       // Disable depth testing so geometry is draw regardless of depth values
       // of geometry already draw.
       mHUDStateSet->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);
       mHUDStateSet->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );

       // Need to make sure this geometry is draw last. RenderBins are handled
       // in numerical order so set bin number to 11
       mHUDStateSet->setRenderBinDetails( 11, "RenderBin");
       
       return bulletBuilt;
}


void HUDHandler::shoot()
{
	if(currentBullets == 0)
		reload();
}

void HUDHandler::setCursorPosition(double x, double y)
{
	patCursor->setPosition(osg::Vec3d(x,y,-1.0));
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
	
