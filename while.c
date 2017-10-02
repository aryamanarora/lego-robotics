bool prime(int num) {
	bool is_prime = true;
	int divisor = 1;
	while (is_prime == true) {
		if (num % divisor == 0) {
			is_prime = false;
		}
		divisor++;
	}
	return is_prime;
}

task main() {
	int counter = 0;
	while (counter < 10000) {
		if (prime(counter) == true) {
			nxtDisplayTextLine(2, "Counter is now:");
			nxtDisplayTextLine(4, "%d", counter);
			wait1Msec(1000);
			counter++;
		}
	}
}
