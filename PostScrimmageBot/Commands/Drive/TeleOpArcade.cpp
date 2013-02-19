#include "TeleOpArcade.h"

TeleOpArcade::TeleOpArcade() {
	// Use requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void TeleOpArcade::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void TeleOpArcade::Execute() {
	chassis->ArcadeOneStick(oi->GetStick(1));
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpArcade::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleOpArcade::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpArcade::Interrupted() {
}
