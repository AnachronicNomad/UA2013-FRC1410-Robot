#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick *stick;
	
	JoystickButton *raiseTur;
	JoystickButton *lowerTur;
	JoystickButton *fire;
	JoystickButton *loader;
	JoystickButton *speedToggler;
	JoystickButton *killShooter;
public:
	OI();
	double GetStick(int stickNum);
};

#endif
