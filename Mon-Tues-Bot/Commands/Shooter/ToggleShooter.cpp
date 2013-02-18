#include "ToggleShooter.h"

ToggleShooter::ToggleShooter() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooter);
}

// Called just before this Command runs the first time
void ToggleShooter::Initialize() {
	shooter->SetShooterToggle();
}

// Called repeatedly when this Command is scheduled to run
void ToggleShooter::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleShooter::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleShooter::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleShooter::Interrupted() {
}
