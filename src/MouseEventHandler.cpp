#include "MouseEventHandler.h"

using namespace std;

MouseEventHandler::MouseEventHandler() : osgGA::GUIEventHandler() {}

void MouseEventHandler::setRootNode(osg::ref_ptr< osg::Group > rootNode)
{
	mRootNode = rootNode;
}

MouseEventHandler::~MouseEventHandler(){}
	
bool MouseEventHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa) {
 
        switch ( ea.getEventType() ) {

			case osgGA::GUIEventAdapter::RELEASE : {
 				
 				printf("MousePressed\n");
                /** PERFORM MOUSE PICKING:
                    In OSG, mouse picking can be done in a few slightly
                    different ways, however, the OSG documentation recommends
                    using the following steps: **/

                /** 1. Create either a PolytopeIntersector, or a LineIntersector
                    using the normalized mouse co-ordinates.**/
                osg::ref_ptr< osgUtil::LineSegmentIntersector > lI = new
					osgUtil::LineSegmentIntersector( osgUtil::Intersector::PROJECTION,
                        ea.getXnormalized(), ea.getYnormalized());
 
                /** 2. Create an IntersectionVisitor, passing the
                    Intersector as parameter to the constructor. **/
                osgUtil::IntersectionVisitor iV( lI );

                /** 3. Launch the IntersectionVisitor on the root node of
                    the scene graph. In an OSGART application, we can
                    launch it on the osgART::Scene node. **/
                    
                mRootNode->accept( iV );
 
                /** 4. If the Intersector contains any intersections
                    obtain the NodePath and search it to find the
                    Node of interest. **/
 
                if ( lI.get()->containsIntersections() ) {
					cout << "Encontre colision" << endl;
                    osg::NodePath nP = lI->getFirstIntersection().nodePath;
 
                    /** Here we search the NodePath for the node of interest.
                        This is where we can make use of our node naming.
 
                        If we find the Transform node named "CAR", we obtain its
                        AnimationPathCallback - if it is currently paused
                        we "un-pause" it, and vice-versa. **/
                    for (unsigned int i = 0; i <= nP.size(); i++) {
                        if (nP[i]->getName() == "puerco") 
						{
                            printf("Has matado un cerdo!\n");
                            return true;
                        }
                        else if (nP[i]->getName() == "buitre") 
						{
                            printf("Has matado un buitre!\n");
                            return true;
                        }
                        else if (nP[i]->getName() == "conejo") 
						{
                            printf("Has matado un conejo!\n");
                            return true;
                        }
                        else if (nP[i]->getName() == "obstaculo") 
						{
							printf("Has matado un conejo!\n");
                            return true;
                        }
                        else
                        {
                        	printf("Shoot some undefined object");
                        	return true;
                        }
                    }
                }
            } 
            default:
				return false;
        } 
    }

