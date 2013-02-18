#ifndef TURRETANDHOPPER_H
#define TURRETANDHOPPER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author zeitgeist
 */
class TurretAndHopper: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar *altitude;
	Jaguar *hopperRotat;
	ADXL345_I2C *accel;
public:
	TurretAndHopper();
	void InitDefaultCommand();
	void AltitudeControl(double speed);
	void HopperBumpRotate(double speed);
};

#endif