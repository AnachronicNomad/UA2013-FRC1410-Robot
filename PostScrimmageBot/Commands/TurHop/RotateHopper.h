#ifndef ROTATEHOPPER_H
#define ROTATEHOPPER_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author zeitgeist
 */
class RotateHopper: public CommandBase {
	bool direction;
public:
	RotateHopper(bool LeftOrRight);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
