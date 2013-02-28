#include "OI.h"

#include "Commands/Shooter/ToggleShooter.h"
#include "Commands/Shooter/KillShooter.h"
#include "Commands/TurHop/AltitudeDirCont.h"
#include "Commands/TurHop/Fire.h"
#include "Commands/TurHop/Load.h"
#include "Commands/TurHop/RotateHopper.h"

OI::OI() {
	// Process operator interface input here.
	stick = new Joystick(1);
	
	raiseTur = new JoystickButton(stick, 2);
	lowerTur = new JoystickButton(stick, 1);
	fire = new JoystickButton(stick, 6);
	loader = new JoystickButton(stick, 5);
	speedToggler = new JoystickButton(stick, 4);
	killShooter = new JoystickButton(stick, 3);
		
	raiseTur->WhileHeld(new AltitudeDirCont(true));
	lowerTur->WhileHeld(new AltitudeDirCont(false));
	fire->WhileHeld(new Fire());
	loader->WhenPressed(new Load());
	speedToggler->WhenPressed(new ToggleShooter());
	killShooter->WhenPressed(new KillShooter());
}
double OI::GetStick(int stickNum)
{
	switch(stickNum)
	{
	default:
		return stick->GetRawAxis(2);
	case 1:
		return stick->GetRawAxis(2);
	case 2:
		return stick->GetRawAxis(5);
	}
}
