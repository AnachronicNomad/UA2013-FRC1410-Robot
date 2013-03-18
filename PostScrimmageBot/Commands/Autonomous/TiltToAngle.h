#ifndef TILTTOANGLE_H
#define TILTTOANGLE_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author ProgEnv
 */
class TiltToAngle: public CommandBase {
private:
	float desiredAngle;
	
public:
	TiltToAngle(float inputAngle);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
