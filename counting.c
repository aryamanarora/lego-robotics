task main()
{
	for (int i = 0; i < 180; i++) {
		if (i % 4 == 0) {
			nxtDisplayTextLine(1, "woah");
		}
		if (i % 4 == 2) {
			nxtDisplayClearTextLine(1);
		}
		drawLine(20, 20, 100, i);
		wait1Msec(100);
	}
}
