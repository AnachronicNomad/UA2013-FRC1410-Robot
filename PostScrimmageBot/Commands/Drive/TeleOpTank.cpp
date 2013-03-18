#include "TeleOpTank.h"

TeleOpTank::TeleOpTank() {
	// Use requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void TeleOpTank::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void TeleOpTank::Execute() {
	chassis->TankTwoStick(oi->GetStickAxis(true),oi->GetStickAxis(false));
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpTank::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpTank::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpTank::Interrupted() {
}
