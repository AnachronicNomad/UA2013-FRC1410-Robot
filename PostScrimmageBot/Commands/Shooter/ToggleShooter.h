#ifndef TOGGLESHOOTER_H
#define TOGGLESHOOTER_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author zeitgeist
 */
class ToggleShooter: public CommandBase {
public:
	ToggleShooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
