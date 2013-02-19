#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick *stick;
	
	JoystickButton *raiseTur;
	JoystickButton *lowerTur;
	JoystickButton *fire;
		
	JoystickButton *shooterShit;
public:
	OI();
	double GetStick(int stickNum);
};

#endif
