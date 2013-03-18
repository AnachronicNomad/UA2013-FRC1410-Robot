#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick *stick1;
	Joystick *stick2;
	
	JoystickButton *raiseTur;
	JoystickButton *lowerTur;
	JoystickButton *fire;
	JoystickButton *potShot;
	//JoystickButton *loader;
	JoystickButton *speedToggler;
	JoystickButton *killShooter;
public:
	OI();
	double GetStickAxis(bool left);
};

#endif
