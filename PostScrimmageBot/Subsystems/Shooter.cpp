#include "Shooter.h"
#include "../Robotmap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	shooterFrontMotor = new Jaguar(3);
	shooterBackMotor = new Jaguar(4);
	this->ArraySpeedsInit();
	counter =0;
	SmartDashboard::PutNumber("Speed Percentage Front", speedsFront[counter]);
	SmartDashboard::PutNumber("Speed Percentage Back", speedsBack[counter]);
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
	if(counter == 6)
	{counter = 0;}
	shooterFrontMotor->Set(speedsFront[counter]);
	shooterBackMotor->Set(speedsBack[counter]);
	SmartDashboard::PutNumber("Speed Percentage Front", speedsFront[counter]);
	SmartDashboard::PutNumber("Speed Percentage Back", speedsBack[counter]);
}
void Shooter::TurnOff()
{
	shooterFrontMotor->Set(0.0);
	shooterBackMotor->Set(0.0);
	counter = 0;
	SmartDashboard::PutNumber("Speed Percentage Front", speedsFront[counter]);
	SmartDashboard::PutNumber("Speed Percentage Back", speedsBack[counter]);
}

void Shooter::ArraySpeedsInit()
{
	speedsFront[0] = 0.0;
	speedsFront[1] = -0.75;
	speedsFront[2] = -0.80;
	speedsFront[3] = -0.85;
	speedsFront[4] = -0.9;
	speedsFront[5] = -1.0;
	
	speedsBack[0] = 0.0;
	speedsBack[1] = -0.65;
	speedsBack[2] = -0.7;
	speedsBack[3] = -0.75;
	speedsBack[4] = -0.8;
	speedsBack[5] = -0.9;
	           
}

void Shooter::SetShooterSpeed(float speed)
{
	counter = 0;
	shooterFrontMotor->Set(speed);
	shooterBackMotor->Set(speed);
	SmartDashboard::PutNumber("Speed Percentage Front", speedsFront[counter]);
	SmartDashboard::PutNumber("Speed Percentage Back", speedsBack[counter]);
}
