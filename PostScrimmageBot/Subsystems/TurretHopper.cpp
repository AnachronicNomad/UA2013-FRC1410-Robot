#include "TurretHopper.h"
#include "../Robotmap.h"

TurretHopper::TurretHopper() : Subsystem("TurretHopper") {
	altitude = new Jaguar(4);
	hopRotat = new Jaguar(5);
	feeder = new DoubleSolenoid(1,2);
	hopFeed1 = new Servo(4);
	hopFeed2 = new Servo(5);
	
	hopFeed1->SetAngle(90);
	hopFeed2->SetAngle(90);
	hopLoadOn = false;
	
	comp = new Compressor(1,1);
	comp->Start();
	
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

void TurretHopper::FeederToggle()
{
	feeder->Set(DoubleSolenoid::kForward);
	Wait(0.5);
	feeder->Set(DoubleSolenoid::kReverse);
	Wait(0.25);
}
void TurretHopper::HopFeedToggle()
{
	hopLoadOn = !hopLoadOn;
	if(hopLoadOn)
	{
		hopFeed1->SetAngle(180);
		hopFeed2->SetAngle(180);
		Wait(0.5);
	}
	else
	{
		hopFeed1->SetAngle(90);
		hopFeed2->SetAngle(90);
		Wait(0.5);
	}
}
