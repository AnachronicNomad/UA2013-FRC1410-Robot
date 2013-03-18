#ifndef SINGLEFIRE_H
#define SINGLEFIRE_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author ProgEnv
 */
class SingleFire: public CommandBase {
public:
	SingleFire();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
