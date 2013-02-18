#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author zeitgeist
 */
class Shooter: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar *shooterMotor;
	DoubleSolenoid *feeder;
	
	bool firing;
public:
	Shooter();
	void InitDefaultCommand();
	void SetShooterToggle();
	void TurnOffShooter();
	void FeederToggle();
};

#endif