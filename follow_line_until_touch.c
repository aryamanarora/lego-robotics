#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S1,     touch,          sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
// actually 5 sec lol

void set_motors(int b, int c);

task main() {
	int threshold = 48;
	bool good = true;
	while (good) {
		if (SensorValue(light) < threshold) {
			set_motors(5, 20);
		}
		if (SensorValue(light) > threshold) {
			set_motors(20, 5);
		}
		if (SensorValue(touch) == 1) {
			good = false;
		}
	}
}

void set_motors(int b, int c) {
	motor[motorB] = b;
	motor[motorC] = c;
}