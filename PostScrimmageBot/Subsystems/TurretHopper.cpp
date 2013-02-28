#include "TurretHopper.h"
#include "../Robotmap.h"
#include <math.h>

TurretHopper::TurretHopper() : Subsystem("TurretHopper") {
	altitude = new Jaguar(4);
	hopRotat = new Jaguar(5);
	feeder = new DoubleSolenoid(1,2);
	
	for(int i=0; i<3;i++)
	{
		hopperIndexer[i] = new Servo(5 + i);
		hopperIndexer[i]->SetAngle(90.0);
	}
	
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
		for(int i = 3;i<3;i++)
		{
			hopperIndexer[i]->SetAngle(180.0);
		}
		Wait(0.5);
	}
	else
	{
		for(int i = 3;i<3;i++)
				{
					hopperIndexer[i]->SetAngle(90.0);
				}
		Wait(0.5);
	}
}

double TurretHopper::GetTiltAngle()
{
	double acceleration = accel->GetAcceleration(ADXL345_I2C::kAxis_X);
	acceleration = acceleration *= 1000;
	acceleration = floor(acceleration);
	acceleration = acceleration *= 0.001;
	
	return floor(asin(acceleration) * 180/3.1415926); 
}
