#include "Shooter.h"
#include "../Robotmap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	shooterMotor = new Jaguar(3);
	
	firing = false;
}
    
void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::FiringToggle()
{
	firing = !firing;
	if(firing)
	{shooterMotor->Set(-1.0);}
	else
	{shooterMotor->Set(0.0);}
}
void Shooter::TurnOff()
{
	firing = false;
	shooterMotor->Set(0.0);
}
