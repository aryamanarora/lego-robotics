task main()
{
	int x = 1;
	nxtDisplayTextLine(1, "x = %d", x);
	x++;
	nxtDisplayTextLine(2, "x = %5d", x);
	x++;
	nxtDisplayTextLine(x, "x = %-5d", x);
	x++;
	nxtDisplayTextLine(x, "x = %d", x+100);
	x++;
	nxtDisplayTextLine(x, "x = %d", x);
	wait1Msec(random(5000));
}
