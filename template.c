void pivot_turn(float degrees) {
	nSyncedMotors = synchBC;
	nSyncedTurnRatio = -100;

	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = 360 * (degrees/180);
	motor[motorB] = (degrees >= 0) ? 30 : -30;

	while(nMotorRunState[motorB] != runStateIdle) {}

	nSyncedMotors = synchNone;
	motor[motorB] = 0;
}

void swing_turn(float degrees) {
	nSyncedMotors = synchNone;

	if (degrees >= 0) {
		nMotorEncoder[motorB] = 0;
		nMotorEncoderTarget[motorB] = 2 * 360 * (degrees/180);

		motor[motorB] = 30;
		while(nMotorRunState[motorB] != runStateIdle) {}

		motor[motorB] = 0;
	}
	else {
		nMotorEncoder[motorC] = 0;
		nMotorEncoderTarget[motorC] = 2 * 360 * (degrees/180);

		motor[motorC] = 10;
		while(nMotorRunState[motorC] != runStateIdle) {}

		motor[motorC] = 0;
	}
}

void forward(float revolutions) {
	nSyncedMotors = synchBC;
	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = revolutions * 360;

	nSyncedTurnRatio = 100;
	motor[motorB] = (revolutions > 0) ? 50 : -50;

	while(nMotorRunState[motorB] != runStateIdle) {}
}

void forward_cm(float cm) {
	forward((5 * (cm / 90)) * 100/98);
}

task main()
{
	forward_cm(100);
}