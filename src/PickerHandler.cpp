
#include "PickerHandler.h"

using namespace std;
PickHandler::PickHandler( osgText::Text* updateText )
{
	_updateText = updateText;
}

PickHandler::~PickHandler()
{
	
}


bool PickHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
{
    switch(ea.getEventType())
    {
        case(osgGA::GUIEventAdapter::PUSH):
        {
        	printf("Mouse Pressed\n");
            osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
            if (view) pick(view,ea);
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

void PickHandler::pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea)
{
	printf("Llamando a pick\n");
    osgUtil::LineSegmentIntersector::Intersections intersections;

    std::string gdlist="";
    float x = ea.getX();
    float y = ea.getY();

    osg::ref_ptr< osgUtil::LineSegmentIntersector > picker = new osgUtil::LineSegmentIntersector(osgUtil::Intersector::WINDOW, x, y);
    osgUtil::IntersectionVisitor iv(picker.get());
    view->getCamera()->accept(iv);
    //printf("%d\n",view->getSceneData()->getNumChildren());
    if (picker->containsIntersections())
    {
    	printf("Found Intersections\n");
    	
        intersections = picker->getIntersections();
    //if (view->computeIntersections(x,y,intersections))
    //{
		printf("Computing intersections\n");
        for(osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
            hitr != intersections.end();
            ++hitr)
        {
            std::ostringstream os;
            if (!hitr->nodePath.empty() && !(hitr->nodePath.back()->getName().empty()))
            {
                // the geodes are identified by name.
                 cout <<"Object \""<<hitr->nodePath.back()->getName()<<"\""<<std::endl;
            }
            else if (hitr->drawable.valid())
            {
                cout<<"Object \""<<hitr->drawable->className()<<"\""<<std::endl;
            }

            os<<"        local coords vertex("<< hitr->getLocalIntersectPoint()<<")"<<"  normal("<<hitr->getLocalIntersectNormal()<<")"<<std::endl;
            os<<"        world coords vertex("<< hitr->getWorldIntersectPoint()<<")"<<"  normal("<<hitr->getWorldIntersectNormal()<<")"<<std::endl;
            const osgUtil::LineSegmentIntersector::Intersection::IndexList& vil = hitr->indexList;
            for(unsigned int i=0;i<vil.size();++i)
            {
                cout <<"        vertex indices ["<<i<<"] = "<<vil[i]<<std::endl;
            }
            
            gdlist += os.str();
        }
    }
    setLabel(gdlist);
}