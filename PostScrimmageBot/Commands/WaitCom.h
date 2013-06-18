#ifndef WAITCOM_H
#define WAITCOM_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ProgEnv
 */
class WaitCom: public CommandBase {
public:
	WaitCom();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
