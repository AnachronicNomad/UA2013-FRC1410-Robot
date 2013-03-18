#include "AutoSeqGroup.h"
#include "../TurHop/DropRamp.h"
#include "../TurHop/SingleFire.h"
#include "../Shooter/ToggleShooter.h"
#include "../Shooter/KillShooter.h"
#include "TiltToAngle.h"

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
        // would require.
        // e.g. if Command1 requires chassis, and Command2 requires arm,
        // a CommandGroup containing them would require both the chassis and the
        // arm.
	
	AddParallel(new DropRamp());
	AddParallel(new TiltToAngle(SmartDashboard::GetNumber("Desired Auto Angle")));
	AddSequential(new ToggleShooter());
	
	AddSequential(new SingleFire());
	AddSequential(new SingleFire());
	AddSequential(new SingleFire());
	AddSequential(new KillShooter());
}
