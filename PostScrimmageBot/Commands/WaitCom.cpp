#include "WaitCom.h"

WaitCom::WaitCom() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void WaitCom::Initialize() {
	Wait(2.5);
}

// Called repeatedly when this Command is scheduled to run
void WaitCom::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool WaitCom::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void WaitCom::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitCom::Interrupted() {
}
