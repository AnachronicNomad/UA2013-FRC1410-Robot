#include "OI.h"

OI::OI() {
	// Process operator interface input here.
}
Joystick* OI::GetStick1()
{
	return stick1;
}
Joystick* OI::GetStick2()
{
	return stick2;
}
