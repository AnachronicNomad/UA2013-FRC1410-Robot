#include "Shooter.h"
#include "../Robotmap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	shooterMotor = new Jaguar(3);
	feeder = new DoubleSolenoid(1,2);
	
	feeder->Set(DoubleSolenoid::kReverse);
	firing = false;
}
    
void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::SetShooterToggle()
{
	firing = !firing;
	if(firing)
	{shooterMotor->Set(1.0);}
	else
	{shooterMotor->Set(0.0);}
}

void Shooter::TurnOffShooter()
{
	firing = false;
	shooterMotor->Set(0.0);
}

void Shooter::FeederToggle()
{
	feeder->Set(DoubleSolenoid::kForward);
	Wait(0.5);
	feeder->Set(DoubleSolenoid::kReverse);
}
