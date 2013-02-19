#include "TurretHopper.h"
#include "../Robotmap.h"

TurretHopper::TurretHopper() : Subsystem("TurretHopper") {
	altitude = new Jaguar(4);
	hopRotat = new Jaguar(5);
	feeder = new DoubleSolenoid(1,2);
	hopFeed = new Solenoid(3);
	
	accel = new ADXL345_I2C(1);
	
	feeder->Set(DoubleSolenoid::kReverse);
}
    
void TurretHopper::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void TurretHopper::AltitudeControl(double speed)
{
	altitude->Set(speed);
}
void TurretHopper::RotatBump(bool left)
{
	if(left)
	{
		hopRotat->Set(-0.5);
		Wait(0.75);
		hopRotat->Set(0.0);
	}
	else
	{
		hopRotat->Set(0.5);
		Wait(0.75);
		hopRotat->Set(0.0);
	}
}
void TurretHopper::FeederToggle()
{
	feeder->Set(DoubleSolenoid::kForward);
	Wait(0.5);
	feeder->Set(DoubleSolenoid::kReverse);
}
void TurretHopper::HopFeedToggle()
{
	hopFeed->Set(true);
	Wait(0.5);
	hopFeed->Set(false);
}
