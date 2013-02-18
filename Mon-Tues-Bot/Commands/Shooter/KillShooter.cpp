#include "KillShooter.h"

KillShooter::KillShooter() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooter);
}

// Called just before this Command runs the first time
void KillShooter::Initialize() {
	shooter->TurnOffShooter();
}

// Called repeatedly when this Command is scheduled to run
void KillShooter::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool KillShooter::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void KillShooter::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KillShooter::Interrupted() {
}
