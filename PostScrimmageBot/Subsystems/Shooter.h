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
	
	bool firing;
public:
	Shooter();
	void InitDefaultCommand();
	void FiringToggle();
	void TurnOff();
};

#endif
