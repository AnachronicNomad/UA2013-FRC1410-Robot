#include "OI.h"

#include "Commands/Shooter/ToggleShooter.h"
#include "Commands/Shooter/KillShooter.h"
#include "Commands/TurHop/AltitudeDirCont.h"
#include "Commands/TurHop/Fire.h"
#include "Commands/TurHop/SingleFire.h"


OI::OI() {
	// Process operator interface input here.
	stick1 = new Joystick(1);
	stick2 = new Joystick(2);
	
	raiseTur = new JoystickButton(stick2, 3);
	lowerTur = new JoystickButton(stick2, 2);
	fire = new JoystickButton(stick2, 6);
	potShot = new JoystickButton(stick2, 8);
	//loader = new JoystickButton(stick2, 5);
	speedToggler = new JoystickButton(stick2, 4);
	killShooter = new JoystickButton(stick2, 1);
		
	raiseTur->WhileHeld(new AltitudeDirCont(true));
	lowerTur->WhileHeld(new AltitudeDirCont(false));
	fire->WhileHeld(new Fire());
	potShot->WhenPressed(new SingleFire());
	//loader->WhenPressed(new Load());
	speedToggler->WhenPressed(new ToggleShooter());
	killShooter->WhenPressed(new KillShooter());
}
double OI::GetStickAxis(bool left)
{
	if(left)
		{return stick1->GetRawAxis(2);}
	else
		{return stick1->GetRawAxis(4);}
}
