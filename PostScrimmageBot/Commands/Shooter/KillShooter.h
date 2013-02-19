#ifndef KILLSHOOTER_H
#define KILLSHOOTER_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author zeitgeist
 */
class KillShooter: public CommandBase {
public:
	KillShooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
