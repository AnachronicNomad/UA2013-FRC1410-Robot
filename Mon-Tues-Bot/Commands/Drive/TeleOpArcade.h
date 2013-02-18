#ifndef TELEOPARCADE_H
#define TELEOPARCADE_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author zeitgeist
 */
class TeleOpArcade: public CommandBase {
public:
	TeleOpArcade();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
