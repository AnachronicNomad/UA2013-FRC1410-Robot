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
	
	
	
	int counter;
	double speeds[4];
	//int qwerty []; 
public:
	Shooter();
	void InitDefaultCommand();
	void FiringToggle();
	void TurnOff();
	void ArraySpeedsInit();
};

#endif
