#include "AutoSeqGroup.h"
#include "../TurHop/SingleFire.h"
#include "../Shooter/ToggleShooter.h"
#include "../Shooter/KillShooter.h"
#include "TiltToAngle.h"
#include "TiltToPotAngle.h"
#include "../WaitCom.h"

AutoSeqGroup::AutoSeqGroup() {
        // Add Commands here:
        // e.g. AddSequential(new Command1());
        //      AddSequential(new Command2());
        // these will run in order.

        // To run multiple commands at the same time,
        // use AddParallel()
        // e.g. AddParallel(new Command1());
        //      AddSequential(new Command2());
        // Command1 and Command2 will run in parallel.

        // A command group will require all of the subsystems that each member
        // would req  uire.
        // e.g. if Command1 requires chassis, and Command2 requires arm,
        // a CommandGroup containing them would require both the chassis and the
        // arm.
	//AddSequential(new TiltToAngle(25.5));
	AddSequential(new TiltToPotAngle(2.598));
	
	AddSequential(new ToggleShooter());
	AddSequential(new ToggleShooter());
	
	AddSequential(new WaitCom());
	AddSequential(new SingleFire());
	AddSequential(new SingleFire());
	AddSequential(new SingleFire());
	AddSequential(new SingleFire());//4

	AddSequential(new KillShooter());

}
