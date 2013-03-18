#ifndef DROPRAMP_H
#define DROPRAMP_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author ProgEnv
 */
class DropRamp: public CommandBase {
public:
	DropRamp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
