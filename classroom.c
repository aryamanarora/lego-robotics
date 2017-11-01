#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S1,     touch,          sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
// 48 threshold

int check_student(void);
void pivot_turn(float degrees);
void forward(float revolutions);
void forward_cm(float cm);
void set_motors(int b, int c);

task main()
{
	int threshold = 48;
	int count = 0;

	// get to the first row
	while (SensorValue(light) <= threshold) {
		set_motors(30, 30);
	}
	set_motors(0, 0);
	pivot_turn(90);

	// check first row
	count = count + check_student();

	forward_cm(30);
	pivot_turn(-90);

	while (SensorValue(light) <= threshold) {
		set_motors(30, 30);
	}
	while (SensorValue(light) >= threshold) {
		set_motors(30, 30);
	}
	while (SensorValue(light) <= threshold) {
		set_motors(30, 30);
	}
	set_motors(0, 0);
	pivot_turn(90);

	count = count + check_student();

	forward_cm(30);
	pivot_turn(-90);

	while (SensorValue(light) <= threshold) {
		set_motors(30, 30);
	}
	while (SensorValue(light) >= threshold) {
		set_motors(30, 30);
	}
	while (SensorValue(light) <= threshold) {
		set_motors(30, 30);
	}
	set_motors(0, 0);
	pivot_turn(90);

	count = count + check_student();

	nxtDisplayBigTextLine(2, "%d", count);
	wait1Msec(60000);
}

int check_student(void) {
	int students = 0;
	int count = 0;
	int threshold = 48;
	int lines = 2;
	while (SensorValue(touch) == 0 && count < lines) {
		set_motors(30, 30);
		if (SensorValue(light) >= threshold && count < lines) {
			count++;
			while (SensorValue(light) >= threshold && count < lines) {
				set_motors(30, 30);
			}
		}
	}
	if (SensorValue(touch) == 1) {
		students++;
	}
	pivot_turn(180);

	lines = 3;
	count = 0;
	while (SensorValue(touch) == 0 && count < lines) {
		set_motors(30, 30);
		if (SensorValue(light) >= threshold && count < lines) {
			count++;
			while (SensorValue(light) >= threshold && count < lines) {
				set_motors(30, 30);
			}
		}
	}
	if (SensorValue(touch) == 1) {
		students++;
	}
	pivot_turn(180);
	return students;
}


void pivot_turn(float degrees) {
	nSyncedMotors = synchBC;
	nSyncedTurnRatio = -100;

	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = 360 * (degrees/180);
	motor[motorB] = (degrees >= 0) ? 30 : -30;

	while(nMotorRunState[motorB] != runStateIdle) {}

	nSyncedMotors = synchNone;
	motor[motorB] = 0;

	wait1Msec(100);
}

void forward(float revolutions) {
	nSyncedMotors = synchBC;
	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = revolutions * 360;

	nSyncedTurnRatio = 100;
	motor[motorB] = (revolutions > 0) ? 30 : -30;

	while(nMotorRunState[motorB] != runStateIdle) {}
	wait1Msec(200);
}

void forward_cm(float cm) {
	forward((5 * (cm / 90)) * 100/98);
}

void set_motors(int b, int c) {
	motor[motorB] = b;
	motor[motorC] = c;
}
