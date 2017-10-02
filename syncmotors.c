void pivot_turn(float degrees);
void swing_turn(float degrees);
void forward(float revolutions);

task main() {
	nSyncedMotors = synchBC;
	nSyncedTurnRatio = 100;
	for (int i = 0; i < 12; i++) {
		if (i % 2 == 0) {
			forward(5.5);
		}
		else {
			forward(4.5);
		}
		if (i == 10) {
			swing_turn(90.0);
		}
		else {
			pivot_turn(90.0);
		}
	}
	nSyncedMotors = synchNone;
}

void pivot_turn(float degrees) {
	nSyncedTurnRatio = -100;
	if (degrees > 0) {
		motor[motorB] = 20;
	}
	else {
		motor[motorB] = -20;
	}
	wait1Msec((fabs(degrees)/360.0) * 4250.0);
	nSyncedTurnRatio = 100;
	motor[motorB] = 0;
}

void swing_turn(float degrees) {
	nSyncedMotors = synchNone;
	if (degrees > 0) {
		motor[motorB] = 20;
	}
	else {
		motor[motorB] = -20;
	}
	wait1Msec((fabs(degrees)/360.0) * 7500.0);
	nSyncedMotors = synchBC;
	nSyncedTurnRatio = 100;
	motor[motorB] = 0;
}

void forward(float revolutions) {
	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = revolutions * 360;

	nSyncedTurnRatio = 100;
	motor[motorB] = 50;

	while(nMotorRunState[motorB] != runStateIdle) {}
	motor[motorB] = 0;
}
