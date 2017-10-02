task main()
{
	int i = 1;
	while (i <= 64) {
		nxtDisplayTextLine(2, "%d", i);
		i = i * 2;
		wait1Msec(500);
	}

	i = 0;
	while (true) {
		nxtDisplayTextLine(2, "%d", i * i);
		i++;
		wait1Msec(500);
	}
}
