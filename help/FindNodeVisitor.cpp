#include "findNodeVisitor.h"

void FindNodeVisitor::apply(osg::Node &searchNode) 
{ 
   if(!strcmp(searchNode.className(),className))
   {
      foundNodeList.push_back(&searchNode);
      //osg::PositionAttitudeTransform* gPtr = dynamic_cast<osg::PositionAttitudeTransform*> (&searchNode);
      
   }
   //std::cout<< searchNode.className() <<std::endl;
   traverse(searchNode); 
} 



