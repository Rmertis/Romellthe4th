#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>
#include <time.h>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Joystick.h>
#include <CANTalon.h>
//================================================================================
//                         Romell the Forth                                     //
//================================================================================
class Robot: public frc::IterativeRobot {
public:
	void RobotInit() {
		jL = new Joystick(0);

		fL = new CANTalon(15);
		fR = new CANTalon(0);
		bL = new CANTalon(14);
		bR = new CANTalon(1);
	}

	void AutonomousInit() override {

	}

	void AutonomousPeriodic() {

	}

	void TeleopInit() {

	}

	void TeleopPeriodic() {
		if(fabs(jL->GetRawAxis(2)) > 0.1 || fabs(jL->GetRawAxis(5)) > 0.1)

		{
			float left = jL->GetRawAxis(2);
			float right = -1 * jL->GetRawAxis(5);

			fL->Set(left);
			bL->Set(left);

			fR->Set(right);
			bR->Set(right);

		}
	}

	void TestPeriodic() {
		lw->Run();
	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();

	Joystick *jL;
	CANTalon *fL;
	CANTalon *fR;
	CANTalon *bL;
	CANTalon *bR;
};


START_ROBOT_CLASS(Robot)
