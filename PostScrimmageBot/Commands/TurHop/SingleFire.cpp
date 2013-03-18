#include "SingleFire.h"

SingleFire::SingleFire() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void SingleFire::Initialize() {
	Wait(0.25);
		turhop->HopFeedToggle();
		Wait(0.25);
		turhop->FeederToggle();
		turhop->HopFeedToggle();
}

// Called repeatedly when this Command is scheduled to run
void SingleFire::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool SingleFire::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SingleFire::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SingleFire::Interrupted() {
}
