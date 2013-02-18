#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/Drive/TeleOpArcade.h"

Drive::Drive() : Subsystem("Drive") {
	drive = new RobotDrive(1,2);
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TeleOpArcade());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drive::OneStickArcade(Joystick* stick)
{
	drive->ArcadeDrive(stick);
}

void Drive::TwoStickTank(double speed1, double speed2)
{
	drive->TankDrive(speed1, speed2);
}
