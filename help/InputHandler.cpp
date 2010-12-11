#include "InputHandler.h"

InputHandler::InputHandler()
{		
		//oldy = newy = 256;
		//oldx = newx = 256;
		//deltay = deltax = delta = 0;
		wflag = vflag = sflag = playerSL = playerSR = false; 
		//mouseMoving = dragRB = dragLB = false;
		tModel = NULL;
		b1 = b2 = b3 = b4 = b5 = b6 = b7 = b8 = b9 = false;
}\
InputHandler::~InputHandler()
{
}

void InputHandler::setController( osg::ref_ptr< osg::MatrixTransform > jModel )
{
	tModel = jModel;
}

void InputHandler::update( double a )
{
	delta = a;
}

bool InputHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{
	switch( ea.getEventType() )
	{
	case( osgGA::GUIEventAdapter::KEYUP ):
	{	
		if ( ea.getKey() == 'a' || ea.getKey() == 'A')
		{
			playerSL = false;
			return true;
		}
		else if ( ea.getKey() == 'd' || ea.getKey() == 'D')
		{
			playerSR = false;
			return true;
		}
		else if ( ea.getKey() == 'w' || ea.getKey() == 'W')
		{
			wflag = false;				
			return true;
		}
		else if ( ea.getKey() == 's' || ea.getKey() == 'S')
		{
			vflag = false;
			
			return true;
				
		}
		else if ( ea.getKey() == '1')
		{
			b1 = false;
			
			return true;
				
		}
		else if ( ea.getKey() == '2')
		{
			b2 = false;
			
			return true;
				
		}
		else if ( ea.getKey() == '3')
		{
			b3 = false;
			
			return true;
				
		}
		else if ( ea.getKey() == '4')
		{
			b4 = false;
			
			return true;
				
		}
		else if ( ea.getKey() == '5')
		{
			b5 = false;
			
			return true;
				
		}
		else if ( ea.getKey() == '6')
		{
			b6 = false;
			
			return true;
				
		}
		else if ( ea.getKey() == '7')
		{
			b7 = false;
			
			return true;
				
		}
		else if ( ea.getKey() == '8')
		{
			b8 = false;
			
			return true;
				
		}
		else if ( ea.getKey() == '9')
		{
			b9 = false;
			
			return true;
				
		}
	}
	case(osgGA::GUIEventAdapter::KEYDOWN):
	{	
		if ( ea.getKey() == 'a' || ea.getKey() == 'A')
		{
			if(playerSL == false)
				playerSL = true;

			trans.makeTranslate(osg::Vec3(5.0f*(float)delta, 0.0f, 0.0f));
			tModel.get()->postMult(trans);

			return true;
		}
		else if ( ea.getKey() == 'd' || ea.getKey() == 'D')
		{
			if(playerSR == false)
				playerSR = true;

			trans.makeTranslate(osg::Vec3(-5.0f*(float)delta, 0.0f, 0.0f));
			tModel.get()->postMult(trans);

			return true;
		}
		else if ( ea.getKey() == 'w' || ea.getKey() == 'W')
		{	
			if(wflag == false)
				wflag = true;

			trans.makeTranslate(osg::Vec3(0.0f, -5.0f*(float)delta, 0.0f));
            tModel.get()->postMult(trans);

			return true;					
		}
		else if ( ea.getKey() == 's' || ea.getKey() == 'S')
		{	
			if(vflag == false)
				vflag = true;

			trans.makeTranslate(osg::Vec3(0.0f, 5.0f*(float)delta, 0.0f));
            tModel.get()->postMult(trans);

			return true;					
		}
		else if ( ea.getKey() == '1')
		{	
			if(b1 == false)
				b1 = true;

			return true;					
		}
		else if ( ea.getKey() == '2')
		{	
			if(b2 == false)
				b2 = true;

			return true;					
		}
		else if ( ea.getKey() == '3')
		{	
			if(b3 == false)
				b3 = true;

			return true;					
		}
		else if ( ea.getKey() == '4')
		{	
			if(b4 == false)
				b4 = true;

			return true;					
		}
		else if ( ea.getKey() == '5')
		{	
			if(b5 == false)
				b5 = true;

			return true;					
		}
		else if ( ea.getKey() == '6')
		{	
			if(b6 == false)
				b6 = true;

			return true;					
		}
		else if ( ea.getKey() == '7')
		{	
			if(b7 == false)
				b7 = true;

			return true;					
		}
		else if ( ea.getKey() == '8')
		{	
			if(b8 == false)
				b8 = true;

			return true;					
		}
		else if ( ea.getKey() == '9')
		{	
			if(b9 == false)
				b9 = true;

			return true;					
		}
	}
	/*case(osgGA::GUIEventAdapter::RELEASE):
	{
		if (ea.getButton() == osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON)
		{
			dragRB = false;
			return true;
		}
		else if (ea.getButton() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
		{
			dragLB = false;
			return true;
		}

	}*/
	/*case(osgGA::GUIEventAdapter::DRAG):
	{
		if (ea.getButtonMask()== osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON)
		{
			if(dragRB == false)
				dragRB = true;
				
			newy = ea.getY();
			deltay = newy - oldy;
			oldy = newy;

			return true;
				
		}
		else if (ea.getButtonMask()== osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
		{
			if(dragLB == false)
				dragLB = true;

			newx = ea.getX();
			deltax = newx - oldx;
			newy = ea.getY();
			deltay = newy - oldy;

			oldy = newy;
			oldx = newx;

			return true;
		}
		
	}*/
	default: break;
	}
    return false;
}