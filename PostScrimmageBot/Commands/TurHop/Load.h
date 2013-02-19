#ifndef LOAD_H
#define LOAD_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author zeitgeist
 */
class Load: public CommandBase {
public:
	Load();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
