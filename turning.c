const int MOTOR_POWER = 85;

void wait(float seconds);
void stop_motors();
void turn(float degrees);
void forward(float meters);

task main() {
	forward(0.5);
	turn(90);
	forward(0.5);
	turn(90);
	forward(0.5);
	turn(90);
	forward(0.5);
	turn(90);
	// forward(0.5);
}

void wait(float seconds) {
	wait1Msec(1000 * seconds);
}

void stop_motors() {
	motor[motorB] = 0;
	motor[motorC] = 0;
}

void turn(float degrees) {
	if (degrees < 0.0) {
		motor[motorC] = 50;
	}
	else {
		motor[motorB] = 55; // motor B is weaker...
	}
	wait(fabs(degrees)/130.0);
	stop_motors();
}

void forward(float meters) {
	motor[motorC] = MOTOR_POWER;
	motor[motorB] = MOTOR_POWER;
	wait(2.2 * meters);
	stop_motors();
}
