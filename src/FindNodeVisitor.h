#include <osg/NodeVisitor>
#include <osg/Node>
#include <osg/PositionAttitudeTransform>
#include <iostream>
#include <vector>
#include <string.h>


//Se hereda de la clase NodeVisitor para poder hacer el recorrido del grafo
//La idea es reimplementar el metodo apply para realizar tareas especificas
//sobre cada nodo durante el recorrido

class FindNodeVisitor : public osg::NodeVisitor { 
public: 

   FindNodeVisitor(const char* nodetype);
 	~FindNodeVisitor();
 	
   virtual void apply(osg::Node &searchNode);
   
   //Cambiamos la definición a nodes
   typedef std::vector<osg::Node*> nodeListType; 

   nodeListType foundNodeList; 

private: 
   
   const char* className;

}; 


