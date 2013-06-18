#ifndef TILTTOPOTANGLE_H
#define TILTTOPOTANGLE_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author ProgEnv
 */
class TiltToPotAngle: public CommandBase {
private:
	float desiredVoltage;
	
public:
	TiltToPotAngle(float inputVoltage);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
