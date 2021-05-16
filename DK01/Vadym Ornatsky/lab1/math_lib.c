int factorial(int a){
	int result = 1;
		for (int i = 1; i <= a; i++) {
			result = result * i;			
	}
		return result;
}

double modul(double b) {
	double result = 0;
	if (b < 0) {
		return (-b);
	}
	return b;
}