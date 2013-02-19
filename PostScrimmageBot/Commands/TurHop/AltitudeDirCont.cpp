#include "AltitudeDirCont.h"

AltitudeDirCont::AltitudeDirCont(bool up) {
	// Use requires() here to declare subsystem dependencies
	Requires(turhop);
	direction = up;
}

// Called just before this Command runs the first time
void AltitudeDirCont::Initialize() {
	if(direction)
	{turhop->AltitudeControl(0.9);}
	else
	{turhop->AltitudeControl(-0.9);}
}

// Called repeatedly when this Command is scheduled to run
void AltitudeDirCont::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool AltitudeDirCont::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AltitudeDirCont::End() {
	turhop->AltitudeControl(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AltitudeDirCont::Interrupted() {
	turhop->AltitudeControl(0.0);
}
