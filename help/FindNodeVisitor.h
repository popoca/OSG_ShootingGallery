
#include <osg/NodeVisitor>
#include <osg/Node>
#include <osg/PositionAttitudeTransform>
#include <iostream>
#include <vector>

class FindNodeVisitor : public osg::NodeVisitor { 
public: 

   FindNodeVisitor(const char* nodetype)				    
{ 

  setTraversalMode(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN);
  className = nodetype;
} 
 

   virtual void apply(osg::Node &searchNode);
   

  
   

   typedef std::vector<osg::Node*> nodeListType; 

   nodeListType foundNodeList; 

private: 

   
   const char* className;

}; 


