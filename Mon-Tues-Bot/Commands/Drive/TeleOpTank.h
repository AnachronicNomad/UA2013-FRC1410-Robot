#ifndef TELEOPTANK_H
#define TELEOPTANK_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author zeitgeist
 */
class TeleOpTank: public CommandBase {
public:
	TeleOpTank();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
