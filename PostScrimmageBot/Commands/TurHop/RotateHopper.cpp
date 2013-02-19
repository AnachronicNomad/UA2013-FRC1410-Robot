#include "RotateHopper.h"

RotateHopper::RotateHopper(bool LeftOrRight) {
	// Use requires() here to declare subsystem dependencies
	Requires(turhop);
	direction = LeftOrRight;
}

// Called just before this Command runs the first time
void RotateHopper::Initialize() {
	turhop->RotatBump(direction);
}

// Called repeatedly when this Command is scheduled to run
void RotateHopper::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool RotateHopper::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RotateHopper::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateHopper::Interrupted() {
}
