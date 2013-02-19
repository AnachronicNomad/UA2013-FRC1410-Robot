#ifndef ALTITUDEDIRCONT_H
#define ALTITUDEDIRCONT_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author zeitgeist
 */
class AltitudeDirCont: public CommandBase {
	bool direction;
public:
	AltitudeDirCont(bool up);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
