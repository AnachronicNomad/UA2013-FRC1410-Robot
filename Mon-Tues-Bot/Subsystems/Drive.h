#ifndef DRIVE_H
#define DRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author zeitgeist
 */
class Drive: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive *drive;
public:
	Drive();
	void InitDefaultCommand();
	void OneStickArcade(Joystick* stick);
	void TwoStickTank(double speed1, double speed2);
};

#endif
