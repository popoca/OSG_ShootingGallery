#include "FindNodeVisitor.h"


   FindNodeVisitor::FindNodeVisitor(const char* nodetype)				    
{ 

  setTraversalMode(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN);
  className = nodetype;
} 
FindNodeVisitor::~FindNodeVisitor(){};

void FindNodeVisitor::apply(osg::Node &searchNode) 
{ 
   if(!strcmp(searchNode.className(),className))
   {
	  //agregamos el nodo a la lista
      foundNodeList.push_back(&searchNode);      
   }

   //Metodo que establece la recursion, con traverse se hace el llamado del metodo
   //apply para los hijos del nodo searchNode
   traverse(searchNode); 
} 



