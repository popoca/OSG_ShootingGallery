/**
MOUSE EVENT HANDLER:
To handle keyboard and mouse events in OSG, we need to define a subclass
of osgGA::GUIEventHandler, and override the handle() method with custom code.
**/
class MouseEventHandler : public osgGA::GUIEventHandler {
 
    protected:
 
    float _mX, _mY;
 
    public:
 
    MouseEventHandler() : osgGA::GUIEventHandler() {}
 
 
    /** OVERRIDE THE HANDLE METHOD:
        The handle() method should return true if the event has been dealt with
        and we do not wish it to be handled by any other handler we may also have
        defined. Whether you return true or false depends on the behaviour you
        want - here we have no other handlers defined so return true. **/
    virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa) {
 
       //osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
 
        switch (ea.getEventType()) {
 
 
            /** HANDLE MOUSE EVENTS:
                Mouse events have associated event names, and mouse
                position co-ordinates. **/
            case osgGA::GUIEventAdapter::RELEASE: {
 
 
                /** PERFORM SOME ACTION:
                    Once we have received the mouse event, we can
                    perform some action. Here we perform mouse picking.
 
                    Mouse picking can be thought of as shooting a "ray"
                    from the mouse position into our scene, and determining
                    which parts of the scene intersect with the ray.
                    Typically we will only be interested in the firstfalse
                    (if any) object that the ray hits. We can then perform
                    some action.
 
                    In this example, we are going to interact with our
                    car model - if the mouse has "picked" it, we will
                    start a simple rotation on it. **/
 
 
 
                /** PERFORM MOUSE PICKING:
                    In OSG, mouse picking can be done in a few slightly
                    different ways, however, the OSG documentation recommends
                    using the following steps: **/
 
 
                /** 1. Create either a PolytopeIntersector, or a LineIntersector
                    using the normalized mouse co-ordinates.**/
                osg::ref_ptr<osgUtil::LineSegmentIntersector> lI = new
                    osgUtil::LineSegmentIntersector(osgUtil::Intersector::PROJECTION,
                        ea.getXnormalized(), ea.getYnormalized());
 
                /** 2. Create an IntersectionVisitor, passing the
                    Intersector as parameter to the constructor. **/
                osgUtil::IntersectionVisitor iV(lI);
 
                /** 3. Launch the IntersectionVisitor on the root node of
                    the scene graph. In an OSGART application, we can
                    launch it on the osgART::Scene node. **/
                scene->accept(iV);
 
                /** 4. If the Intersector contains any intersections
                    obtain the NodePath and search it to find the
                    Node of interest. **/
 
                if (lI->containsIntersections()) {
                    osg::NodePath nP = lI->getFirstIntersection().nodePath;
 
 
                    /** Here we search the NodePath for the node of interest.
                        This is where we can make use of our node naming.
 
                        If we find the Transform node named "CAR", we obtain its
                        AnimationPathCallback - if it is currently paused
                        we "un-pause" it, and vice-versa. **/
                    for (int i = 0; i <= nP.size(); i++) {
                        if (nP[i]->getName() == "CAR") {
                            osg::AnimationPathCallback* cb = 
                                dynamic_cast<osg::AnimationPathCallback*>(nP[i]->getUpdateCallback());
 
                            if (cb->getPause()==true)
                                cb->setPause(false);
                            else cb->setPause(true);
 
                            return true;
                        }
                    }
                }
            } 
            default: return false;
        } 
    } 
};