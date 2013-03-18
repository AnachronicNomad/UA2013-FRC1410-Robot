#ifndef TURRETHOPPER_H
#define TURRETHOPPER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author zeitgeist
 */
class TurretHopper: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar *altitude;
	
	DoubleSolenoid *feeder;
	
	Servo* hopFeedb1;
	Servo* hopFeedb2;
	Servo* hopFeedFront;
	
	Servo* hopRamp;
	
	bool hopLoadOn;
	
	Compressor *comp;
	
	ADXL345_I2C *accel;
	double acceleration;
public:
	TurretHopper();
	void InitDefaultCommand();
	void AltitudeControl(double speed);
	void FeederToggle();
	void HopFeedToggle();
	void SetFiringOff();
	double GetTiltAngle();
};

#endif
