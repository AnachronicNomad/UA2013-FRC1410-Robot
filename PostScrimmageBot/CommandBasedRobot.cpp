#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Autonomous/AutoSeqGroup.h"
#include "Commands/Shooter/KillShooter.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	Command *shooterSafety;
	
	LiveWindow *lw;
	
	virtual void RobotInit() {
		CommandBase::init();
		autonomousCommand = new AutoSeqGroup();
		shooterSafety = new KillShooter();
		lw = LiveWindow::GetInstance();
	}
	
	virtual void AutonomousInit() {
		
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		
		//autonomousCommand->Cancel();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
	virtual void DisabledInit()
	{
		shooterSafety->Start();
		Wait(0.25);
		shooterSafety->Cancel();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

