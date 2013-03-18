#include "Shooter.h"
#include "../Robotmap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	shooterMotor = new Jaguar(3);
	this->ArraySpeedsInit();
	counter =0;
	SmartDashboard::PutNumber("Speed Percentage", speeds[counter]);
}
    
void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::FiringToggle()
{
	++counter;
	if(counter == 4)
	{counter = 0;}
	shooterMotor->Set(speeds[counter]);
	SmartDashboard::PutNumber("Speed Percentage", speeds[counter]);
	Wait(0.05);
}
void Shooter::TurnOff()
{
	shooterMotor->Set(0.0);
	counter = 0;
	SmartDashboard::PutNumber("Speed Percentage", speeds[counter]);
	Wait(0.05);
}

void Shooter::ArraySpeedsInit()
{
	speeds[0] = 0.0;
	speeds[1] = -0.50;
	speeds[2] = -0.60;
	speeds[3] = -0.70;
}

void Shooter::SetShooterSpeed(float speed)
{
	counter = 0;
	shooterMotor->Set(speed);
	SmartDashboard::PutNumber("Speed Percentage", speeds[counter]);
	Wait(0.05);
}
