#include "TurretHopper.h"
#include "../Robotmap.h"
#include <math.h>

TurretHopper::TurretHopper() : Subsystem("TurretHopper") {
	altitude = new Jaguar(5);
	feeder = new DoubleSolenoid(1,2);
	feeder->Set(DoubleSolenoid::kReverse);
	
	comp = new Compressor(1,1);
	comp->Start();

	pot = new AnalogChannel(1,1);
	accel = new ADXL345_I2C(1);
	
	SmartDashboard::PutNumber("Tilt Angle", GetTiltAngle());
	SmartDashboard::PutNumber("Potentiometer", GetPotAngle());
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
	Wait(0.3);
	feeder->Set(DoubleSolenoid::kReverse);
}

void TurretHopper::SetFiringOff()
{
	feeder->Set(DoubleSolenoid::kReverse);
}

double TurretHopper::GetPotAngle()
{	
	return (pot->GetVoltage()); 
}

double TurretHopper::GetTiltAngle()
{	
	double acceleration = accel->GetAcceleration(ADXL345_I2C::kAxis_X);
	acceleration = floor(acceleration * 1000);
	acceleration *= 0.001;
	return ((asin(acceleration)) * (180/3.1415926)); 
}
