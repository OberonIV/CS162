int ways_to_top(int n) {
	// YOUR CODE GOES HERE
	if (n == 0){
		return 1;
	}

	if(n < 0){
		return 0;
	}

	return ways_to_top(n - 3) + ways_to_top(n - 2) + ways_to_top(n - 1);
}
