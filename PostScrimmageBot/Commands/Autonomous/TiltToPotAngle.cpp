#include "TiltToPotAngle.h"

TiltToPotAngle::TiltToPotAngle(float inputVoltage) {
	// Use requires() here to declare subsystem dependencies
	Requires(turhop);
	desiredVoltage = inputVoltage;
}

// Called just before this Command runs the first time
void TiltToPotAngle::Initialize() {
	//SmartDashboard::PutNumber("Tilt Angle", turhop->GetTiltAngle());
}

// Called repeatedly when this Command is scheduled to run
void TiltToPotAngle::Execute() {
	SmartDashboard::PutNumber("Tilt Angle", turhop->GetTiltAngle());
	SmartDashboard::PutNumber("Potentiometer", turhop->GetPotAngle());
	if(turhop->GetPotAngle() > desiredVoltage)
			{turhop->AltitudeControl(-0.85);}
		else if(turhop->GetPotAngle() < desiredVoltage)
			{turhop->AltitudeControl(0.85);}
}

// Make this return true when this Command no longer needs to run execute()
bool TiltToPotAngle::IsFinished() {
	return ((turhop->GetPotAngle() > desiredVoltage - 0.006) && (turhop->GetPotAngle() < desiredVoltage + 0.006));
}

// Called once after isFinished returns true
void TiltToPotAngle::End() {
	turhop->AltitudeControl(0.0);
	SmartDashboard::PutNumber("Tilt Angle", turhop->GetTiltAngle());
	SmartDashboard::PutNumber("Potentiometer", turhop->GetPotAngle());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TiltToPotAngle::Interrupted() {
	turhop->AltitudeControl(0.0);
	SmartDashboard::PutNumber("Tilt Angle", turhop->GetTiltAngle());
	SmartDashboard::PutNumber("Potentiometer", turhop->GetPotAngle());
}
