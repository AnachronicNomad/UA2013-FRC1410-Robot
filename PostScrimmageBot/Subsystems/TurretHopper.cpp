#include "TurretHopper.h"
#include "../Robotmap.h"
#include <math.h>

TurretHopper::TurretHopper() : Subsystem("TurretHopper") {
	altitude = new Jaguar(4);
	feeder = new DoubleSolenoid(1,2);
	
	hopFeedb1 = new Servo(5);
	hopFeedb2 = new Servo(6);
	hopFeedFront = new Servo(7);
	hopLoadOn = false;
	
	hopFeedb1->SetAngle(90);
	hopFeedb2->SetAngle(90);
	hopFeedFront->SetAngle(180);
	
	hopRamp = new Servo(8);
	
	comp = new Compressor(1,1);
	comp->Start();
	
	accel = new ADXL345_I2C(1);
	acceleration = 0.0;
	SmartDashboard::PutNumber("Tilt Angle", GetTiltAngle());
	
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
	Wait(0.05);
}

void TurretHopper::FeederToggle()
{
	feeder->Set(DoubleSolenoid::kForward);
	Wait(0.25);
	feeder->Set(DoubleSolenoid::kReverse);
}
void TurretHopper::HopFeedToggle()
{
	hopLoadOn = !hopLoadOn;
	if(hopLoadOn)
	{
		hopFeedFront->SetAngle(0);
		Wait(0.25);
		hopFeedb1->SetAngle(0);
		hopFeedb2->SetAngle(0);
		Wait(0.05);		
	}
	else
	{
		hopFeedFront->SetAngle(180);
		hopFeedb1->SetAngle(90);
		hopFeedb1->SetAngle(90);
		Wait(0.05);
	}
}

void TurretHopper::SetFiringOff()
{
	hopLoadOn = false;
	feeder->Set(DoubleSolenoid::kReverse);
	hopFeedFront->SetAngle(180);
	hopFeedb1->SetAngle(90);
	hopFeedb1->SetAngle(90);
}

double TurretHopper::GetTiltAngle()
{
	acceleration = accel->GetAcceleration(ADXL345_I2C::kAxis_X);
	acceleration = acceleration *= 1000;
	acceleration = floor(acceleration);
	acceleration = acceleration *= 0.001;
	
	return asin(acceleration) * 180/3.1415926; 
}
