void wait(float seconds)
{
	wait1Msec(1000 * seconds);
}

task main()
{
	int motor_power = 85;
	motor[motorB] = motor_power;
	motor[motorC] = motor_power;

	wait(1);
	motor[motorB] = 0;

	wait(0.5);
	motor[motorB] = motor_power;

	wait(1);


	/*
	 * 20 cm - 0.45 sec
	 * 40 cm - 0.95 sec
	 * 100 cm - 2.2 sec
	 */
}
