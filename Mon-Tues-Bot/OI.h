#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick* stick1;
	Joystick* stick2;
public:
	OI();
	Joystick* GetStick1();
	Joystick* GetStick2();
};

#endif
