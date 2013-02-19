#include "ChassisDrive.h"
#include "../Robotmap.h"
#include "../Commands/Drive/TeleOpTank.h"

ChassisDrive::ChassisDrive() : Subsystem("ChassisDrive") {
	drive = new RobotDrive(1,2);
	drive->SetExpiration(0.1);
	drive->SetSafetyEnabled(false);
}
    
void ChassisDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TeleOpTank());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void ChassisDrive::ArcadeOneStick(Joystick* stick1)
{
	drive->ArcadeDrive(stick1);
}
void ChassisDrive::TankTwoStick(float speed1, float speed2)
{
	drive->TankDrive(speed1, speed2);
}
