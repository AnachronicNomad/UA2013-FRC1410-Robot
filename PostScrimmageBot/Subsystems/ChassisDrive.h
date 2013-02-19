#ifndef CHASSISDRIVE_H
#define CHASSISDRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author zeitgeist
 */
class ChassisDrive: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive *drive;
public:
	ChassisDrive();
	void InitDefaultCommand();
	void ArcadeOneStick(Joystick* stick);
	void TankTwoStick(Joystick* stick1, Joystick* stick2);
};

#endif
