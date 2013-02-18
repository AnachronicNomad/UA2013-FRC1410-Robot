#include "TurretAndHopper.h"
#include "../Robotmap.h"

TurretAndHopper::TurretAndHopper() : Subsystem("TurretAndHopper") {
	altitude = new Jaguar(4);
	hopperRotat = new Jaguar(5);
	accel = new ADXL345_I2C(1);
}
    
void TurretAndHopper::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void TurretAndHopper::AltitudeControl(double speed)
{
	altitude->Set(speed);
}

void TurretAndHopper::HopperBumpRotate(double speed)
{
	hopperRotat->Set(speed);
	Wait(0.75);
	hopperRotat->Set(0.0);
}
