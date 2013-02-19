#include "OI.h"

#include "Commands/Shooter/ToggleShooter.h"
#include "Commands/TurHop/AltitudeDirCont.h"
#include "Commands/TurHop/Fire.h"
#include "Commands/TurHop/Load.h"
#include "Commands/TurHop/RotateHopper.h"

OI::OI() {
	// Process operator interface input here.
	stick1 = new Joystick(1);
	stick2 = new Joystick(2);
	
	raiseTur = new JoystickButton(stick1, 3);
	lowerTur = new JoystickButton(stick1, 2);
	fire = new JoystickButton(stick1, Joystick::kDefaultTriggerButton);
	load = new JoystickButton(stick2, Joystick::kDefaultTriggerButton);
	rotLeft = new JoystickButton(stick1, 4);
	rotRight = new JoystickButton(stick1, 5);
	
	shooterShit = new JoystickButton(stick2, 6);
	
	raiseTur->WhileHeld(new AltitudeDirCont(1));
	lowerTur->WhileHeld(new AltitudeDirCont(0));
	fire->WhileHeld(new Fire());
	load->WhenPressed(new Load());
	
	rotLeft->WhileHeld(new RotateHopper(1));
	rotRight->WhileHeld(new RotateHopper(0));
	
	shooterShit->WhenPressed(new ToggleShooter());
}
Joystick* OI::GetStick(int stickNum)
{
	switch(stickNum)
	{
	default:
		return stick1;
	case 1:
		return stick1;
	case 2:
		return stick2;
	}
}
