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
	Jaguar *shooterFrontMotor;
	Jaguar *shooterBackMotor;	
	
	int counter;
	double speedsFront[6];
	double speedsBack[6];
	
public:
	Shooter();
	void InitDefaultCommand();
	void FiringToggle();
	void TurnOff();
	void ArraySpeedsInit();
	void SetShooterSpeed(float speed);
};

#endif
