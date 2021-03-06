#include "PickerHandler.h"

using namespace std;
PickHandler::PickHandler( osgText::Text* updateText, HUDHandler* _myHH, SoundHandler *sHandle )
: sHandle( sHandle )
{
	_updateText = updateText;
	myHH = _myHH;
}

PickHandler::~PickHandler()
{
	
}

bool PickHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
{
	//ea.setCursor(osgViewer::GraphicsWindow::CrosshairCursor);
	
	
	
	myHH->setCursorPosition((ea.getX()/ea.getXmax())*1024-55,(ea.getY()/ea.getYmax())*860-64);
    
    if(ea.getEventType() == osgGA::GUIEventAdapter::PUSH)
    {
		switch(ea.getButtonMask())
		{
				case(osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON):
			{
				
				if(!myHH->reloading)
				{
					printf("Shooting\n");
					myHH->shoot();
					sHandle->playSound( 1 );
					osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
					if (view) pick(view,ea);
				}
				else
					printf("Gun not reloaded, you can't shoot!\n");
				return false;
			}   
		 case(osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON):
		 {
				printf("X: %f,Y: %f\n",ea.getX(),ea.getY());
				printf("Reloading\n");
				myHH->reload(1);
				return false;
		 } 
			case(osgGA::GUIEventAdapter::KEYDOWN):
			{
				if (ea.getKey()=='c')
				{        
					osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
					osg::ref_ptr<osgGA::GUIEventAdapter> event = new osgGA::GUIEventAdapter(ea);
					event->setX((ea.getXmin()+ea.getXmax())*0.5);
					event->setY((ea.getYmin()+ea.getYmax())*0.5);
					if (view) pick(view,*event);
				}
				return false;
			}    
			default:
				return false;
		}
	}
	else
		return false;
}

void PickHandler::pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea)
{
	printf("Llamando a pick\n");

    osgUtil::LineSegmentIntersector::Intersections intersections;

    float x = ea.getX();
    float y = ea.getY();

	osg::ref_ptr< osg::Group > parent;

    osg::ref_ptr< osgUtil::LineSegmentIntersector > picker = new osgUtil::LineSegmentIntersector( osgUtil::Intersector::WINDOW, x, y );
    osgUtil::IntersectionVisitor iv( picker.get() );
    view->getCamera()->accept(iv);
    //printf("%d\n",view->getSceneData()->getNumChildren());
    if ( picker->containsIntersections() )
    {
    	printf( "Found Intersections\n" );
		intersections = picker->getIntersections();
    //if (view->computeIntersections(x,y,intersections))
    //{
		printf( "Computing intersections\n" );
		osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
        /*for( osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
            hitr != intersections.end();
            ++hitr )*/
        {
			
            // std::ostringstream os;
			if ( !hitr->nodePath.empty() && !( hitr->nodePath.back()->getName().empty()) )
            {
				for( parent = hitr->nodePath.back()->getParent(0) ; parent->getNumParents() > 0; parent = parent->getParent(0) )
				{
					cout << "Finding parent..." << parent->className() << " " << parent->getName() << endl;
					//hitr->nodePath.pop_back();
					if( (!strcmp( parent->getName().c_str(), "buitre") || (!strcmp( parent->getName().c_str(), "buitre2")) ))
					{
						myHH->achieveBird();
						sHandle->playSound( 3 );
						parent->setName("X");
						break;
					}
					if(( !strcmp( parent->getName().c_str(), "cerdito") || ( !strcmp( parent->getName().c_str(), "cerdito2"))))
					{
						myHH->achievePork();
						sHandle->playSound( 3 );
						parent->setName("X");
						break;
					}
					if(( !strcmp( parent->getName().c_str(), "conejo") ||( !strcmp( parent->getName().c_str(), "conejo2"))))
					{
						myHH->achieveRabbit();
						sHandle->playSound( 3 );
						parent->setName("X");
						break;
					}
				}

				cout << "Nodo obtenido: " << parent->getName() << endl;
				cout << "Object \"" << hitr->nodePath.back()->className() << "\"" << std::endl;
            }
            else if ( hitr->drawable.valid() )
            {
                cout<<"Object \""<< hitr->drawable->className() <<"\""<<std::endl;
            }

            //os<<"        local coords vertex("<< hitr->getLocalIntersectPoint()<<")"<<"  normal("<<hitr->getLocalIntersectNormal()<<")"<<std::endl;
            //os<<"        world coords vertex("<< hitr->getWorldIntersectPoint()<<")"<<"  normal("<<hitr->getWorldIntersectNormal()<<")"<<std::endl;
            const osgUtil::LineSegmentIntersector::Intersection::IndexList& vil = hitr->indexList;
            for(unsigned int i=0;i<vil.size();++i)
            {
                cout <<"        vertex indices ["<<i<<"] = "<<vil[i]<<std::endl;
            }
            
            //gdlist += os.str();
        }
    }
}
