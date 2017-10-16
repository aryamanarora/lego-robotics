#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     touch,          sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
// 48 threshold

void pivot_turn(float degrees);
void forward(float revolutions);
void forward_cm(float cm);
void set_motors(int b, int c);

task main() {
	int threshold = 48;
	while (true) {
		set_motors(10, 40);
		while (SensorValue(light) > threshold) {
			set_motors(40, 10);
		}
	}
}

void pivot_turn(float degrees) {
	nSyncedMotors = synchBC;
	nSyncedTurnRatio = -100;

	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = 360 * (degrees/180);
	motor[motorB] = (degrees >= 0) ? 10 : -10;

	while(nMotorRunState[motorB] != runStateIdle) {}

	nSyncedMotors = synchNone;
	motor[motorB] = 0;
}

void forward(float revolutions) {
	nSyncedMotors = synchBC;
	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = revolutions * 360;

	nSyncedTurnRatio = 100;
	motor[motorB] = (revolutions > 0) ? 20 : -20;

	while(nMotorRunState[motorB] != runStateIdle) {}
}

void forward_cm(float cm) {
	forward((5 * (cm / 90)) * 100/98);
}

void set_motors(int b, int c) {
	motor[motorB] = b;
	motor[motorC] = c;
}
