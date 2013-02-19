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
	JoystickButton *load;
	JoystickButton *rotLeft;
	JoystickButton *rotRight;
	
	JoystickButton *shooterShit;
public:
	OI();
	Joystick* GetStick(int stickNum);
};

#endif
