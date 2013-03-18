#include "TiltToAngle.h"

TiltToAngle::TiltToAngle(float inputAngle) {
	// Use requires() here to declare subsystem dependencies
	Requires(turhop);
	desiredAngle = inputAngle;
}

// Called just before this Command runs the first time
void TiltToAngle::Initialize() {
	if(turhop->GetTiltAngle() > desiredAngle)
	{turhop->AltitudeControl(-0.9);}
	else
	{turhop->AltitudeControl(0.9);}
}

// Called repeatedly when this Command is scheduled to run
void TiltToAngle::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool TiltToAngle::IsFinished() {
	return (turhop->GetTiltAngle() > desiredAngle - 1) && (turhop->GetTiltAngle() < desiredAngle + 1);
}

// Called once after isFinished returns true
void TiltToAngle::End() {
	turhop->AltitudeControl(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TiltToAngle::Interrupted() {
	turhop->AltitudeControl(0.9);
}
