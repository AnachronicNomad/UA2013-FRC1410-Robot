#include "Fire.h"

Fire::Fire() {
	// Use requires() here to declare subsystem dependencies
	Requires(shooter);
	SetTimeout(15.0);
}

// Called just before this Command runs the first time
void Fire::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Fire::Execute() {
	shooter->FeederToggle();
}

// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Fire::End() {
	shooter->TurnOffShooter();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted() {
	shooter->TurnOffShooter();
}
