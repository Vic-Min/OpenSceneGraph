//C++ header - Open Scene Graph - Copyright (C) 1998-2002 Robert Osfield
//Distributed under the terms of the GNU Library General Public License (LGPL)
//as published by the Free Software Foundation.

#ifndef OSGGLUT_ProducerEventAdapter
#define OSGGLUT_ProducerEventAdapter 1

#include <osgGA/GUIEventAdapter>
#include <Producer/KeyboardMouse>

/** Class for adapting GLUT events so that they can be used as input to osgGA::CameraManipulators.*/
class ProducerEventAdapter : public osgGA::GUIEventAdapter
{

    public:
        ProducerEventAdapter();
        virtual ~ProducerEventAdapter() {}

        /** Get the EventType of the GUI event.*/
        virtual EventType getEventType() const { return _eventType; }

        /** key pressed, return -1 if inappropriate for this event. */
        virtual int getKey() const { return _key; }

        /** button pressed/released, return -1 if inappropriate for this event.*/
        virtual int getButton() const { return _button; }

        /** window minimum x. */
        virtual int getXmin() const  { return _Xmin; }

        /** window maximum x. */
        virtual int getXmax() const  { return _Xmax; }

        /** window minimum y. */
        virtual int getYmin() const { return _Ymin; }

        /** window maximum y. */
        virtual int getYmax() const { return _Ymax; }

        /** current mouse x position.*/
        virtual int getX() const { return _mx; }

        /** current mouse y position.*/
        virtual int getY() const { return _my; }

        /** current mouse button state */
        virtual unsigned int getButtonMask() const { return _buttonMask; }

        /** time in seconds of event. */
        virtual double time() const { return _time; }

        virtual unsigned int getModKeyMask() const { return _modKeyMask; }

        /** static method for setting window dimensions.*/
        static void setWindowSize(int Xmin, int Ymin, int Xmax, int Ymax);

        /** static method for setting button state.*/
        static void setButtonMask(unsigned int buttonMask);

        /** method for adapting resize events. */
        void adaptResize(double t, int Xmin, int Ymin, int Xmax, int Ymax);


        /** method for adapting mouse motion events whilst mouse buttons are pressed.*/
        void adaptMouseMotion(double t, float x, float y);

        void adaptButtonPress(double t,float x, float y, unsigned int button);
        
        void adaptButtonRelease(double t,float x, float y, unsigned int button);

        /** method for adapting keyboard events.*/
        void adaptKeyPress( double t, Producer::KeySymbol key);

        void adaptKeyRelease( double t, Producer::KeySymbol key);

        /** method for adapting frame events, i.e. idle/display callback.*/
        void adaptFrame(double t);


        void copyStaticVariables();

    protected:
    

        EventType _eventType;
        int _key;
        int _button;
        int _Xmin,_Xmax;
        int _Ymin,_Ymax;
        int _mx;
        int _my;
        unsigned int _buttonMask;
        unsigned int _modKeyMask;
        double _time;

        // used to accumulate the button mask state, it represents
        // the current button mask state, which is modified by the
        // adaptMouse() method which then copies it to value _buttonMask
        // which required the mouse buttons state at the time of the event.
        static unsigned int _s_accumulatedButtonMask;
        
	// used to store current button value
	static int _s_button;

        // used to store window min and max values.
        static int _s_Xmin;
        static int _s_Xmax;
        static int _s_Ymin;
        static int _s_Ymax;
        static int _s_mx;
        static int _s_my;
        static int _s_modKeyMask;

};

#endif
